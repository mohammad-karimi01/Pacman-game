#include "../header/PacMan.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>
#define POS_X 10 // موقعیت پیش فرض برای محل ایجاد پک من
#define POS_Y 10

using namespace std;

 
 

PacMan::PacMan() 
{
    set_xy(POS_X, POS_Y); //سازنده پیش فرض برای مقدار دهی موقعیت اولیه پک من هنگام تولد برای شرع بازی
    set_HighScore();
    set_score(0);
    Life = 4;
    
}

PacMan::~PacMan()
{
    cout << "Distructor...." << endl;
}

void PacMan::Set_Speed(int level)
{
    float MaxSpeed = static_cast<float>(MAX_SPEED);
    
    if (level >= 1 && level <= 4){
        CurrentSpeed = MaxSpeed * (80/100); 
    }
    else if (level >= 5 && level <= 20){
        CurrentSpeed = MaxSpeed * (90/100); 
    }
    else if (level >= 21 && level <= 32){
        CurrentSpeed = MaxSpeed ; 
    }
    else if (level >= 33){
        CurrentSpeed = MaxSpeed * (90/100); 
    }
    else{
        throw out_of_range("Error: The value of Levels game out of range(Not be negatives number)");
    }
}//End function Set_Level



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

llint PacMan::get_score() const
{
    return Score;
}// End function*

void PacMan::set_HighScore()
{
    ifstream file("HighScore.txt", ios::in | ios::ate);
    if (!file){
        HighScore = 0;
        update_HighScore();
        //throw runtime_error("Error: The file \" HighScore \" could not be opened...");
    }
    else {
        file.seekg(0, ios::beg);
        file >> HighScore;
        if (HighScore < 0)
        {
            throw out_of_range("HighScore is out of range");
        }
    }
    file.close();
}// End function*

llint PacMan::get_HighScore() const
{
    return HighScore;

}// End function*

void PacMan::update_HighScore() 
{
    if ( Score >= HighScore)
    {
        ofstream file("HighScore.txt", ios::out);
        if(!file)
        {
            throw runtime_error("Error: The file \" HighScore \" could not be opened...");
        }
        HighScore = Score;

        file << Score;
    }

}// End function*

void PacMan::Destroy()
{
    Life--;
    if (Life == 0)
    {
        cout << "GAME OVER !" << endl;
    }

}
