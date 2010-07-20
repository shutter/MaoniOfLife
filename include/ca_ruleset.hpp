#ifndef __GRAPHICS_LAB__CA_RULESET__HPP__
#define __GRAPHICS_LAB__CA_RULESET__HPP__

#include "cellular_automaton.hpp"
#include "simple_cell.hpp"

namespace graphics_lab
{

class ca_ruleset
{
public:
    ca_ruleset( cellular_automaton< simple_cell >& ca );
    virtual void step() = 0;
    virtual void reset() = 0;

protected:
    cellular_automaton< simple_cell >&  _ca;
    cellular_automaton< simple_cell >   _ca_tmp;

}; // class ca_ruleset

} // namespace graphics_lab

#endif

