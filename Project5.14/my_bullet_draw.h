#ifndef _MY_BULLET_DRAW
#define _MY_BULLET_DRAW
#include "bullet_draw_box.h"
#include "my_bullet_list.h"

class my_bullet_draw : public bullet_draw
{
public:
    //初始化mine_bullet_box数组
    my_bullet_draw(int number);
    ~my_bullet_draw();
    //输入一个pos数组，根据数组中的x，y绘制相应的box数组
    void my_bullet_drawing(my_bullet_list my_bullet_pos);
    //敌机碰撞检测
    void my_bullet_collision(my_bullet_list my_bullet_pos, enemy_flyer *enemy_n);
};

#endif // !MINE_BULLET_DRAW
