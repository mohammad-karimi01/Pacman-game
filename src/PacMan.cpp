#include "PacMan.hpp"
#include "TypesOfCollisions.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cmath>
#define POS_X 10 // موقعیت پیش فرض برای محل ایجاد پک من
#define POS_Y 10

using namespace std;

 
PacMan::PacMan(): Score(0),  
EatPowerPellet(false), 
Die(false)
{
	SetStartPos();
    Set_Animation(); // Set Informations animation of pacman
    set_HighScore();
    Life = 4; 
    CurrentSpeed = 2;
    direction = Right;
    Key = Right;
    //cout << "Pos_X : " << Pos_X << "    Pos_Y :" << Pos_Y << endl;
}

PacMan::~PacMan()
{
    cout << "Distructor...." << endl;
}

// when pacman is start game or die by ghosts this function reset the pacman position
void PacMan::SetStartPos()
{
	Pos_X = Pos_X = static_cast<float>(PacManStartGame_X * Cell_Size);
	Pos_Y = static_cast<float>(PacManStartGame_Y * Cell_Size);
}

void PacMan::Set_EatPowerPellet(bool E)
{
	EatPowerPellet = E;
}
bool PacMan::Get_EatPowerPellet()
{
	return EatPowerPellet;
}

// this function use in function hunt in main file
sf::Sprite &PacMan::GetSprite()
{
	return PacmanSprite;
}
// this function update score when pacman eat pellet or power pellet
bool PacMan::SetScore(std::array<std::array<Cell,Cell_Height>, Cell_Weight> & Gmap)
{
	bool output = false;
	if (TypesOfCollisions(true, false, Pos_X, Pos_Y, Gmap)){
		Score += 10; 
		//output = false;
	}
	else if (TypesOfCollisions(false, true, Pos_X, Pos_Y, Gmap)){
		Score += 50;
		EatPowerPellet = true; // برای تغییر حالت ارواح به ترسیده
		output = true;
	}
	return output;
}

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

// this function get game level and update pacman speed
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

void PacMan::Destroy()
{
	Die = true;
    Life--;
    if (Life == 0)
    {
        cout << "GAME OVER !" << endl;
    }
}// End function Destroy


void PacMan::Set_Animation()
{
    FramNum = 6; // number of frame in Image Pacman
    TimeAnime = .5; // Animation durition
    if (!PacmanTexture.loadFromFile("C:/Users/K2/Desktop/Pacman-game/Pacman32.png")){
        throw runtime_error("PacMan Image can not load");
    }
    PacmanSprite.setTexture(PacmanTexture);

}// End function Set_Sprite
void PacMan::Drow(sf::RenderWindow & window ,  sf::Time & ElapcedTime , sf::Clock & ck)
{
    int Size = static_cast<int>(Cell_Size); // this is Cell Size and size of all Ellement
	float TimeAsSecond = ElapcedTime.asSeconds();
	int AnimFram;
    if (Die){
		// framenum = 11
		// timeanime = 1.2
		AnimFram = static_cast<int>((TimeAsSecond / 1.2) * 11) % 11 ;
		PacmanSprite.setTextureRect(sf::IntRect(AnimFram * Size, 4 * Size , Size, Size));

	}
	else{
		
		AnimFram = static_cast<int>((TimeAsSecond / TimeAnime) * FramNum) % FramNum ;
		PacmanSprite.setTextureRect(sf::IntRect(AnimFram * Size, direction * Size , Size, Size));
	}
		PacmanSprite.setPosition(Pos_X, Pos_Y);

		window.draw(PacmanSprite);
	   
   // cout << Pos_X << "\t" << Pos_Y << endl;
}

void PacMan::update
(const int level,std::array<std::array<Cell,Cell_Height>, Cell_Weight> & i_map)
{
	
	std::array<bool, 4> walls{};
	walls[0] = TypesOfCollisions(0, 0, CurrentSpeed + Pos_X, Pos_Y, i_map);
	walls[1] = TypesOfCollisions(0, 0, Pos_X, Pos_Y - CurrentSpeed, i_map);
	walls[2] = TypesOfCollisions(0, 0, Pos_X - CurrentSpeed, Pos_Y, i_map);
	walls[3] = TypesOfCollisions(0, 0, Pos_X, CurrentSpeed + Pos_Y, i_map);

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (0 == walls[0]) //You can't turn in this direction if there's a wall there.
		{
			direction = 0;
		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (0 == walls[1])
		{
			direction = 1;
		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (0 == walls[2])
		{
			direction = 2;
		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (0 == walls[3])
		{
			direction = 3;
		}
	}
	
    
	if (0 == walls[direction])
	{
		switch (direction)
		{
			case 0:
			{
				
				Pos_X += CurrentSpeed;

				break;
			}
			case 1:
			{
				Pos_Y -= CurrentSpeed;

				break;
			}
			case 2:
			{
				Pos_X -= CurrentSpeed;

				break;
			}
			case 3:
			{
				Pos_Y += CurrentSpeed;
			}
		}
	}
// تنظیم حرکت در تونل ها
	if (-Cell_Size >= Pos_X) 
	{
		Pos_X = Cell_Size * Cell_Weight - CurrentSpeed;
	}
	else if (Cell_Size * Cell_Weight <= Pos_X)
	{
		Pos_X = CurrentSpeed - Cell_Size;
	}

	
}// End function update ----------

// Reset the data of pacman after its death
void PacMan::Reset()
{
	SetStartPos();
	Die = false;
	direction = 0; // is Right
	EatPowerPellet = false;

}