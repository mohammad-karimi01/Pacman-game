#pragma once
#include <array>
#include <string>

#include "Information.hpp"

#define Cell_Height 21 // ارتفاع نقشه  بدون ضریب اندازه هر سلول
#define Cell_Weight 21 // عرض نقشه


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
        void DrowMap();
        

};


    