#pragma onec

#include <array>
#include <cmath>
#include "Map.hpp"
/*
عملکرد تابع؟
این تابع برای تنظیم حرکت روح ها و پک من
همچنین بررسی برخورد پک من و گلوله ها است
در صورت خورده شدن گلوله ها توسط پک من جای گلوله ها با فضای خالی عوض میشود

*/
bool TypesOfCollisions
(bool EatPellets, bool EatPowerPellets, float P_x , float P_y,
 std::array<std::array<Cell,Cell_Height>, Cell_Weight> & GameMap )
{
    
    bool output = false;
    int x = 0, y = 0;
    // دو دستور زیر قدم اول برای معادل سازی موقعیت کاراکتر در نقشه گرافیکی
    // با نقشه ی حاوی اطلاعات قابل پردازش است
    // نقشه قابل پردازش همان 
    // MainMap ----> in class Map.hpp
    // است
    float Temp_x = P_x / static_cast<float>(Cell_Size); 
	float Temp_y = P_y / static_cast<float>(Cell_Size);
    
/*
حلقه زیر شامل الگوریتم اصلی برای سنجش برخورد یا عدم برخورد است
توضییحات دقیق تر در گزارش کار
*/
    for (size_t i = 0; i < 4; i++)
    {
        switch (i)
		{
			case 0: 
			{
				x = static_cast<short>(floor(Temp_x));
				y = static_cast<short>(floor(Temp_y));

				break;
			}
			case 1: 
			{
				x = static_cast<short>(ceil(Temp_x));
				y = static_cast<short>(floor(Temp_y));

				break;
			}
			case 2: 
			{
				x = static_cast<short>(floor(Temp_x));
				y = static_cast<short>(ceil(Temp_y));

				break;
			}
			case 3:
			{
				x = static_cast<short>(ceil(Temp_x));
				y = static_cast<short>(ceil(Temp_y));
			}
		}// End switch case


        if (0 <= x && 0 <= y && Cell_Height > y && Cell_Weight > x)
		{
			if (!EatPellets) 
			{
				if (Cell::Wall == GameMap[x][y])
				{
					output = true;
				}
				// else if (0 == i_use_door && Cell::Door == i_map[x][y])
				// {
				// 	output = 1;
				// }
			}
			else 
			{
				if (Cell::Power_Food == GameMap[x][y])
				{
					output = true;

					GameMap[x][y] = Cell::Empty;
				}
				else if (Cell::Food == GameMap[x][y])
				{
					GameMap[x][y] = Cell::Empty;
                    return true;
				}
			}
		}
    }// End for 1

	return output;
}//End function TypesOfCollisions

