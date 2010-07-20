#include "exercise.hpp"
#include <GL/glew.h>
#include <boost/la/all.hpp>
#include <iostream>

using namespace boost::la;
namespace graphics_lab
{

exercise::exercise(size_t width, size_t height) :
	_ca(128, 128), _run(true), _step(false), _draw_mode(0), _ca_ruleset(0),
			_game_of_life(0), _simple_1d_ca(0), _ca_update_rate(1.0 / 24.0),
			ruleset_(999)
{
	_setup_ca();
}

exercise::~exercise()
{
}

void exercise::draw()
{
	_draw_background();
	_draw_points();
}

void exercise::_draw_points()
{
	Vec2 base(-1.0f, -1.0f);
	Vec2 size(2.0f, 2.0f);

	const size_t width = _ca.get_width();
	const size_t height = _ca.get_height();

	Vec2 cell_size = size;
	cell_size | X /= width;
	cell_size | Y /= height;

	Vec2 cell_base = base;
	cell_base | Y += size | Y;

	glPointSize(3.0f);
	glBegin(GL_POINTS);

	glColor3f(1.0f, 1.0f, 1.0f);

	for (size_t y = 0; y < height; ++y)
	{
		for (size_t x = 0; x < width; ++x)
		{
			const simple_cell& cell = _ca.get_cell(x, y);

			if (cell.is_alive())
			{
				if (_draw_mode != 0)
				{
					const float& age = 1.0f - cell.get_age() * 0.5f;
					glColor3f(age, age, age);
				}

				glVertex3f(cell_base | X, cell_base | Y, 0.0f);
			}
			cell_base | X += cell_size | X;
		}
		cell_base | X = base | X;
		cell_base | Y -= cell_size | Y;
	}

	glEnd();

}

void exercise::_setup_ca()
{
	_game_of_life = new game_of_life(_ca);
	_simple_1d_ca = new simple_1d_ca(_ca);
	_custom_ca = new custom_ca(_ca);
	_ca_ruleset = _game_of_life;
}

void exercise::step()
{
	assert(_ca_ruleset);
	_ca_ruleset->step();
}

void exercise::_draw_background()
{
	glBegin(GL_QUADS);
	{
		glColor3f(0.24, 0.55f, 0.75);
		glVertex3f(-1.1f, -1.1f, 0.0f);
		glColor3f(0.24, 0.24, 0.75);
		glVertex3f(-1.1f, 1.1f, 0.0f);
		glColor3f(0.55f, 0.24, 0.75);
		glVertex3f(1.1f, 1.1f, 0.0f);
		glColor3f(0.55f, 0.55f, 0.75);
		glVertex3f(1.1f, -1.1f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	glEnd();
}

void exercise::set_rule(unsigned short rule)
{
	if (rule >= 0 && rule < 256 && rule != _simple_1d_ca->get_rule())
		_simple_1d_ca->set_rule(rule);
}

void exercise::set_ruleset(unsigned short ruleset)
{
	if (ruleset == 0 && ruleset != ruleset_)
	{
		ruleset_ = ruleset;
		_ca_ruleset = _game_of_life;
		std::cout << "set ruleset to game of life" << std::endl;
	}
	else if (ruleset == 1 && ruleset != ruleset_)
	{
		ruleset_ = ruleset;
		_ca_ruleset = _simple_1d_ca;
		std::cout << "set ruleset to simple 1d ca" << std::endl;
	}
	else if (ruleset == 2 && ruleset != ruleset_)
	{
		ruleset_ = ruleset;
		_ca_ruleset = _custom_ca;
		std::cout << "set ruleset to custom ca" << std::endl;
	}
}

} // namespace graphics_lab

