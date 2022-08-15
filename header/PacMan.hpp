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

    ///////////////////
    void set_HighScore();
    void Set_Speed(int level);
    // bool collison(const std::array<std::array<Cell,Cell_Height>, Cell_Weight> &, Directions);
    //  void collison2(const std::array<std::array<Cell,Cell_Height>, Cell_Weight> &, Directions);
    void Set_Animation(); // Information of animations Pacman
public:
    //PacMan(int , int);
    PacMan();
    ~PacMan();
    
    sf::Sprite & GetSprite();
    
    void update(unsigned char i_level, std::array<std::array<Cell,Cell_Height>, Cell_Weight> & );

  //  void Update(const std::array<std::array<Cell,Cell_Height>, Cell_Weight> &, int );
    void Set_X();
    void Set_Y();
    void Move(int ); // parameter is Game level
    //void Drow(sf::RenderWindow &);

    int get_life() const;
   // void set_score(SnackType , int = 0);
    llint get_score() const;
    llint get_HighScore() const;
    
    void update_HighScore();
    void Destroy();

    void Drow(sf::RenderWindow & , sf::Time & , sf::Clock &);
};

#endif