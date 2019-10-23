#ifndef _ENEMY_BULLET_DRAW
#define _ENEMY_BULLET_DRAW
#include <FL/Fl_Box.H>
#include "bullet_draw_box.h"
#include "enemy_bullet_list.h"

class enemy_bullet_draw : public bullet_draw
{
public:
    //初始化enemy_bullet_box数组
    enemy_bullet_draw(int number);
    ~enemy_bullet_draw();
    //输入一个pos数组，根据数组中的x，y绘制相应的box数组(这个和my_bullet_draw是一样的，只是改了下颜色)
    void enemy_bullet_drawing(enemy_bullet_list enemy_bullet_pos);
    //我机碰撞检测
    void enemy_bullet_collision(enemy_bullet_list enemy_bullet_pos, my_flyer *my_plane);
};

#endif // !_ENEMY_BULLET_BOX