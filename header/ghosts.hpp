#ifndef _GHOSTS
#define _GHOSTS
#include "ghosts_state.hpp"

#define LP 7

enum Color {Blinky = 1 , Pinky, lnky, Clyde};
//          ghermez  sorati  firozei   narngi
// typedef long long int llint;

class Ghosts
{
private:
    int X; // موقعیت طولی
    int Y; // موقعیت عرضی
    ghosts_state * current_state;
    Color color;
public:
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;
    void set_color(Color );
    Color get_color();

    void Change_CurrentState(ghosts_state * );
   
};

#endif