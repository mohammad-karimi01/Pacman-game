#include "Map.hpp"
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
					MainMap[row][col] = Cell::Wall;
					break;
				case '.' :
					MainMap[row][col] = Cell::Pellet;
					break;
				case '*' :
					MainMap[row][col] = Cell::Power_Pellet;
					break;
				default :
					MainMap[row][col] = Cell::Empty;
					break;
			}// End Switch-Case
		}// End for 2
	}// End for 1
}// End function ToEqualize