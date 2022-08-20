#include "Ghosts.hpp"
#include <iostream>
#include <stdexcept>
#include "TypesOfCollisions.hpp"
#include <ctime>
#include <random>
#include <cmath>
using namespace std;

Ghosts::Ghosts( int c) : 
TotalTimeScared(sf::seconds(0)),
color(c), 
current_state(Wandering),
CurrentSpeed(2),
house(true)
{
    
    SetRestartPos();
    Set_Animation();
    Set_ScaredDuration(1);
}

void Ghosts::Set_Scared()
{
    reverse();
    current_state = Scared;
    if (ElapcedTime_Scared > sf::seconds(0))
    {
        ElapcedTime_Scared = sf::seconds(0);  
    }
}
bool Ghosts::Get_Scared()
{
    if (current_state == Scared)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Ghosts::Set_FrightenedGhosts()
{
    reverse();
    current_state = FrightenedGhosts;
}
bool Ghosts::Get_FrightenedGhosts()
{
    if (current_state == FrightenedGhosts)
        return true;
    else
        return false;
}


void Ghosts::SetRestartPos()
{
    float Size = static_cast<float>(Cell_Size);
    if (color == 0){
        Pos_X = 10 * Size ;
        Pos_Y = 7 * Size;
        Direction = G_Right;
    }
    else if (color == 1){
        Pos_X = 9 * Size;
        Pos_Y = 9 * Size;
        Direction = G_Right;
    }
    else if (color == 2){
        Pos_X = 10 * Size;
        Pos_Y = 9 * Size;
        Direction = G_Up;
    }
    else if (color == 3){
        Pos_X = 11 * Size;
        Pos_Y = 9 * Size;
        Direction = G_Left;
    }
    else{
        throw invalid_argument("Error: invalid start position of Ghosts in constructors ghosts");
    }

}

void Ghosts::reverse()
{
    if (Direction == G_Right){
        Direction = G_Left;
    }
    else if (Direction == G_Left){
        Direction = G_Right;
    }
    else if (Direction == G_Up){
        Direction = G_Down;
    }
    else if (Direction == G_Down){
        Direction = G_Up;
    }
}

GhostsState  Ghosts::SetTimer(int L, sf::Time & ETime) // L is GameLevel --- Etime is ElapcedTime of Game
{
    sf::Time temp = sf::seconds(ETime.asSeconds() - TotalTimeScared.asSeconds());
    
    if (L == 1){
        if (temp >= sf::seconds(0) && temp <= sf::seconds(7) || 
            temp >= sf::seconds(27) && temp <= sf::seconds(34) ||
            temp >= sf::seconds(54) && temp <= sf::seconds(59) ||
            temp >= sf::seconds(79) && temp <= sf::seconds(84) )
            {
                if (current_state != Wandering){
                    reverse();
                }
                return Wandering; // سرگردان
            }
        else {
            if (current_state != Chaser){
                    reverse();
                }
            return Chaser; // تعقیب

        }
    }
    else if (L >= 2 && L <= 4){
        if (temp >= sf::seconds(0) && temp <= sf::seconds(7) || 
            temp >= sf::seconds(27) && temp <= sf::seconds(34) ||
            temp >= sf::seconds(54) && temp <= sf::seconds(59) ||
            temp >= sf::seconds(1092) && temp <= sf::seconds(1093.6) )
            {
                if (current_state != Wandering){
                    reverse();
                }
                return Wandering; // سرگردان
            }
        else {
            if (current_state != Chaser){
                    reverse();
                }
            return Chaser ; // تعقیب

        }
    }
    else if ( L >= 5){
        if (temp >= sf::seconds(0) && temp <= sf::seconds(5) || 
            temp >= sf::seconds(25) && temp <= sf::seconds(30) ||
            temp >= sf::seconds(50) && temp <= sf::seconds(55) ||
            temp >= sf::seconds(1092) && temp <= sf::seconds(1093.6) )
            {
                if (current_state != Wandering){
                    reverse();
                }
                return Wandering; // سرگردان
            }
        else {
            if (current_state != Chaser){
                    reverse();
                }
            return Chaser; // تعقیب

        }
    }
    else{
        throw invalid_argument
        ("Error: The number of GameLeve in function SetTimer of class Ghosts is invalid");
    }
}// End function SetTimer

// L is LevelGame
// ET is ElapcedTime system
void Ghosts::Change_CurrentState(int L, sf::Time & ET )
{
    if (Get_Scared())
    {
        current_state = Scared;
    }
    else if (Get_FrightenedGhosts())
    {
        current_state = FrightenedGhosts;
    }
    else{
        current_state = SetTimer(L, ET);
    }
    
}// End function Change_CurrentState

/*
این تابع برخورد پک من با روح هارا بررسی میکند
*/
sf::Sprite &Ghosts::GetSprit()
{
    return GhostsSprite;
}

void Ghosts::Reset(int L) // L is LevelGame
{
    SetRestartPos();
    Set_ScaredDuration(L);
    TotalTimeScared = sf::seconds(0);
    current_state = Wandering ;
    house = true;
}

void Ghosts::Set_ScaredDuration(int L)
{
    if (L == 1){
        ScaredDuration = sf::seconds(6);
        Winking = 5;
    }
    else if (L == 2){
        ScaredDuration = sf::seconds(5);
        Winking = 5;        
    }
    else if (L == 3){
        ScaredDuration = sf::seconds(4);
        Winking = 5;            
    }
    else if (L == 4){
        ScaredDuration = sf::seconds(3);
        Winking = 4;            
    }
    else if (L == 5){
        ScaredDuration = sf::seconds(2);
        Winking = 4;            
    }
    else if (L >= 6 && L <= 10){
        ScaredDuration = sf::seconds(4);
        Winking = 5;            
    }
    else if (L >= 11 && L <= 16){
        ScaredDuration = sf::seconds(3);
        Winking = 4;            
    }
    else if (L >= 17 && L <= 32){
        ScaredDuration = sf::seconds(2);
        Winking = 4;            
    }
    else if (L >= 33 && L <= 64){
        ScaredDuration = sf::seconds(1);
        Winking = 3;            
    }
    else if (L == 128){
        ScaredDuration = sf::seconds(0);
        Winking = 0;            
    }
    else if (L > 128 || (L >=65 && L < 128) ){
        ScaredDuration = sf::seconds(0);
        Winking = 0;
    }
    else {
        throw invalid_argument("Error: invalid number of LevelGame in function Set_ScaredDuration");
    }

}


void Ghosts::SetSpeed(int L)
{
    //float MaxSpeed = static_cast<float>(MAX_SPEED);
    bool Tunel = false;
    if ((Pos_Y == 9 * Cell_Size) && 
        ( (Pos_X < 4 * Cell_Size) || (Pos_X > 16 * Cell_Size) ) )
    {
        Tunel = true;
    }

    //if (L >= 1 && L <= 4){
    if (Get_FrightenedGhosts())
    {
        CurrentSpeed = 6;
    }
    else if (Get_Scared() || Tunel){
        CurrentSpeed = 2;
        //MaxSpeed * ((float)50/100);
    }
    else{
        CurrentSpeed = 4;
        //MaxSpeed * ((float)100/100);
    }
    ///////////////////////
    // بررسی این مسئله که ایا موقعیت فعلی با در نظر گرفتن سرعت جدید
    // منجر به تداخل در پیکسل های اشیا میشود یا نه
    // اگر بشود منجر به باگ شده و رفتار اشیا نامشخص است
   
    // }
    // else if (L >= 5 && L <= 20){
    //      if (Get_Scared()){
    //        CurrentSpeed = MaxSpeed * ((float)55/100);
    //    }
    //    else if (Tunel){
    //         CurrentSpeed = MaxSpeed * ((float)45/100);

    //    }
    //    else{
    //        CurrentSpeed = MaxSpeed * ((float)85/100);
    //    }
    // }
    // else if (L >= 21){
    //     if (Get_Scared()){
    //        CurrentSpeed = MaxSpeed * ((float)60/100);
    //    }
    //    else if (Tunel){
    //         CurrentSpeed = MaxSpeed * ((float)50/100);

    //    }
    //    else{
    //        CurrentSpeed = MaxSpeed * ((float)95/100);
    //    }

    // }

}

void Ghosts::Update(sf::Time & ET ,const int level,array<array<Cell,Cell_Height>, Cell_Weight> & Gmap, float x, float y)
{
    array<bool, 4> walls = {true};
    walls[0] = TypesOfCollisions(Get_FrightenedGhosts() ,house ,false, false, Pos_X + CurrentSpeed , Pos_Y, Gmap); // G_Right
    walls[1] = TypesOfCollisions(Get_FrightenedGhosts() ,house ,false, false, Pos_X , Pos_Y + CurrentSpeed, Gmap);// G_Down
    walls[2] = TypesOfCollisions(Get_FrightenedGhosts() ,house ,false, false, Pos_X - CurrentSpeed, Pos_Y, Gmap);// G_Left
    walls[3] = TypesOfCollisions(Get_FrightenedGhosts() ,house ,false, false, Pos_X , Pos_Y - CurrentSpeed , Gmap);// G_Up
  
    
    //SetSpeed(level);
    Change_CurrentState(level, ET);

    if (Pos_Y == 7 * Cell_Size) // if true --> ghost exit from house
    { 
        house = false;
    }

    if (Get_FrightenedGhosts())
    {
        if (Pos_X == 10 * Cell_Size && Pos_Y == 9 * Cell_Size)
        {
            current_state = None;
            house = true;
        }
        else 
        {
            DirectionChaser(walls, 10 * Cell_Size, 9 * Cell_Size);
        }
    }
    else if (current_state == Scared || current_state == Wandering)
    {
        DirectionRandom(walls);
    }
    else if (current_state == Chaser)
    {
        DirectionChaser(walls, x, y);
    }
    
    if (!walls[Direction])
	{
		switch (Direction)
		{
			case G_Right:
			{	
				Pos_X += CurrentSpeed;
				break;
			}
			case G_Down:
			{
				Pos_Y += CurrentSpeed;
				break;
			}
			case G_Left:
			{
				Pos_X -= CurrentSpeed;
				break;
			}
			case G_Up:
			{
				Pos_Y -= CurrentSpeed;
                break;
			}
		}
	}
    // تنظیم حرکت در تونل ها
	if (-Cell_Size >= Pos_X) 
	{
		Pos_X = Cell_Size * Cell_Weight - CurrentSpeed;
	}
	else if (Cell_Size * Cell_Weight <= Pos_X)
	{
		Pos_X = CurrentSpeed - Cell_Size;
	}
}

void Ghosts::Set_Animation()
{
    FramNum = 2; // number of frame in Image Pacman
    TimeAnime = .5; // Animation durition
    if (!GhostsTexture.loadFromFile("C:/Users/K2/Desktop/Pacman-game/Ghosts32.png")){
        throw runtime_error("Ghosts Image can not load");
    }
    GhostsSprite.setTexture(GhostsTexture);

}// End function Set_Sprite

void Ghosts::Drow(sf::RenderWindow & window, sf::Time & ElapcedTime, sf::Time & dt)
{
    int Size = static_cast<int>(Cell_Size); // this is Cell Size --- size of all Ellement
    float TimeAsSecond = ElapcedTime.asSeconds();
    int AnimFram;
    if (Get_FrightenedGhosts())
    {
       // AnimFram = static_cast<int>((TimeAsSecond / TimeAnime) * 4 ) % 4 ;
        GhostsSprite.setTextureRect
        (sf::IntRect( Direction * Size * 2, 4 * Size , Size, Size));
    }
    else if (Get_Scared())
    {
        ElapcedTime_Scared += dt; // محاسبه مدت زمانی که روح در حالت ترسیده قرار اس بماند
        TotalTimeScared += dt;
        // شرط چشمک زدن روح ترسیده
        //sf::seconds((TimeAnime/2 + (float)Winking))
        if (ElapcedTime_Scared + sf::seconds(.5 * Winking) >= ScaredDuration )
        {
            AnimFram = static_cast<int>((TimeAsSecond / TimeAnime) * 4 ) % 4 ;
            GhostsSprite.setTextureRect
            (sf::IntRect((AnimFram * Size), 5 * Size , Size, Size));
        }
        else
        {
            AnimFram = static_cast<int>((TimeAsSecond / TimeAnime) * 2 ) % 2 ;
            GhostsSprite.setTextureRect
            (sf::IntRect((AnimFram * Size), 5 * Size , Size, Size));

        }
       
        if (ElapcedTime_Scared >= ScaredDuration)
        {
            ElapcedTime_Scared = sf::seconds(0);
            current_state = None;
        }
    }
    else 
    {
        AnimFram = static_cast<int>((TimeAsSecond / TimeAnime) * FramNum ) % FramNum ;
        GhostsSprite.setTextureRect
        (sf::IntRect((AnimFram * Size) + (Direction * Size * 2), color * Size , Size, Size));

    }

    GhostsSprite.setPosition(Pos_X, Pos_Y);
    window.draw(GhostsSprite);
  
}// End function Drow


void Ghosts::DirectionRandom(std::array<bool, 4> & walls)
{
    //walls[0] -> G_Right
    //walls[1] -> G_Up
    //walls[2] -> G_Left
    //walls[3] -> G_Down
    
    int num = 0;
   // srand(time(0));
    int random;
    // Determine the number of free paths
    for (int i = 0; i < 4; i++) 
    {
        if (!walls[i])
        {
            num++;
        }
    }
    if (num == 4)
    {
        random = rand() % 3;
        if (Direction == G_Right)//result should not be G_Left(2)
        {
            if (random == 0){
                Direction = G_Right;
            }
            else if (random == 1){
                Direction = G_Down;
            }
            else if (random == 2){
                Direction = G_Up;
            }
        }
        else if (Direction == G_Down)//result should not be G_Up(3)
        {
            if (random == 0){
                Direction = G_Down;
            }
            else if (random == 1){
                Direction = G_Right;
            }
            else if (random == 2){
                Direction = G_Left;
            }
            
        }
        else if (Direction == G_Left)//result should not be G_Right(0)
        {
            if (random == 0){
                Direction = G_Left;
            }
            else if (random == 1){
                Direction = G_Up;
            }
            else if(random == 2){
                Direction = G_Down;
            }
        }
        else if (Direction == G_Up)//result should not be G_Down(1)
        {
            if (random == 0){
                Direction = G_Up;
            }
            else if (random == 1){
                Direction = G_Right;
            }
            else if (random == 2){
                Direction = G_Left;
            }  
        }
    }// End if num 4
    else if (num == 3)
    {
        random = rand() % 2;
        // دو شرط پیش رو بر اساس اشتراک بین مسیر های راست و چپ میباشد
        // توضیحات دقیق تر در گزارش کار
        if ( ((Direction == G_Right) && walls[G_Right]) || ((Direction == G_Left) && walls[G_Left]) )
        {
            if (random == 0){
                Direction = G_Down;
            }
            else if (random == 1){
                Direction = G_Up;
            }
        }
        else if ( ((Direction == G_Down) && walls[G_Down]) || ((Direction == G_Up) && walls[G_Up]) )
        {
            if (random == 0){
                Direction = G_Right;
            }
            else if (random == 1){
                Direction = G_Left;
            }
        }
        ///////////////////////////////////////////////////
        // چهار شرط پیش رو بر اساس اشتراک بین مسیر های راست با پایین یا بالا همچنین چپ با پایین یا بالا است
        // توضیحات دقیق تر در گزارش کار
        else if ( ((Direction == G_Right) && walls[G_Up]) || ((Direction == G_Down) && walls[G_Left]) )
        {
            if (random == 0){
                Direction = G_Right;
            }
            else if (random == 1){
                Direction = G_Down;
            }
        }

        else if ( ((Direction == G_Right) && walls[G_Down]) || ((Direction == G_Up) && walls[G_Left]))
        {
            if (random == 0){
                Direction = G_Right;
            }
            else if (random == 1){
                Direction = G_Up;
            }
        }

        else if ( ((Direction == G_Left) && walls[G_Up]) || ((Direction == G_Down) && walls[G_Right]))
        {
            if (random == 0){
                Direction = G_Left;
            }
            else if (random == 1){
                Direction = G_Down;
            }
        }

       else if ( ((Direction == G_Left) && walls[G_Down]) || ((Direction == G_Up) && walls[G_Right]))
        {
            if (random == 0){
                Direction = G_Left;
            }
            else if (random == 1){
                Direction = G_Up;
            }
        }
    }// End if num 3
    else if (num == 2)
    {
        if (((Direction == G_Right) || (Direction == G_Down) || (Direction == G_Up)) && !walls[G_Right])
        {
            Direction = G_Right;
        }

        else if (((Direction == G_Right) || (Direction == G_Up) || (Direction == G_Left)) && !walls[G_Up])
        {
            Direction = G_Up;
        }

        else if (((Direction == G_Right) || (Direction == G_Down) || (Direction == G_Left)) && !walls[G_Down])
        {
            Direction = G_Down;
        }

        else if (((Direction == G_Left) || (Direction == G_Down) || (Direction == G_Up)) && !walls[G_Left])
        {
            Direction = G_Left;
        }
    }
    else if (num == 1) // this if is just for house of ghosts
    {
        if (Direction == G_Right){
            Direction = G_Left;
        }
        else if (Direction == G_Down){
            Direction = G_Up;
        }
        else if (Direction == G_Left){
            Direction = G_Right;
        }
        else if (Direction == G_Up){
            Direction = G_Down;
        }
                
    }// End if num 1
  
}// End function Determine
/*
هدف تابع زیر ؟
هدف تابع تنظیم درست جهت ارواح برای تعقیب و شکار پک من است
x --- is position x of pacman
y --- is position y pacman
*/
void Ghosts::DirectionChaser(std::array<bool, 4> & walls, float x, float y)
{
    if (house && !Get_FrightenedGhosts())
    {
        if (!walls[G_Up])
        {
            Direction = G_Up;
        }
        else if (walls[G_Right])
        {
            Direction = G_Left;
        }
        else if (walls[G_Left])
        {
            Direction = G_Right;
        }
    }
    else if ((Direction == G_Right) || (Direction == G_Left))
    {
        if (Pos_Y > y)
        {
            if (!walls[G_Up])
            {
                Direction = G_Up;
            }
            else if (walls[Direction] && !walls[G_Down])
            {
                Direction = G_Down;
            }
           
        }
        else if (Pos_Y < y)
        {
            if (!walls[G_Down])
            {
                Direction = G_Down;
            }
            else if (walls[Direction] && !walls[G_Up])
            {
                Direction = G_Up;
            }
        }
        else if (Pos_Y == y)
        {
            if ( ((Direction == G_Right) && ((x < Pos_X) || walls[G_Right])) || 
                 ( (Direction == G_Left) && ((x > Pos_X) || walls[G_Left]) ) )
            {
                if (!walls[G_Up])
                {
                    Direction = G_Up;
                }
                else if (!walls[G_Down])
                {
                    Direction = G_Down;
                }
            }
            
        }

    }
    else if ((Direction == G_Up) || (Direction == G_Down))
    {
        if (Pos_X > x)
        {
            if (!walls[G_Left])
            {
                Direction = G_Left;
            }
            else if (walls[Direction] && !walls[G_Right])
            {
                Direction = G_Right;
            }
           
        }
        else if (Pos_X < x)
        {
            if (!walls[G_Right])
            {
                Direction = G_Right;
            }
            else if (walls[Direction] && !walls[G_Left])
            {
                Direction = G_Left;
            }
           
        }
        else if (Pos_X == x)
        {
            if ( ((Direction == G_Down)&&(Pos_Y > y || walls[G_Down])) || 
                 ((Direction == G_Up)&&(y > Pos_Y || walls[G_Up])))
            {
                if (!walls[G_Right])
                {
                    Direction = G_Right;
                }
                else if (!walls[G_Left])
                {
                    Direction = G_Left;
                }
            }
        }
    }
}// End function DirectionChaser