#include "simple_cell.hpp"

#include <cstdlib>

namespace graphics_lab
{

simple_cell::simple_cell()
    : _is_alive( true )
    , _age( 1.0f )
    , _age_diff_per_step( 0.025f )
{}


const bool 
simple_cell::is_alive() const
{
    return _is_alive;
}


void
simple_cell::set( const bool is_alive )
{
    _is_alive = is_alive;
    _age = 0.0f;
}

void
simple_cell::update( const bool is_alive )
{
    if ( is_alive == _is_alive )
    {
        if ( is_alive )
        {
            if ( _age < 1.0f )
                _age += _age_diff_per_step;
        }
        else 
        {
            if ( _age > -1.0f )
                _age -= _age_diff_per_step;
        }
    }
    else
    {
        _is_alive   = is_alive;
        _age        = 0.0f;
    }
}


float
simple_cell::get_age() const
{
    return _age;
}


void
simple_cell::randomize( float life_probability )
{
    float r = rand() / (double) RAND_MAX;
    
    if ( r > 1.0f - life_probability )
    {
        _is_alive   = true;
        _age = rand() / (double) RAND_MAX;
    }
    else
    {
        _is_alive = false;
        _age = 0.0f;
    }
}



} // namespace graphics_lab

