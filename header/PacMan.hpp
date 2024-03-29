#ifndef _PACMAN
#define _PACMAN
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include <array>
typedef long long int llint;

enum Directions {Right = 0, Up,Left, Down, Stop};

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
        sf::Texture LifeTextur;
        sf::Sprite PacmanSprite;
        sf::Texture PacmanTexture;
        sf::Font font;
        sf::Text ScoreText;
        sf::Text HighScoreText;
        sf::Text text1;
        sf::Text text2;
        int FramNum; // number of fram in imaages pacman
        float TimeAnime;
        bool Dead ; // this member set when pacman hunt by ghosts
        sf::Time ElapcedTime_dead;
        
        ///////////////////
        void set_HighScore();
        void Set_Animation(); // Information of animations Pacman
        void SetStartPos(); // when pacman is start game or die by ghosts this function reset the pacman position
        void SetFont();
    public:
        PacMan();
        ~PacMan();
        float Get_PosX() const;
        float Get_PosY() const;
        void Set_Dead();
        bool Get_Dead();
        int get_life() const;
        llint get_score() const;
        llint get_HighScore() const;
        sf::Sprite & GetSprite(); // this function use in function hunt in main file
        void update_HighScore();
        void Reset(); // call when pacman is win
        bool SetScorePellet(std::array<std::array<Cell,Cell_Height>, Cell_Weight> & );
        void SetScoreGhosts(int );
        void Destroy();// cal when pacman is die
        void Drow(sf::RenderWindow & , sf::Time & , sf::Time &);
        // this get LevelGame and MapGame then Update the changes
        void update(const int , std::array<std::array<Cell,Cell_Height>, Cell_Weight> & );
        void ShowScores(sf::RenderWindow & ); // show score and highscore in rendering
        void ShowLife(sf::RenderWindow &);
};

#endif