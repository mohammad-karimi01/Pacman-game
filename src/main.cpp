#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
//#include "includefile.hpp"
#include "../header/PacMan.hpp"
using namespace std;

int main()
{
    PacMan p;

    cout << "Life: " << p.get_life() << endl
         << "Score: " << p.get_score() << endl
         << "High score: " << p.get_HighScore() << endl
         << "Position ----- X: " << p.get_x() << "--- Y: " << p.get_y() << endl; 
    cout << "..................................................." << endl;
    p.set_score(5555);
    p.update_HighScore();
    cout << "Life: " << p.get_life() << endl
         << "Score: " << p.get_score() << endl
         << "High score: " << p.get_HighScore() << endl
         << "Position ----- X: " << p.get_x() << "--- Y: " << p.get_y() << endl; 

    cout << "End...." << endl;
    return 0;
}