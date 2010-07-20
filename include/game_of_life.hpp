#ifndef __GRAPHICS_LAB__GAME_OF_LIFE__HPP__
#define __GRAPHICS_LAB__GAME_OF_LIFE__HPP__

#include "ca_ruleset.hpp"

namespace graphics_lab
{

class game_of_life : public ca_ruleset
{
public:
    game_of_life( cellular_automaton< simple_cell >& ca );

    virtual void step();
    virtual void reset();

protected:

}; // class game_of_life

} // namespace graphics_lab

#endif

