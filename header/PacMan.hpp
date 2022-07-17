#ifndef _PACMAN
#define _PACMAN
#define LP 7
typedef long long int llint;
class PacMan
{
private:
    int X; // موقعیت طولی
    int Y; // موقعیت عرضی
    static int Life; // تعداد جان های پک من
    static llint Score; // مقدار امتیاز پک من  
    llint HighScore;
    ///////////////////
    void set_HighScore();
public:
    //PacMan(int , int);
    PacMan();
    ~PacMan();
    
    int get_life() const;
    void set_xy(int, int);
    int get_x() const;
    int get_y() const;
    void set_score(llint );
    llint get_score() const;
    llint get_HighScore() const;
    
    void update_HighScore();
    void Destroy();
};

#endif