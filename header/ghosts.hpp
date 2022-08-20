#ifndef _GHOSTS
#define _GHOSTS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Information.hpp"
#include "Map.hpp"

//#include "PacMan.hpp"

enum IS_Direction {G_Right = 0, G_Down, G_Left, G_Up};
enum GhostsState {Wandering , Chaser , Scared, FrightenedGhosts, None};
class Ghosts
{
    
private:
    bool house; // if ghosts be in house this is true
    float Pos_X; // موقعیت طولی
    float Pos_Y; // موقعیت عرضی
    const int color; // Blinky = 0 , Pinky, Inky, Clyde
    IS_Direction Direction; 
   // bool FrightenedGhosts; // if Ghosts eat by pacman in state scared
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
    void DirectionRandom(std::array<bool, 4> & ); // تعیین جهت اروح در تقاطع ها
public:
    Ghosts(int );
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;
    
    void Set_FrightenedGhosts();
    bool Get_FrightenedGhosts();
    sf::Sprite & GetSprit();
  //  Color get_color();
	void Set_Animation();
    void Change_CurrentState( int, sf::Time &);
    void Set_ScaredDuration(int );
    void Drow(sf::RenderWindow &  ,  sf::Time &, sf::Time &);
    void Reset(int );
    void SetRestartPos();
    void Set_Scared();
    bool Get_Scared();
    void SetSpeed(int ); // Set current speed based on argument GameLevel
    void reverse();
    void DirectionChaser(std::array<bool, 4> &, float, float);
    void Update(sf::Time & ,const int ,std::array<std::array<Cell,Cell_Height>, Cell_Weight> & , float, float);
};

#endif