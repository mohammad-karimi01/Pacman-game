#ifndef SNACKS_HPP
#define SNACKS_HPP
#include <stdexcept>
using namespace std;

enum SnackType 
{apple, strawberry, cherry, peach, grape, banana};
//                                           totfarangi   albalu   holoo   angor

/*
این تابع اساسا برای محاسبه امتیاز پک من استفاده میشود
*/
long long int GetScores_Snacks(const SnackType & type, int num)
{
    if (type == SnackType::apple){
        return 100;
    }
    else if (type == SnackType::strawberry){
        return 300;
    }
    else if (type == SnackType::cherry){
        return 500;
    }
    else if (type == SnackType::peach){
        return 700;
    }
    else if (type == SnackType::grape){
        return 1000;
    }
    else if (type == SnackType::banana){
        return 2000;
    }
    else{
        throw invalid_argument
        ("Error: Invalide the Snakes type in function GetScore_Snacks in Snack.cpp file");
    }
}// End function GetScore...


SnackType DetermineSnack(int level)
{
    if (level >= 1 && level <= 64 ){
        return SnackType::apple;
    }
    else if (level >= 65 && level <= 128){
        return SnackType::strawberry;
    }
    else if (level >= 129 && level <= 192){
        return SnackType::cherry;
    }
    else if (level >= 193 && level <= 224 ){
        return SnackType::peach;
    }
    else if (level >= 225 && level <= 240){
        return SnackType::grape;
    }
    else if (level >= 241 && level <= 255){
        return SnackType::banana;
    }
    else{
        return SnackType::banana;
    }
} 



// void DrowFruit(int )
// {

// }// End Function Drow...

#endif