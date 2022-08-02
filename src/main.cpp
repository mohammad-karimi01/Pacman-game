#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include "includefile.hpp"

using namespace std;
int main()
{
    pellets p;
    power_pellets pp;
    fruits f;
    
    snacks s1(&p, 1,1);

    snacks s2(&pp, 2,2);
    snacks s3(&f, 3,3);

    s1.print();
    s2.print();
    s3.print();
    

    cout << "End...." << endl;
    return 0;
}