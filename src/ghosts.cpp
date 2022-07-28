#include "ghosts.hpp"

using namespace std;


void Ghosts::set_xy(int x, int y)
{
    this->X = x;
    this->Y = y;
}// End function*

int Ghosts::get_x() const
{
    return this->X;
}

int Ghosts::get_y() const
{
    return this->Y;
}// End function*

void Ghosts::set_color(Color c )
{
    color = c;
}// End function*

Color Ghosts::get_color()
{
    return color;
}// End function*

void Ghosts::Change_CurrentState(ghosts_state * NewState )
{
    current_state = NewState;
}// End function*