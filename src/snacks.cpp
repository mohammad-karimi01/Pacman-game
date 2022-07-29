#include "snacks.hpp"
#include <iostream>

using namespace std;

snacks::snacks(snacks_state * s, int x, int y)
{
    ChangeState(s);
    set_xy(x, y);
}
void snacks::set_xy(int x, int y) 
{
    this->X = x;
    this->Y = y;
}
int snacks::get_x() const
{
    return X;
}
int snacks::get_y() const
{
    return Y;
}

void snacks::ChangeState(snacks_state * NewState)
{
    current_state = NewState;
}

void snacks::print()
{
    cout << ".................................................." << endl;
    cout << "State: " ;
    current_state->print();
    cout << X << " " << Y << endl;
}