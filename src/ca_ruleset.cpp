#include "ca_ruleset.hpp"

namespace graphics_lab
{

ca_ruleset::ca_ruleset( cellular_automaton< simple_cell >& ca )
    : _ca( ca )
    , _ca_tmp( ca )
{}

} // namespace graphics_lab
