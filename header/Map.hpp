#ifndef MAP_HPP
#define MAP_HPP


#include <array>
#include <string>
#include <SFML/Graphics.hpp>
//#include "Information.hpp"
#include "Information.hpp"
enum Cell {Wall, Empty, Food, Power_Food, Door};
class Map
{
    private :
       
        std::array<std::string, Cell_Height> PatternMap; 
        std::array<std::array<Cell,Cell_Height>, Cell_Weight> MainMap; 
         
        void Set_Pattern();
        void ToEqualize();
    public :
        Map();
        
        std::array<std::array<Cell,Cell_Height>, Cell_Weight> & GetMap() ;
        void DrowMap(sf::RenderWindow & );
        void UpdateMap();
};


#endif