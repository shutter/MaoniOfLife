#ifndef __EXERCISE__SIMPLE_CELL__HPP__
#define __EXERCISE__SIMPLE_CELL__HPP__

namespace graphics_lab
{

class simple_cell
{
public:
    simple_cell();

    const bool is_alive() const;   

    float get_age() const;
    
    void set( const bool is_alive );
    void update( const bool is_alive );   
    
    void randomize( float life_probability = 0.7f );

protected:
    bool    _is_alive;
    float   _age;
    float   _age_diff_per_step;

}; // class simple_cell

} // namespace graphics_lab

#endif

