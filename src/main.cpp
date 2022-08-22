#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
//#include "includefile.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Map.hpp"
#include "PacMan.hpp"
#include "Ghosts.hpp"
//#include "Snacks.hpp"
//#include "TypesOfCollisions.hpp"
using namespace std;

int GameLevel = 1;
//هنگام تغیر مرحله زمان سیستم رو هم ریست کن برای کلاس روح الزامیه

// از این تابع برای بررسی برخورد یا شکار پک من توسط روح استفاده میشود
bool Hunt(sf::Sprite & Spacman, sf::Sprite & ghosts)
{
    if (Spacman.getGlobalBounds().intersects(ghosts.getGlobalBounds())){
        return true;
    }
    else{
        return false;
    }
}// End function Hunt

int main()
{
    unsigned char ch = 1;
    float x = static_cast<float>(MAX_SPEED);
    //cout << x << endl;
    Map GameMap;
    PacMan Player;
    // Blinky = 0 , Pinky, Inky, Clyde
    Ghosts Blinky(0);
    Ghosts Pinky(1);
    Ghosts Inky(2);
    Ghosts Clyde(3);

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "PAC-MAN");
    window.setFramerateLimit(60);
    
    sf::Time ElapcedTime;
    sf::Clock ck;

    while (window.isOpen())
    {
        sf::Time dt = ck.restart();
        ElapcedTime += dt;
         bool flag = false;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed){
                window.close();
            }
        }

        Player.update(GameLevel, GameMap.GetMap());

        
        
        // Check collison pacman and ghosts
        if (Player.SetScore(GameMap.GetMap()))// if pacman eat Power pellet this return true
        {
            Blinky.Set_Scared();
            Pinky.Set_Scared();
            Inky.Set_Scared();
            Clyde.Set_Scared();
        }
       
        // دستورات زیر برخورد پک من و ارواح را در دو حالت ترسیده و عادی بررسی میکند
        if (!Blinky.Get_FrightenedGhosts() && Blinky.Get_Scared() )
        {
            if (Hunt(Player.GetSprite(), Blinky.GetSprit()))
            {
                Blinky.Set_FrightenedGhosts();
                cout << "Scared Blinky" << endl;
            }
            
        }
        else if ( !Blinky.Get_FrightenedGhosts() && Hunt(Player.GetSprite(), Blinky.GetSprit()))
        {
            flag = true;
        }
        if (!Pinky.Get_FrightenedGhosts() && Pinky.Get_Scared())
        {
            if (Hunt(Player.GetSprite(), Pinky.GetSprit()))
            {
                Pinky.Set_FrightenedGhosts();
            }
            
        }
        else if (!Pinky.Get_FrightenedGhosts() && Hunt(Player.GetSprite(), Pinky.GetSprit()))
        {   
            flag = true;
        }
        if (!Inky.Get_FrightenedGhosts() && Inky.Get_Scared())
        {
            if (Hunt(Player.GetSprite(), Inky.GetSprit()))
            {
                Inky.Set_FrightenedGhosts();
            }
        }
        else if (!Inky.Get_FrightenedGhosts() && Hunt(Player.GetSprite(), Inky.GetSprit()))
        { 
            flag = true; 
        }
        if (!Clyde.Get_FrightenedGhosts() && Clyde.Get_Scared())
        {
            if (Hunt(Player.GetSprite(), Clyde.GetSprit()))
            {
                Clyde.Set_FrightenedGhosts();
            }
            
        }
        else if (!Clyde.Get_FrightenedGhosts() && Hunt(Player.GetSprite(), Clyde.GetSprit()))
        {// pacman is die
            flag = true;
        }
        if (flag)
        {
            cout << "flag : " << flag << endl;
            Player.Set_Dead(); 
            Blinky.Reset(GameLevel);
            Inky.Reset(GameLevel);
            Pinky.Reset(GameLevel);
            Clyde.Reset(GameLevel);
            flag = false;
        }


        if (!Player.Get_Dead())
        {
            Blinky.Update(ElapcedTime ,GameLevel, GameMap.GetMap(), Player.Get_PosX(), Player.Get_PosY());
            Pinky.Update(ElapcedTime ,GameLevel, GameMap.GetMap(), Player.Get_PosX(), Player.Get_PosY());
            Inky.Update(ElapcedTime ,GameLevel, GameMap.GetMap(), Player.Get_PosX(), Player.Get_PosY());
            Clyde.Update(ElapcedTime ,GameLevel, GameMap.GetMap(), Player.Get_PosX(), Player.Get_PosY());
        }
        

        if (!GameMap.CountPellet()) //Pacman is won
        {
            GameLevel++;
            Player.Reset();
            Blinky.Reset(GameLevel);
            Inky.Reset(GameLevel);
            Pinky.Reset(GameLevel);
            Clyde.Reset(GameLevel);
            ElapcedTime = sf::seconds(0);
            GameMap.ToEqualize();
        }
        window.clear(sf::Color::Black);
        
        GameMap.DrowMap(window);
        Player.Drow(window, ElapcedTime, dt);
        if (!Player.Get_Dead())
        {
            Blinky.Drow(window, ElapcedTime , dt);
            Pinky.Drow(window, ElapcedTime, dt);
            Inky.Drow(window, ElapcedTime, dt);
            Clyde.Drow(window, ElapcedTime, dt);
        }
            
       
       // GameMap.DrowMap(window);
        window.display();
    }
    return 0;
}