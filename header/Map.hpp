#ifndef MAP_HPP
#define MAP_HPP


#include <array>
#include <string>
#include <SFML/Graphics.hpp>
//#include "Information.hpp"
#include "Information.hpp"
class Map
{
    private :
        enum Cell {Wall, Empty, Pellet, Power_Pellet, Door};
        std::array<std::string, Cell_Height> PatternMap; 
        std::array<std::array<Cell,Cell_Height>, Cell_Weight> MainMap; 
         
    public :
        Map();
        void Set_Pattern();
        void ToEqualize();
        void DrowMap(sf::RenderWindow & );
        void UpdateMap();
};


#endif