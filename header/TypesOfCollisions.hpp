#ifndef _TYPEOFCOLLISIONS
#define _TYPEOFCOLLISIONS

#include <array>
#include "Map.hpp"
/*
عملکرد تابع؟
این تابع برای تنظیم حرکت روح ها و پک من
همچنین بررسی برخورد پک من و گلوله ها است
در صورت خورده شدن گلوله ها توسط پک من جای گلوله ها با فضای خالی عوض میشود

*/
bool TypesOfCollisions
(bool, bool, bool, bool, float, float, std::array<std::array<Cell,Cell_Height>, Cell_Weight> &  );


#endif