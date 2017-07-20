#include<iostream>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include <ctime>

using namespace std;

void digit(int x1, int x2, int x3, int x4, int x5, int x6, int x7,int i)
{
    int j;
    j=150;
    if(x2==1) line(i,j,i+50,j);
    if(x1==1) line(i,j,i,j+50);
    if(x3==1) line(i+50,j,i+50,j+50);
    if(x4==1) line(i,j+50,i+50,j+50);
    if(x5==1) line(i,j+50,i,j+100);
    if(x6==1) line(i,j+100,i+50,j+100);
    if(x7==1) line(i+50,j+50,i+50,j+100);

}

void draw(int n,int x)
{
    switch(n)
    {
        case 0: digit(1,1,1,0,1,1,1,x); break;
        case 1: digit(0,0,1,0,0,0,1,x);break;
        case 2: digit(0,1,1,1,1,1,0,x);break;
        case 3: digit(0,1,1,1,0,1,1,x);break;
        case 4: digit(1,0,1,1,0,0,1,x);break;
        case 5: digit(1,1,0,1,0,1,1,x);break;
        case 6: digit(1,1,0,1,1,1,1,x);break;
        case 7: digit(0,1,1,0,0,0,1,x);break;
        case 8: digit(1,1,1,1,1,1,1,x);break;
        case 9: digit(1,1,1,1,0,1,1,x);break;
    }
}

void setup()
{
    setcolor(3);
    rectangle(50,100,640,320);
    setcolor(7);
    rectangle(70,120,620,300);
}


int main()
{
    int gd,gm;
    gd=DETECT;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    setcolor(14);
    int i,x,y;
    int h,m,s;
    while(!kbhit())
    {
        cleardevice();
        setup();
        setcolor(15);
        time_t now = time(0);
        tm *ltm = localtime(&now);
        s=ltm->tm_sec;
        m=ltm->tm_min;
        h=ltm->tm_hour;
        //for hour
        draw(h/10,100);
        draw(h%10,170);

        bar(235,170,245,180);
        bar(235,220,245,230);

        //minutes
        draw(m/10,260);
        draw(m%10,330);

        bar(395,170,405,180);
        bar(395,220,405,230);

        //minutes
        draw(s/10,420);
        draw(s%10,490);

        delay(800);
    }
    return 0;
}
