#include<iostream>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include <ctime>

#define PI 3.14159265

using namespace std;

void point(int x,int y,int r)
{
    int i;
    setcolor(11);
    for(i=1;i<=r;i++)
        circle(x,y,i);
}

void dline(float x,float y,int r)
{
    line(200,170,200+y*r,170-x*r);
}

int main()
{
    int gd,gm;
    gd=DETECT;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    setcolor(14);
    circle(200,170,100);circle(200,170,99);circle(200,170,101);
    int i,x,y;
    float h,m,s;
    point(200,170,3);
    for(i=0;i<360;i+=30)
    {
        x=200+cos(i*PI/180)*90;
        y=170-sin(i*PI/180)*90;
        point(x,y,3);
    }
    while(!kbhit())
    {
        point(200,170,3);
        time_t now = time(0);
        tm *ltm = localtime(&now);
        s=ltm->tm_sec*6;
        m=(ltm->tm_min+ltm->tm_sec/60.0)*6;
        h=(ltm->tm_hour%12+m/360.0)*30;
        //cout<<endl<<s<<endl<<m<<endl<<h<<endl;
        setcolor(12);dline(cos(s*PI/180),sin(s*PI/180),83);
        setcolor(13);dline(cos(m*PI/180),sin(m*PI/180),63);
        setcolor(9);dline(cos(h*PI/180),sin(h*PI/180),33);
        delay(800);
        setcolor(0);
        dline(cos(s*PI/180),sin(s*PI/180),83);
        dline(cos(m*PI/180),sin(m*PI/180),63);
        dline(cos(h*PI/180),sin(h*PI/180),33);
    }
    return 0;
}

