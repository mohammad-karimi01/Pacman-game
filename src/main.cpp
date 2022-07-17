#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include "includefile.hpp"

using namespace std;

int main()
{
    PacMan m;
    char ch;
    cout << "Enter a number : ";
    ch = cin.get();
    cin.ignore();
    cout << ch << endl;
    return 0;
}