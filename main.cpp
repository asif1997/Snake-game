#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void setup()
{
	gameOver=false;
	dir = STOP;
	x=width/2;
	y=height/2;
	fruitX=rand()%width;
	fruitY=rand()%height;
	score=0;
}
void Draw()
{
	system("cls");
	for (int i=0;i<width;i++)
	{
		cout<<"#";
	}
	cout<<endl;

	for (int i=0;i<height;i++)
	{
		for (int j=0;j<width;j++)
		{
			if (j==0||j==width-1)
			{
				cout<<"#";
			}
			if (i==y&&j==x)
            {
                cout<<"0";
            }
            else if (i==fruitX&&j==fruitY)
            {
                cout<<"F";
            }
			else
			{
				cout<<" ";
			}

		}
		cout<<endl;
	}
	for (int i=0;i<width;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	cout<<fruitX<<" "<<fruitY<<endl;
	cout<<x<<" "<<y<<endl;
	cout<<"Score:"<<score<<endl;
}
void Input()
{
    if (_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir=LEFT;
            break;
        case 'd':
            dir=RIGHT;
            break;
        case 'w':
            dir=UP;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'x':
            gameOver=true;
        }
    }
}
void Logic()
{
    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x>width || x<0||y>height||y<0)
    {
        gameOver=true;
    }
    if (x==fruitY && y==fruitX)
    {
        score+=10;
        fruitX=rand()%width;
        fruitY=rand()%height;

    }
}
int main()
{
	setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
//		sleep(10);

	}
	return 0;
}
