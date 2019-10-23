#include "enemy_bullet_list.h"

enemy_bullet_list::enemy_bullet_list()
{
}

enemy_bullet_list::~enemy_bullet_list()
{
}

void enemy_bullet_list::enemy_bullet1(int i)
{
    int x = listX[i];
    int y = listY[i];
    if (10 < x && 650 > x && 10 < y && 450 > y)
    {
        y = y + 2;
        listX[i] = x;
        listY[i] = y;
    }
    else
    {
        listX[i] = 0;
        listY[i] = 0;
    }
}

void enemy_bullet_list::enemy_bullet2(int i)
{
    int x = listX[i];
    int y = listY[i];
    if (10 < x && 650 > x && 10 < y && 450 > y)
    {
        x = x - 2;
        y = y + 2;
        listX[i] = x;
        listY[i] = y;
    }
    else
    {
        listX[i] = 0;
        listY[i] = 0;
    }
    
}

void enemy_bullet_list::enemy_bullet3(int i)
{
    int x = listX[i];
    int y = listY[i];
    if (10 < x && 650 > x && 10 < y && 450 > y)
    {
        x = x + 2;
        y = y + 2;
        listX[i] = x;
        listY[i] = y;
    }
    else
    {
        listX[i] = 0;
        listY[i] = 0;
    }
}