#include "PacMan.hpp"

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cmath>
#define POS_X 10 // موقعیت پیش فرض برای محل ایجاد پک من
#define POS_Y 10

using namespace std;

 
PacMan::PacMan(): Score(0) 
{
    Set_X();// Set position X of Pacman
    Set_Y(); // Set position Y of Pacman
    Set_Animation(); // Set Informations animation of pacman
    set_HighScore();
    Life = 4; 
    CurrentSpeed = 2;
    direction = Right;
    Key = Right;
    cout << "Pos_X : " << Pos_X << "    Pos_Y :" << Pos_Y << endl;
}

PacMan::~PacMan()
{
    cout << "Distructor...." << endl;
}


void PacMan::Set_X()
{
    Pos_X = static_cast<float>(PacManStartGame_X * Cell_Size);
}
void PacMan::Set_Y()
{
    Pos_Y = static_cast<float>(PacManStartGame_Y * Cell_Size);
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
// void PacMan::set_score(SnackType type, int num)
// {
//     Score += GetScores_Snacks(type, num); // this function define in header snakc.hpp
// }// End function SetScore


void PacMan::Destroy()
{
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
    int mul = static_cast<int>(direction); // for Choice the row of the image Pacman
    if (mul == 5){
        mul = 1;
    }
    // sf::Time dt = ck.restart();
    // ElapcedTime += dt;
    float TimeAsSecond = ElapcedTime.asSeconds();
    int AnimFram = static_cast<int>((TimeAsSecond / TimeAnime) * FramNum) % FramNum ;

    PacmanSprite.setTextureRect(sf::IntRect(AnimFram * Size, mul * Size , Size, Size));

    PacmanSprite.setPosition(Pos_X, Pos_Y);
    
    window.draw(PacmanSprite);
   // cout << Pos_X << "\t" << Pos_Y << endl;
}




bool PacMan::map_collision
(bool i_collect_pellets, bool i_use_door, short i_x, short i_y,std::array<std::array<Cell,Cell_Height>, Cell_Weight> & i_map)
{
	bool output = 0;

	//Getting the exact position.
	float cell_x = i_x / static_cast<float>(Cell_Size);
	float cell_y = i_y / static_cast<float>(Cell_Size);

	//A ghost/Pacman can intersect 4 cells at most.
	for (unsigned char a = 0; a < 4; a++)
	{
		short x = 0;
		short y = 0;

		switch (a)
		{
			case 0: //Top left cell
			{
				x = static_cast<short>(floor(cell_x));
				y = static_cast<short>(floor(cell_y));

				break;
			}
			case 1: //Top right cell
			{
				x = static_cast<short>(ceil(cell_x));
				y = static_cast<short>(floor(cell_y));

				break;
			}
			case 2: //Bottom left cell
			{
				x = static_cast<short>(floor(cell_x));
				y = static_cast<short>(ceil(cell_y));

				break;
			}
			case 3: //Bottom right cell
			{
				x = static_cast<short>(ceil(cell_x));
				y = static_cast<short>(ceil(cell_y));
			}
		}

		//Making sure that the position is inside the map.
		if (0 <= x && 0 <= y && Cell_Height > y && Cell_Weight > x)
		{
			if (0 == i_collect_pellets) //Here we only care about the walls.
			{
				if (Cell::Wall == i_map[x][y])
				{
					output = 1;
				}
				else if (0 == i_use_door && Cell::Door == i_map[x][y])
				{
					output = 1;
				}
			}
			else //Here we only care about the collectables.
			{
				if (Cell::Power_Food == i_map[x][y])
				{
					output = 1;

					i_map[x][y] = Cell::Empty;
				}
				else if (Cell::Food == i_map[x][y])
				{
					i_map[x][y] = Cell::Empty;
				}
			}
		}
	}

	return output;
}



void PacMan::update
(unsigned char i_level,std::array<std::array<Cell,Cell_Height>, Cell_Weight> & i_map)
{
	std::array<bool, 4> walls{};
	walls[0] = map_collision(0, 0, CurrentSpeed + Pos_X, Pos_Y, i_map);
	walls[1] = map_collision(0, 0, Pos_X, Pos_Y - CurrentSpeed, i_map);
	walls[2] = map_collision(0, 0, Pos_X - CurrentSpeed, Pos_Y, i_map);
	walls[3] = map_collision(0, 0, Pos_X, CurrentSpeed + Pos_Y, i_map);

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

	if (-Cell_Size >= Pos_X)
	{
		Pos_X = Cell_Size * Cell_Weight - CurrentSpeed;
	}
	else if (Cell_Size * Cell_Weight <= Pos_X)
	{
		Pos_X = CurrentSpeed - Cell_Size;
	}

	// if (1 == map_collision(1, 0, Pos_X, Pos_Y, i_map)) //When Pacman eats an energizer...
	// {
	// 	//He becomes energized!
	// 	energizer_timer = static_cast<unsigned short>(ENERGIZER_DURATION / pow(2, i_level));
	// }
	// else
	// {
	// 	energizer_timer = std::max(0, energizer_timer - 1);
	// }
}
