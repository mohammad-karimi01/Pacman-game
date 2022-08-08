#ifndef SNACKS_HPP
#define SNACKS_HPP

enum SnackType 
{Pellet, PowerPellet, Fapple, Fstrawberry, Fcherry, Fpeach, Fgrape, Fbanana, Frigh , FrightenedGhosts};
//                                           totfarangi   albalu   holoo   angor

SnackType DetermineSnack(int );
long long int GetScores_Snacks(SnackType, int ); // int is number of Ghosts(1-4)
void DrowFruit(int ); // argument is level game

#endif