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
bool Hunt(sf::Sprite & Spacman, sf::Sprite & Sghosts)
{
    if (Spacman.getGlobalBounds().intersects(Sghosts.getGlobalBounds())){
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

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed){
                window.close();
            }
        }
        // Check collison pacman and ghosts
        if (Player.SetScore(GameMap.GetMap()))
        {
            //cout << "############333";
            Blinky.Set_FrightenedGhosts(true);
            Pinky.Set_FrightenedGhosts(true);
            Inky.Set_FrightenedGhosts(true);
            Clyde.Set_FrightenedGhosts(true);
        }

        // if (Hunt(Player.GetSprite(), Blinky.GetSprit()) ||
        //     Hunt(Player.GetSprite(), Pinky.GetSprit()) ||
        //     Hunt(Player.GetSprite(), Inky.GetSprit()) ||
        //     Hunt(Player.GetSprite(), Clyde.GetSprit())  )
        // {
        //     Player.Destroy();
        // }
        Player.update(ch, GameMap.GetMap());
        window.clear(sf::Color::Black);
        
        GameMap.DrowMap(window);
        Player.Drow(window, ElapcedTime, ck);
        Blinky.Drow(window, ElapcedTime , dt);
        Pinky.Drow(window, ElapcedTime, dt);
        Inky.Drow(window, ElapcedTime, dt);
        Clyde.Drow(window, ElapcedTime, dt);
        
       
       // GameMap.DrowMap(window);
        window.display();
    }
    return 0;
}