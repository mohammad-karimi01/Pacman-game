#include "PacMan.hpp"
#include <stdexcept>

using namespace std;



PacMan::PacMan()
{
}

PacMan::~PacMan()
{
}

// here set the element "Life" of pacman 
void PacMan::set_life(int l) // life shoud be 1 - 7
{
    if(l < 1 || l > LP){
        throw out_of_range("Error: The number of life`s pac man is out of range...");
    }
    else{
        Life = l;
    }
}//End function*

int PacMan::get_life() const
{
    return Life;
}//End function*

// here set the element "X and Y"  of pacman 
void PacMan::set_xy(int x, int y)
{
    this->X = x;
    this->Y = y;
}// End function*

int PacMan::get_x() const
{
    return X;
}// End function*

int PacMan::get_y() const
{
    return Y;
}// End function*

// here set the element "Score"  of pacman
void PacMan::set_score(llint s )
{
    Score = s;

}// End function*

llint PacMan::grt_scor() const
{
    return Score;
}// End function*