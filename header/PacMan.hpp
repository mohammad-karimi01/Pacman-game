#ifndef _PACMAN
#define _PACMAN
#include "Information.hpp"
#include "Snacks.hpp"
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include <array>
typedef long long int llint;

enum Directions { Stop, Right, Left, Up, Down};

class PacMan
{
private:
    float Pos_X; // موقعیت طولی
    float Pos_Y; // موقعیت عرضی
    int Life; // تعداد جان های پک من
    llint Score; // مقدار امتیاز پک من  
    llint HighScore;
    float CurrentSpeed;
    Directions direction;

    sf::Sprite PacmanShape;


    ///////////////////
    void set_HighScore();
    void Set_Speed(int level);
    bool collison(const std::array<std::array<Cell,Cell_Height>, Cell_Weight> &, Directions D);
public:
    //PacMan(int , int);
    PacMan();
    ~PacMan();
    
    
    void Update(const std::array<std::array<Cell,Cell_Height>, Cell_Weight> &);
    void Set_X(float );
    void Set_Y(float );
    void Move(int ); // parameter is Game level
    

    int get_life() const;
    void set_score(SnackType , int = 0);
    llint get_score() const;
    llint get_HighScore() const;
    
    void update_HighScore();
    void Destroy();

    void Drow(sf::RenderWindow & );
};

#endif