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
using namespace std;

int GameLevel = 1;



bool Hunt(sf::Sprite & Spacman, sf::Sprite & Sghosts)
{
    if (Spacman.getGlobalBounds().intersects(Sghosts.getGlobalBounds())){
        return true;
    }
    else{
        return false;
    }
}
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
        //Player.Move(GameLevel);
        Player.update(ch, GameMap.GetMap());
        window.clear(sf::Color::Black);
        
        GameMap.DrowMap(window);
        Player.Drow(window, ElapcedTime, ck);
        Blinky.Drow(window, ElapcedTime);
        Pinky.Drow(window, ElapcedTime);
        Inky.Drow(window, ElapcedTime);
        Clyde.Drow(window, ElapcedTime);
        

        if (Hunt(Player.GetSprite(), Blinky.GetSprit()) ||
            Hunt(Player.GetSprite(), Pinky.GetSprit()) ||
            Hunt(Player.GetSprite(), Inky.GetSprit()) ||
            Hunt(Player.GetSprite(), Clyde.GetSprit())  )
        {
            cout << "Barkhorddddddddddddddddddd" << endl;
        }
       // GameMap.DrowMap(window);
        window.display();
    }
    return 0;
}