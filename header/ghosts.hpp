#ifndef _GHOSTS
#define _GHOSTS
#include "GhostsState.hpp"
#include "Chaser.hpp"
#include "Wandering.hpp"
#include "Scared.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>



class Ghosts
{
private:
    int Pos_X; // موقعیت طولی
    int Pos_Y; // موقعیت عرضی
    GhostsState * current_state; // حالت جاری روح که شامل ترسیده یا سرگردان یا تعقیب است
    int color; // Blinky = 0 , Pinky, Inky, Clyde
    int Direction; // Right = 0, Up = 1, Left = 2, Down = 3
    sf::Time ScaredDuration; // مجموع مدت زمان حالت ترسیده

    GhostsScared scared;
    GhostsWandering wandering;
    GhostsChaser chaser;
    GhostsState * SetTimer(int, sf::Time & ); // محاسبه زمان تغییر حالت ها
    void set_color(int ); // need change --- int > Color
public:
    Ghosts(GhostsState *, Color);
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;
   
    Color get_color();

    void Change_CurrentState( int, sf::Time &);

    void print();
};

#endif