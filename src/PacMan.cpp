#include "PacMan.hpp"
#include "TypesOfCollisions.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cmath>
#define POS_X 10 // موقعیت پیش فرض برای محل ایجاد پک من
#define POS_Y 10

using namespace std;

 
PacMan::PacMan():
Life(4), 
Score(0),  
Dead(false),
direction(Right),
ElapcedTime_dead(sf::seconds(0)),
CurrentSpeed(2)
{
	SetStartPos();
    Set_Animation(); 
    set_HighScore();
	SetFont();
}

PacMan::~PacMan()
{
}
float PacMan::Get_PosX() const
{
	return Pos_X;
}
float PacMan::Get_PosY() const
{
	return Pos_Y;
}
// when pacman is start game or die by ghosts this function reset the pacman position
void PacMan::SetStartPos()
{
	Pos_X = static_cast<float>(PacManStartGame_X * Cell_Size);
	Pos_Y = static_cast<float>(PacManStartGame_Y * Cell_Size);
}


void PacMan::Set_Dead()
{
	Dead = true;
}
bool PacMan::Get_Dead()
{
	return Dead;
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
	if (TypesOfCollisions(false ,false ,true, false, Pos_X, Pos_Y, Gmap)){
		Score += 10; 
		//output = false;
	}
	else if (TypesOfCollisions(false ,false ,false, true, Pos_X, Pos_Y, Gmap)){
		Score += 50;
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
/*
// this function get game level and update pacman speed
void PacMan::Set_Speed(int level)
{
    float MaxSpeed = static_cast<float>(MAX_SPEED);
	CurrentSpeed = MaxSpeed;
    
    if (level >= 1 && level <= 4){
        CurrentSpeed = MaxSpeed * (80/100); 
    }
    else if (level >= 5 && level <= 20){
        CurrentSpeed = MaxSpeed * (90/100); 
    }
    else if (level >= 21 && level <= 32){
        CurrentSpeed = MaxSpeed; 
    }
    else if (level >= 33){
        CurrentSpeed = MaxSpeed * (90/100); 
    }
    else{
        throw out_of_range("Error: The value of Levels game out of range(Not be negatives number)");
    }
}////دEnd function Set_Level
*/
void PacMan::Destroy()
{
	Score -= 20;
    SetStartPos();
	direction = Right;
	ElapcedTime_dead = sf::seconds(0);
	Dead = false;
	Life--;
    if (Life == 0)
    {
        cout << "GAME OVER !" << endl;
    }
}// End function Destroy

void func(sf::Font & font, sf::Text & text, float x, float y)
{
	text.setFont(font);
	text.setPosition(sf::Vector2f(x, y));
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(CharSize);
}
void PacMan::SetFont()
{
	float x = float(Cell_Size) * float(Cell_Height);
	if (!font.loadFromFile("C:/Users/K2/Desktop/Pacman-game/times.ttf"))
	{
		throw runtime_error("Error: the font files can not be open");
	}
	func(font, text1, x + float(Cell_Size) * 4, 0 );
	func(font, text2, x + float(Cell_Size) * 8 ,0);
	func(font, ScoreText, x + float(Cell_Size) * 4, CharSize + 5 );
	func(font, HighScoreText, x + float(Cell_Size) * 8, CharSize + 5 );
	text1.setString("SCORE");
	text2.setString("HIGH SCORE");
}//End function SetFont

void PacMan::Set_Animation()
{
    FramNum = 6; // number of frame in Image Pacman
    TimeAnime = .5; // Animation durition
    if (!PacmanTexture.loadFromFile("C:/Users/K2/Desktop/Pacman-game/Pacman32.png")){
        throw runtime_error("PacMan Image can not load");
    }
    PacmanSprite.setTexture(PacmanTexture);

}// End function Set_Sprite
void PacMan::Drow(sf::RenderWindow & window ,  sf::Time & ElapcedTime , sf::Time & dt)
{
    int Size = static_cast<int>(Cell_Size); // this is Cell Size and size of all Ellement
	float TimeAsSecond = ElapcedTime.asSeconds();
	int AnimFram;
    if (Dead)
	{
		// framenum = 11
		// timeanime = 1.2
		ElapcedTime_dead += dt;
		AnimFram = static_cast<int>((ElapcedTime_dead.asSeconds() / 1) * 11) % 11 ;
		PacmanSprite.setTextureRect(sf::IntRect(AnimFram * Size, 4 * Size , Size, Size));
		if (ElapcedTime_dead >= sf::seconds(1))// مدت زمان نمایش مرگ پک من
		{
			Destroy();
			ElapcedTime = sf::seconds(0);
		}

	}
	else{
		
		AnimFram = static_cast<int>((TimeAsSecond / TimeAnime) * FramNum) % FramNum ;
		PacmanSprite.setTextureRect(sf::IntRect(AnimFram * Size, direction * Size , Size, Size));
	}
		PacmanSprite.setPosition(Pos_X, Pos_Y);
		window.draw(PacmanSprite);
}

void PacMan::update
(const int level,std::array<std::array<Cell,Cell_Height>, Cell_Weight> & i_map)
{
	
	std::array<bool, 4> walls{};
	walls[0] = TypesOfCollisions(false ,false ,false, false, CurrentSpeed + Pos_X, Pos_Y, i_map);
	walls[1] = TypesOfCollisions(false ,false ,false, false, Pos_X, Pos_Y - CurrentSpeed, i_map);
	walls[2] = TypesOfCollisions(false ,false ,false, false, Pos_X - CurrentSpeed, Pos_Y, i_map);
	walls[3] = TypesOfCollisions(false ,false ,false, false, Pos_X, CurrentSpeed + Pos_Y, i_map);

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!walls[Right]) //You can't turn in this direction if there's a wall there.
		{
			direction = Right;
		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!walls[Up])
		{
			direction = Up;
		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (0 == walls[Left])
		{
			direction = Left;
		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (0 == walls[Down])
		{
			direction = Down;
		}
	}
	
    
	if (!walls[direction] && !Dead)
	{
		switch (direction)
		{
			case Right:
			{
				
				Pos_X += CurrentSpeed;

				break;
			}
			case Up:
			{
				Pos_Y -= CurrentSpeed;

				break;
			}
			case Left:
			{
				Pos_X -= CurrentSpeed;

				break;
			}
			case Down:
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
	update_HighScore();	
}// End function update ----------

// Reset the data of pacman after its death
void PacMan::Reset()
{
	SetStartPos();
	Dead = false;
	direction = Right; // is Right
	ElapcedTime_dead = sf::seconds(0);
}

void PacMan::ShowScores(sf::RenderWindow & win)
{
	string S(to_string(Score));
	string HS(to_string(HighScore));

	ScoreText.setString(S);
	HighScoreText.setString(HS);

	win.draw(text1);
	win.draw(text2);
	win.draw(ScoreText);
	win.draw(HighScoreText);
}// End function ShowScore

void PacMan::ShowLife(sf::RenderWindow &)
{
	
}