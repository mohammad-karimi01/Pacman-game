#ifndef _GHOSTS
#define _GHOSTS
#include "ghosts_state.hpp"

#define LP 7
// typedef long long int llint;

class Ghosts
{
private:
    int X; // موقعیت طولی
    int Y; // موقعیت عرضی
    ghosts_state * current_state;
public:
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;

    void Change_CurrentState(ghosts_state * );
   
};

#endif