#include "game_of_life.hpp"

namespace graphics_lab
{


game_of_life::game_of_life( cellular_automaton< simple_cell >& ca )
    : ca_ruleset( ca )
{}


void
game_of_life::step()
{
    /*
    Rules:

    Each living cell with one or no neighbors dies, as if by loneliness.
    Each living cell with four or more neighbors dies, as if by overpopulation.
    Each living cell with two or three neighbors survives.

    Each empty/dead cell with three neighbors springs to life.
    */            
    
    std::vector< simple_cell* > neighbors;
    
    const size_t width  = _ca.get_width();
    const size_t height = _ca.get_height();
    
    for( size_t x = 0; x < width; ++x )
    {
        for( size_t y = 0; y < height; ++y )
        {
            simple_cell& in_cell       = _ca.get_cell( x, y );
            _ca.get_moore_neighborhood( x, y, neighbors );
            
            // write code here to evaluate the cell's state as well as its
            // neighborhood and apply the rules for game of life.
            int numberofneighbors = 0;
            for( size_t i = 0; i < neighbors.size(); ++i ){
               numberofneighbors += neighbors[i] -> is_alive();
            }
            
            bool alive = in_cell.is_alive();
            
            // Each living cell with one or no neighbors dies, as if by loneliness.
            if(alive == true && numberofneighbors <= 1) alive = false;
            // Each living cell with four or more neighbors dies, as if by overpopulation.
            if(alive == true && numberofneighbors >= 4 ) alive = false;
            // Each living cell with two or three neighbors survives.
            // no change

            // Each empty/dead cell with three neighbors springs to life.
            if(alive == false &&  numberofneighbors == 3) alive = true;
            
            simple_cell& out_cell   = _ca_tmp.get_cell( x, y );
            
            out_cell.update( alive );
            
        }
    }
    _ca.swap( _ca_tmp );
}



void
game_of_life::reset()
{
    _ca.randomize();
}


} // namespace graphics_lab

