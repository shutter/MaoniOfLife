/*
 * VMMLAB GameOfLife
 */

#include <GL/glew.h>
#include <Maoni.hpp>
#include "exercise.hpp"

ENUM(Select,
		(GameOfLife)
		(Simple_1D_CA)
		(Custom_CA)
)
;
RENDER_ALGORITHM(MaoniOfLife,
		(Select, select, Select::GameOfLife)
		(int, rule, 100)
)
{
	ScopedEnable depth_test_lock(GL_DEPTH_TEST);

	size_t width = 400;
	size_t height = 400;

	static graphics_lab::exercise e(width, height);

	switch (select)
	{
	case Select::GameOfLife:
		e.set_ruleset(0);
		break;
	case Select::Simple_1D_CA:
		e.set_ruleset(1);
		break;
	case Select::Custom_CA:
		e.set_ruleset(2);
		break;
	}
	e.set_rule(rule);
	e.step();
	e.draw();
}
