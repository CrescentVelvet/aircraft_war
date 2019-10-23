#include "bullet_list_box.h"

bullet_list::bullet_list()
{
}
bullet_list::~bullet_list()
{
}
void bullet_list::pushX(int x)
{
    listX.push_back(x);
}
void bullet_list::pushY(int y)
{
    listY.push_back(y);
}
void bullet_list::pushDre(int dre)
{
    listDre.push_back(dre);
}
int bullet_list::getX(int i)
{
    int x;
    x = listX[i];
    return x;
}
int bullet_list::getY(int i)
{
    int y;
    y = listY[i];
    return y;
}
int bullet_list::getDre(int i)
{
    int dre;
    dre = listDre[i];
    return dre;
}
void bullet_list::dele(int i)
{
    /*swap(begin(listX) + 1, end(listX) - 1);
    listX.pop_back();
    swap(begin(listY) + 1, end(listY) - 1);
    listY.pop_back();
    swap(begin(listDre) + 1, end(listDre) - 1);
    listDre.pop_back();*/
    listX.pop_front();
    listY.pop_front();
    listDre.pop_front();
}
int bullet_list::length()
{
    size_t n;
    n = listX.size();
    return n;
}
bool bullet_list::isEmpty()
{
    bool t;
    t = listX.empty();
    return t;
}