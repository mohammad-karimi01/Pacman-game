#include "Snacks.hpp"
#include <stdexcept>
using namespace std;

/*
این تابع اساسا برای محاسبه امتیاز پک من استفاده میشود
*/
long long int GetScores_Snacks(const SnackType & type, int num)
{
   
    if (type == SnackType::Pellet){
        return 10;
    }
    else if (type == SnackType::PowerPellet){
        return 50;
    }
    else if (type == SnackType::Fapple){
        return 100;
    }
    else if (type == SnackType::Fstrawberry){
        return 300;
    }
    else if (type == SnackType::Fcherry){
        return 500;
    }
    else if (type == SnackType::Fpeach){
        return 700;
    }
    else if (type == SnackType::Fgrape){
        return 1000;
    }
    else if (type == SnackType::Fbanana){
        return 2000;
    }
    else if (type == SnackType::FrightenedGhosts){
        if (num < 1 || num > 4){
            throw invalid_argument
                ("Error: Invalide the number of ghosts in function GetScore_Snacks in Snack.cpp file");
        }
        return 200 * num;
    }
    else{
        throw invalid_argument
        ("Error: Invalide the Snakes type in function GetScore_Snacks in Snack.cpp file");
    }
}// End function GetScore...


SnackType DetermineSnack(int level)
{
    if (level >= 1 && level <= 64 ){
        return SnackType::Fapple;
    }
    else if (level >= 65 && level <= 128){
        return SnackType::Fstrawberry;
    }
    else if (level >= 129 && level <= 192){
        return SnackType::Fcherry;
    }
    else if (level >= 193 && level <= 224 ){
        return SnackType::Fpeach;
    }
    else if (level >= 225 && level <= 240){
        return SnackType::Fgrape;
    }
    else if (level >= 241 && level <= 255){
        return SnackType::Fbanana;
    }
}// End function Determin...



void DrowFruit(int )
{

}// End Function Drow...
