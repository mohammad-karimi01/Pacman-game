#ifndef _GHOSTS
#define _GHOSTS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Information.hpp"
#include "Map.hpp"

//#include "PacMan.hpp"


enum GhostsState {Wandering , Chaser , Scared};
class Ghosts
{
    
private:
    float Pos_X; // موقعیت طولی
    float Pos_Y; // موقعیت عرضی
    const int color; // Blinky = 0 , Pinky, Inky, Clyde
    int Direction; // Right = 1, Up = 2, Left = 3, Down = 4
    bool FrightenedGhosts; // if Ghosts be Scared
    float CurrentSpeed;
    sf::Time ScaredDuration; // مدت زمان ترسیده بر اساس مرحله
    sf::Time TotalTimeScared; // مجموع مدت زمان حالت ترسیده
    sf::Time ElapcedTime_Scared; // ذخیره زمان 
    int Winking; // تعداد چشمک هر مرحله
    
    sf::Sprite GhostsSprite;
	sf::Texture GhostsTexture;
	int FramNum;
	float TimeAnime;
    GhostsState  current_state; // حالت جاری روح که شامل ترسیده یا سرگردان یا تعقیب است
    
    //////////////////////////////////////////////////////////
    GhostsState  SetTimer(int, sf::Time & ); // محاسبه زمان تغییر حالت ها
    
public:
    Ghosts(int );
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;
    
    sf::Sprite & GetSprit();
  //  Color get_color();
	void Set_Animation();
    void Change_CurrentState( int, sf::Time &);
    void Set_ScaredDuration(int );
    void Drow(sf::RenderWindow &  ,  sf::Time &, sf::Time &);
    void Reset(int );
    void SetRestartPos();
    void Set_FrightenedGhosts(bool);
    bool Get_FrightenedGhosts();
    void SetSpeed(int ); // Set current speed based on argument GameLevel

    void Update(const int ,std::array<std::array<Cell,Cell_Height>, Cell_Weight> & );
};

#endif