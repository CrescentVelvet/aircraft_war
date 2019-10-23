#include "my_bullet_list.h"

my_bullet_list::my_bullet_list()
{
}

my_bullet_list::~my_bullet_list()
{
}

void my_bullet_list::change(int i)
{
    int x = listX[i];
    int y = listY[i];
    if (10 < x && 650 > x && 10 < y && 450 > y)
    {
        switch (listDre[i])
        {
        case 8:
            y = y - 2;
            break;
        case 2:
            y = y + 2;
            break;
        case 4:
            x = x - 2;
            break;
        case 6:
            x = x + 2;
            break;
        case 0:
            break;
        default:
            break;
        }
        listX[i] = x;
        listY[i] = y;
    }
    else
    {
        listX[i] = -1;
        listY[i] = -1;
        listDre[i] = 0;
    }
}