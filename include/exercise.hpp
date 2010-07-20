#ifndef __GRAPHICS_LAB__EXERCISE__HPP__
#define __GRAPHICS_LAB__EXERCISE__HPP__

#include "cellular_automaton.hpp"
#include "simple_cell.hpp"

#include "ca_ruleset.hpp"
#include "game_of_life.hpp"
#include "simple_1d_ca.hpp"
#include "custom_ca.hpp"

#include <Maoni/Vector.hpp>

namespace graphics_lab
{

class exercise
{
public:
	typedef cellular_automaton<simple_cell> simple_ca;

	exercise(size_t width, size_t height);
	~exercise();

	virtual void draw();
	virtual void step();

	void print_help();
	void set_rule(unsigned short rule);
	void set_ruleset(unsigned short ruleset);

protected:
	virtual void _draw_background();

	void _setup_ca();
	void _setup_mouse();

	void _draw_quads();
	void _draw_points();
	void
			_draw_cell(const simple_cell& cell, const Vec3& base,
					const Vec3& size);

	cellular_automaton<simple_cell> _ca;

	size_t _draw_mode;
	bool _run;
	bool _step;

	ca_ruleset* _ca_ruleset;

	game_of_life* _game_of_life;
	simple_1d_ca* _simple_1d_ca;
	custom_ca* _custom_ca;

	float _ca_update_rate;
	unsigned short ruleset_;

}; // class exercise

} // namespace graphics_lab

#endif

