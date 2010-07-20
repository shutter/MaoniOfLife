#include "custom_ca.hpp"

namespace graphics_lab
{


custom_ca::custom_ca( cellular_automaton< simple_cell >& ca )
    : ca_ruleset( ca )
{}



void
custom_ca::step()
{
    // write code here to implement a ca ruleset of your choosing. 
    // refer to game of life and/or simple_1d_ca to get a handle on things.

    // social structures: peer pressure and revolution

    std::vector< simple_cell* > neighbors;
    
    const size_t width  = _ca.get_width();
    const size_t height = _ca.get_height();
    
    for( size_t x = 0; x < width; ++x )
    {
        for( size_t y = 0; y < height; ++y )
        {
            simple_cell& in_cell       = _ca.get_cell( x, y );
            _ca.get_moore_neighborhood( x, y, neighbors );
            
            int numberofneighbors = 0;
            for( size_t i = 0; i < neighbors.size(); ++i ){
               numberofneighbors += neighbors[i] -> is_alive();
            }
            
            bool alive = in_cell.is_alive();
            
            // a cell switches to the opinion of the majority due to peer pressure
            if(alive == false && numberofneighbors > 4) alive = true;
            if(alive == true && numberofneighbors < 4) alive = false;
            // if all the neighbors get same state a revolutionizer has to be born!
            if(numberofneighbors == 8 ) alive = false;
            if(numberofneighbors == 0 ) alive = true;
            
            simple_cell& out_cell   = _ca_tmp.get_cell( x, y );
            
            out_cell.update( alive );
            
        }
    }
    _ca.swap( _ca_tmp );
    //_ca.randomize();
}


void
custom_ca::reset()
{
    _ca.randomize();
}


} // namespace graphics_lab

