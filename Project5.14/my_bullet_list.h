#ifndef _MY_BULLET_LIST
#define _MY_BULLET_LIST
#include "bullet_list_box.h"

class my_bullet_list : public bullet_list
{
public:
    my_bullet_list();
    ~my_bullet_list();
    //改变xy使得子弹向某个方向移动一格
    void change(int i);
};

#endif // !_MINE_BULLET_LIST
