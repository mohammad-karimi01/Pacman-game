#ifndef _PACMAN
#define _PACMAN
//#include "Information.hpp"
//#include "Snacks.hpp"
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include <array>

typedef long long int llint;

enum Directions {Right, Up,Left, Down, Stop};

class PacMan
{
    
private:
    float Pos_X; // موقعیت طولی
    float Pos_Y; // موقعیت عرضی
    int Life; // تعداد جان های پک من
    llint Score; // مقدار امتیاز پک من  
    llint HighScore;
    float CurrentSpeed;
   // Directions direction;
    Directions Key;
    int direction;
    sf::Sprite PacmanSprite;
    sf::Texture PacmanTexture;
    int FramNum;
    float TimeAnime;
    bool Die; // this member set when pacman hunt by ghosts
    bool EatPowerPellet; // this member set when eating Power pellet by pacman

	///////////////////
    void set_HighScore();
    void Set_Speed(int level);
   
    void Set_Animation(); // Information of animations Pacman
    void SetStartPos(); // when pacman is start game or die by ghosts this function reset the pacman position
public:
    //PacMan(int , int);
    PacMan();
    ~PacMan();
    
    
	void Reset();

    void Set_EatPowerPellet(bool );
    bool Get_EatPowerPellet();
   
    
    int get_life() const;
    
    llint get_score() const;
    llint get_HighScore() const;
    
    void update_HighScore();
    void Destroy();

	sf::Sprite & GetSprite(); // this function use in function hunt in main file
    void Drow(sf::RenderWindow & , sf::Time & , sf::Clock &);

	// this get LevelGame and MapGame then Update the changes
	void update(const int , std::array<std::array<Cell,Cell_Height>, Cell_Weight> & );
	bool SetScore(std::array<std::array<Cell,Cell_Height>, Cell_Weight> & );

};

#endif