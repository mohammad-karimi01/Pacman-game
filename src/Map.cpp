#include "Map.hpp"
#include <iostream>


Map::Map()
{
	Set_Pattern();
	ToEqualize();

}// End Constructor

void Map::Set_Pattern()
{
     PatternMap = {
        " ################### ",
		" #........#........# ",
		" #*##.###.#.###.##*# ",
		" #.................# ",
		" #.##.#.#####.#.##.# ",
		" #....#...#...#....# ",
		" ####.### # ###.#### ",
		"    #.#   0   #.#    ",
		"#####.# ##=## #.#####",
		"     .  #123#  .     ",
		"#####.# ##### #.#####",
		"    #.#       #.#    ",
		" ####.# ##### #.#### ",
		" #........#........# ",
		" #.##.###.#.###.##.# ",
		" #*.#.....P.....#.*# ",
		" ##.#.#.#####.#.#.## ",
		" #....#...#...#....# ",
		" #.######.#.######.# ",
		" #.................# ",
		" ################### "
    };
}// End function Set_pattern

/* 
تابع معادل سازی چه عملکردی دارد؟
در این تابع عملیات معادل سازی نقشه اصلی با طرح نقشه انجام میشود
PatternMap ---> MainMap 
*/
void Map::ToEqualize()
{
	for (int row = 0; row < Cell_Height ; row++){
		for (int col = 0; col < Cell_Weight; col++){
			

			switch (PatternMap[row][col])
			{
				case '#' :
					MainMap[col][row] = Cell::Wall;
					break;
				case '.' :
					MainMap[col][row] = Cell::Food;
					break;
				case '*' :
					MainMap[col][row] = Cell::Power_Food;
					break;
				case '=' :
					MainMap[col][row] = Cell::Door;
					break;
				default :
					MainMap[col][row] = Cell::Empty;
					break;
			}// End Switch-Case
		}// End for 2
	}// End for 1
}// End function ToEqualize

std::array<std::array<Cell, 21ULL>, 21ULL> & Map::GetMap() 
{
	return MainMap;
}
/*
عملکر این تابع رسم نقشه بازی است
*/
void Map::DrowMap(sf::RenderWindow & win)
{
	sf::RectangleShape S_wall(sf::Vector2f(Cell_Size, Cell_Size));
	S_wall.setFillColor(sf::Color::Blue);

	sf::CircleShape S_Foode(2);
	S_Foode.setFillColor(sf::Color::Yellow);

	sf::CircleShape S_power_Foode(6);
	S_power_Foode.setFillColor(sf::Color::Yellow);

	sf::RectangleShape S_door(sf::Vector2f(Cell_Size, Cell_Size/2));
	S_door.setFillColor(sf::Color::Magenta);

	for (int row = 0; row < Cell_Height ; row++){
		for (int col = 0; col < Cell_Weight; col++){

			if (MainMap[row][col] == Cell::Wall)
			{
				S_wall.setPosition(sf::Vector2f(row * Cell_Size, col * Cell_Size));
				win.draw(S_wall);
			}
			if (MainMap[row][col] == Cell::Food)
			{
				S_Foode.setPosition
				(sf::Vector2f(row * Cell_Size + (Cell_Size/2), col * Cell_Size + (Cell_Size/2)));
				win.draw(S_Foode);
			}
			if (MainMap[row][col] == Cell::Power_Food)
			{
				S_power_Foode.setPosition
				(sf::Vector2f(row * Cell_Size + (Cell_Size/2 - 3), col * Cell_Size + (Cell_Size/2 -3 )));
				win.draw(S_power_Foode);
			}
			if (MainMap[row][col] == Cell::Door)
			{
				S_door.setPosition(sf::Vector2f(row * Cell_Size, col * Cell_Size));
				win.draw(S_door);
			}

		}// End for 2
	}// End for 1
} //End function DrowMap