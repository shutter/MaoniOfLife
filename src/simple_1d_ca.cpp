#include "simple_1d_ca.hpp"

#include <cmath>
#include <iostream>
#include <stdlib.h>

namespace graphics_lab
{

simple_1d_ca::simple_1d_ca( cellular_automaton< simple_cell >& ca )
    : ca_ruleset( ca )
    , _current_row( 0 )
{
    set_rule( 110 );
}

void
simple_1d_ca::step()
{
    const size_t width  = _ca.get_width();
    const size_t height = _ca.get_height();
    
    const size_t cur_y = _current_row;
    size_t next_y = _current_row + 1;
    if ( next_y == height )
        next_y = 0;

    const size_t rule = get_rule();

    std::vector< simple_cell* > nbs;
    for( size_t index = 0; index < width; ++index )
    {
        simple_cell& in_cell    = _ca.get_cell( index, cur_y );       
        _ca.get_1d_neighborhood( index, cur_y, 1, nbs );

        // write code here to evaluate the cell and its neighborhood according 
        // to the rule stored in the _rule member variable, and update
        // out_cell with the new state.

        // calculate number of the current pattern. #0 -> 000, #7 -> 111.
        int current_pattern = (nbs[0] -> is_alive())*4 + in_cell.is_alive()*2 + (nbs[1] -> is_alive());

        // find the state of the rule's bit at the position of the current pattern's number.
        bool alive = rule & (int)pow(2, current_pattern);

        //std::cout << rule << " " << (nbs[0] -> is_alive()) << " " <<  in_cell.is_alive() << " " << (nbs[1] -> is_alive()) << " " << current_pattern << " " << alive << "\n";

        simple_cell& out_cell   = _ca.get_cell( index, next_y );
        out_cell.update( alive );
        
    }

    ++_current_row;
    if ( _current_row == height )
    {
        _current_row = 0;
    }
}



void
simple_1d_ca::set_rule( const unsigned short rule )
{
    _rule = rule;   

    std::cout
        << "set 1d ca rule to: "
        << static_cast< size_t >( rule )
        << std::endl;
}


const size_t
simple_1d_ca::get_rule() const
{
    return _rule;
}



void
simple_1d_ca::set_random_rule()
{
    set_rule( rand() >> 2 );
}


void
simple_1d_ca::reset()
{
    cellular_automaton< simple_cell >::iterator
        it      = _ca.begin(),
        it_end  = _ca.end();
    for( ; it != it_end; ++it )
    {
        (*it).set( false );
    }
    
    const size_t width = _ca.get_width();
    _ca.get_cell( width / 2, 0 ).set ( true );
    
    _current_row = 0;
        
}

} // namespace graphics_lab

