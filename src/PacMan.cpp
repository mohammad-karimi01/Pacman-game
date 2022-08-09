#include "PacMan.hpp"

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cmath>
#define POS_X 10 // موقعیت پیش فرض برای محل ایجاد پک من
#define POS_Y 10

using namespace std;

 
 /*

PacMan::PacMan(): Score(0)
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
*/

void PacMan::Set_X(float x)
{

}
void PacMan::Set_Y(float y)
{

}

void PacMan::Set_Speed(int level)
{
    float MaxSpeed = static_cast<float>(MAX_SPEED);
    
    if (level >= 1 && level <= 4){
        CurrentSpeed = static_cast<float>(MaxSpeed) * (80/100); 
    }
    else if (level >= 5 && level <= 20){
        CurrentSpeed = static_cast<float>(MaxSpeed) * (90/100); 
    }
    else if (level >= 21 && level <= 32){
        CurrentSpeed = static_cast<float>(MaxSpeed) ; 
    }
    else if (level >= 33){
        CurrentSpeed = static_cast<float>(MaxSpeed) * (90/100); 
    }
    else{
        throw out_of_range("Error: The value of Levels game out of range(Not be negatives number)");
    }
}//End function Set_Level

/*
این تابع با استفاده از توابع تعریف شده در هدر 
snacks.hpp && .cpp
اقدام به محاسبه ی امتیاز پک من در حین بازی میکند
*/
void PacMan::set_score(SnackType type, int num)
{
    Score += GetScores_Snacks(type, num); // this function define in header snakc.hpp
}// End function SetScore


void PacMan::Destroy()
{
    Life--;
    if (Life == 0)
    {
        cout << "GAME OVER !" << endl;
    }

}// End function Destroy

void PacMan::Drow(sf::RenderWindow &)
{

}// End function Drow

bool PacMan::collison
(const std::array<std::array<Cell,Cell_Height>, Cell_Weight> & CurrentMap, Directions D)
{
    float tempx = Pos_X / static_cast<float>(Cell_Size);
    float tempy = Pos_Y / static_cast<float>(Cell_Size);
    int x, y;
    if (D == Right){
        x = static_cast<int>(ceil(tempx));
        y = static_cast<int>(tempy);
        if (CurrentMap[x+1][y] == Cell::Wall){
            Pos_X = (float)x;
            // Pos_Y not change
            return true;
        }
        
    }
    else if (D == Up){
        x = static_cast<int>(tempx);
        y = static_cast<int>(floor(tempy));
        if (CurrentMap[x][y-1] == Cell::Wall){
            //Pos_X not change
             Pos_Y = static_cast<float>(y);
            return true;
        }
    }
    else if (D == Left){
        x = static_cast<int>(floor(tempx));
        y = static_cast<int>(tempy);
        if (CurrentMap[x-1][y] == Cell::Wall){
            Pos_X = (float)x;
            // Pos_Y not change
            return true;
        }
    }
    else if (D == Down){
        x = static_cast<int>(tempx);
        y = static_cast<int>(ceil(tempy));
        if (CurrentMap[x][y+1] == Cell::Wall){
            //Pos_X not change
             Pos_Y = static_cast<float>(y);
            return true;
        }
    }
    return false;
}// End function Collison
void PacMan::Update(const std::array<std::array<Cell,Cell_Height>, Cell_Weight> & CurrentMap)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
        if (collison(CurrentMap, Directions::Right ))
            direction = Stop;
        else
            direction = Right; 
	}
	else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (collison(CurrentMap, Directions::Up))
		    direction = Stop;
        else
            direction = Up;
	}
	else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (collison(CurrentMap, Directions::Left))
		    direction = Stop;
        else
            direction = Left;
	}
	else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (collison(CurrentMap, Directions::Down))
		    direction = Stop;
        else
            direction = Down;
	}
    else{
        if (collison(CurrentMap, direction))
		    direction = Stop;
        else
            direction = direction;
    }
    
}// End function Update

void PacMan::Move(int l)
{
    Set_Speed(l); // l is level Game
    if (direction == Right){
        Pos_X += CurrentSpeed;
    }
    else if (direction == Up){
        Pos_Y -= CurrentSpeed;
    }
    else if (direction == Left){
        Pos_X -= CurrentSpeed;
    }
    else if (direction == Down){
        Pos_Y += CurrentSpeed;
    }
    /*
    else if (direction == Stop){
        Pos_X and Pos_Y   Not Changel
    }
    see function Collison
    */
}