#ifndef _SNACKS
#define _SNACKS
#include "snacks_state.hpp"

#define LP 7
// typedef long long int llint;

class snacks
{
private:
    int X; // موقعیت طولی
    int Y; // موقعیت عرضی
    snacks_state * current_state;
public:
    snacks(snacks_state * , int, int);
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;

    void ChangeState(snacks_state *);
    
    void print();
};

#endif