#include "Ghosts.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

Ghosts::Ghosts( int c) : 
ScaredDuration(sf::seconds(0)),
color(c), 
current_state(&wandering)
{
    float Size = static_cast<float>(Cell_Size);
    if (c == 0){
        Pos_X = 10 * Size ;
        Pos_Y = 7 * Size;
        Direction = 1;
    }
    else if (c == 1){
        Pos_X = 9 * Size;
        Pos_Y = 9 * Size;
        Direction = 1;
    }
    else if (c == 2){
        Pos_X = 10 * Size;
        Pos_Y = 9 * Size;
        Direction = 2;
    }
    else if (c == 3){
        Pos_X = 11 * Size;
        Pos_Y = 9 * Size;
        Direction = 3;
    }
    else{
        throw invalid_argument("Error: invalid start position of Ghosts in constructors ghosts");
    }
    Set_Animation();
}

/*
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

void Ghosts::Set_Animation()
{
    FramNum = 2; // number of frame in Image Pacman
    TimeAnime = .5; // Animation durition
    if (!GhostsTexture.loadFromFile("C:/Users/K2/Desktop/Pacman-game/Ghosts32.png")){
        throw runtime_error("Ghosts Image can not load");
    }
    GhostsSprite.setTexture(GhostsTexture);

}// End function Set_Sprite

void Ghosts::Drow(sf::RenderWindow & window, sf::Time & ElapcedTime)
{
    int Size = static_cast<int>(Cell_Size); // this is Cell Size and size of all Ellement
    float TimeAsSecond = ElapcedTime.asSeconds();
    int AnimFram = static_cast<int>((TimeAsSecond / TimeAnime) * FramNum ) % FramNum ;
    GhostsSprite.setTextureRect(sf::IntRect((AnimFram * Size) + (Direction * Size * 2), color * Size , Size, Size));
    GhostsSprite.setPosition(Pos_X, Pos_Y);
    window.draw(GhostsSprite);
  //  cout << "Hello" << endl;
    
}// End function Drow

/*
این تابع برخورد پک من با روح هارا بررسی میکند
*/
sf::Sprite &Ghosts::GetSprit()
{
    return GhostsSprite;
}