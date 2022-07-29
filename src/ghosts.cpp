#include "ghosts.hpp"
#include <iostream>
using namespace std;

Ghosts::Ghosts(ghosts_state *g, int c)
{
    Change_CurrentState(g);
    set_color(c);
    set_xy(1, 1);
}
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

void Ghosts::set_color(int c )
{
    if (c == 1){
        color = Blinky;
    }
    else if(c == 2){
        color = Pinky;
    }
    else if (c == 3){
        color = Inky;
    }
    else if (c == 4){
        color = Clyde;
    }
    else{
        cerr << "Color is not correct " << endl;
    }
}// End function*

Color Ghosts::get_color()
{
    return color;
}// End function*

void Ghosts::Change_CurrentState(ghosts_state * NewState )
{
    current_state = NewState;
}// End function*


void Ghosts::print()
{
    cout << "Information ghosts........................................" << endl;
    cout << "State: " ;
    current_state->print();
    cout << "Color: " ;
    if (color == 1){
        cout << "Blinky" ;
    } 
    if ( color == 2){
        cout << "Pinky" ;
    }
    if ( color == 3){
        cout << "Inky" ;
    }
    if ( color == 4){
        cout << "Clyde" ;
    }
    cout << endl << "...................................................." << endl;
}
//Blinky = 1 , Pinky, lnky, Clyde