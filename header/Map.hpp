#ifndef MAP_HPP
#define MAP_HPP
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include "Information.hpp"
enum Cell {Wall, Empty, Food, Power_Food, Door};
class Map
{
    private : 
        std::array<std::string, Cell_Height> PatternMap;
        std::array<std::array<Cell,Cell_Height>, Cell_Weight> MainMap; // this is Main and use in program
        void Set_Pattern();// Initialization Pattern Map
    public :
        Map();
        bool CountPellet(); // if  all the food is eaten return true
        std::array<std::array<Cell,Cell_Height>, Cell_Weight> & GetMap() ; //return the main map
        void DrowMap(sf::RenderWindow & );
        void UpdateMap(); 
        void ToEqualize();// Initialization MainMap based on PatternMap
};

#endif