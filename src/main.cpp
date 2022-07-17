#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Enter a number : ";
    ch = cin.get();
    cin.ignore();
    cout << ch << endl;
    return 0;
}