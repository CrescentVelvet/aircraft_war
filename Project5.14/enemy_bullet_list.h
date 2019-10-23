#ifndef _ENEMY_BULLET_LIST
#define _ENEMY_BULLET_LIST
#include "bullet_list_box.h"

class enemy_bullet_list : public bullet_list
{
public:
    enemy_bullet_list();
    ~enemy_bullet_list();
    //改变xy使得子弹纵向移动
    void enemy_bullet1(int i);
    //改变xy使得子弹斜向移动
    void enemy_bullet2(int i);
    void enemy_bullet3(int i);
};

#endif // !_ENEMY_BULLET_LIST