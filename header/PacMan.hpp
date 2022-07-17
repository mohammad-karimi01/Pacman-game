#ifndef _PACMAN
#define _PACMAN
#define LP 7
typedef long long int llint;
class PacMan
{
private:
    int X; // موقعیت طولی
    int Y; // موقعیت عرضی
    int Life; // تعداد جان های پک من
    llint Score; // مقدار امتیاز پک من  
public:
    PacMan();
    ~PacMan();
    void set_life(int);
    int get_life() const;
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;
    void set_score(llint );
    llint get_score() const;
};

#endif