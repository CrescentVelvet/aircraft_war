#ifndef _ENEMY_FLYER_BOX_H
#define _ENEMY_FLYER_BOX_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "flyer_box.h"
//t是生成随机数的种子，x是生成随机数的范围
#define random(x) (rand()%x)

class enemy_flyer : public flyer
{
public:
    enemy_flyer(int x, int y, int w, int h, const char *data);
    ~enemy_flyer();
    //爆炸显示函数，完成变红与缩小功能
    void fighten(int counter);
    //fight_flag为0时初始化，为-1时正常随机运动，为1时爆炸效果
    int fight_flag = 0;
    //move_counter为计数器，为初始化与爆炸各自维持50次刷新的时间
    int move_counter = 0;
    //运动函数，通过fight_flag判断切换三种运动方式
    void enemy_flyer_move(int type);
};

#endif // !_ENEMY_FLYER_BOX_H