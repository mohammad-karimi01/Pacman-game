#include "Ghosts.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

Ghosts::Ghosts(GhostsState * S, Color c) : ScaredDuration(sf::seconds(0)), color(c)
{
    current_state = S;
    
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

/*
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
*/

GhostsState * Ghosts::SetTimer(int L, sf::Time & ETime) // L is GameLevel --- Etime is ElapcedTime of Game
{
    sf::Time temp = sf::seconds(ETime.asSeconds() - ScaredDuration.asSeconds());
    
    if (L == 1){
        if (temp >= sf::seconds(0) && temp <= sf::seconds(7) || 
            temp >= sf::seconds(27) && temp <= sf::seconds(34) ||
            temp >= sf::seconds(54) && temp <= sf::seconds(59) ||
            temp >= sf::seconds(79) && temp <= sf::seconds(84) )
            {
                return & wandering; // سرگردان
            }
        else {
            return & chaser; // تعقیب

        }
    }
    else if (L >= 2 && L <= 4){
        if (temp >= sf::seconds(0) && temp <= sf::seconds(7) || 
            temp >= sf::seconds(27) && temp <= sf::seconds(34) ||
            temp >= sf::seconds(54) && temp <= sf::seconds(59) ||
            temp >= sf::seconds(1092) && temp <= sf::seconds(1093.6) )
            {
                return & wandering; // سرگردان
            }
        else {
            return & chaser ; // تعقیب

        }
    }
    else if ( L >= 5){
        if (temp >= sf::seconds(0) && temp <= sf::seconds(5) || 
            temp >= sf::seconds(25) && temp <= sf::seconds(30) ||
            temp >= sf::seconds(50) && temp <= sf::seconds(55) ||
            temp >= sf::seconds(1092) && temp <= sf::seconds(1093.6) )
            {
                return & wandering; // سرگردان
            }
        else {
            return & chaser; // تعقیب

        }
    }
    else{
        throw invalid_argument
        ("Error: The number of GameLeve in function SetTimer of class Ghosts is invalid");
    }
}// End function SetTimer

void Ghosts::Change_CurrentState(int L, sf::Time & ET )
{
    current_state = SetTimer(L, ET);
}// End function Change_CurrentState


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