#ifndef _GHOSTS
#define _GHOSTS
#include "GhostsState.hpp"
#include "Chaser.hpp"
#include "Wandering.hpp"
#include "Scared.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Information.hpp"
#include "PacMan.hpp"

class Ghosts
{
    
private:
    int Pos_X; // موقعیت طولی
    int Pos_Y; // موقعیت عرضی
    int color; // Blinky = 0 , Pinky, Inky, Clyde
    int Direction; // Right = 1, Up = 2, Left = 3, Down = 4
    sf::Time ScaredDuration; // مجموع مدت زمان حالت ترسیده
	sf::Sprite GhostsSprite;
	sf::Texture GhostsTexture;
	int FramNum;
	float TimeAnime;
    GhostsState * current_state; // حالت جاری روح که شامل ترسیده یا سرگردان یا تعقیب است
    //////////////////////////////////////////////////////////
    GhostsScared  scared;
    GhostsWandering wandering;
    GhostsChaser chaser;
    ////////////////////////////////////////////////////////// 
    GhostsState * SetTimer(int, sf::Time & ); // محاسبه زمان تغییر حالت ها
    void set_color(int ); // need change --- int > Color
public:
    Ghosts(int );
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;
    
    sf::Sprite & GetSprit();
  //  Color get_color();
	void Set_Animation();
    void Change_CurrentState( int, sf::Time &);
    
    void Drow(sf::RenderWindow &  ,  sf::Time &);
};

#endif