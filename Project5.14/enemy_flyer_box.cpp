#include "enemy_flyer_box.h"
#include <iostream>

enemy_flyer::enemy_flyer(int x, int y, int w, int h, const char *data = 0) : flyer(x, y, w, h, data)
{
    this->box(FL_FLAT_BOX);
    this->color(FL_YELLOW);
}
enemy_flyer::~enemy_flyer() 
{
}

void enemy_flyer::enemy_flyer_move(int type)
{
    //判断敌机飞到边境，就返回初始位置
    int x, y;
    x = this->x();
    y = this->y();
    if (x < 10 || x>640 || y < 20 || y>440)
    {
        //飞跃边境就初始化
        fight_flag = 2;
    }

    //通过取一个随机数的个位十位百位来实现同时生成三个随机数
    int temp_dre, temp_dre1, temp_dre2, temp_dre3;
    srand((unsigned)time(NULL));
    temp_dre = random(1000);
    temp_dre1 = (temp_dre / 100) % 4;
    temp_dre2 = ((temp_dre % 100 - temp_dre % 10) / 10) % 4;
    temp_dre3 = (temp_dre % 10) % 4;
    //三个敌机分别随机运动
    switch (type)
    {
    case 1:
        temp_dre = temp_dre1;
        break;
    case 2:
        temp_dre = temp_dre2;
        break;
    case 3:
        temp_dre = temp_dre3;
        break;
    default:
        break;
    }

    switch (fight_flag)
    {
    case 0:
        //fight_flag为0时执行前进操作(100次）
        this->move_back(1);
        move_counter++;
        if (move_counter == 100)
        {
            //前进100次就随机运动
            fight_flag = -1;
            move_counter = 0;
        }
        break;
    case -1:
        //fight_flag为-1时执行随机方向运动操作(100次）
        move_counter++;
        //随机数决定是朝前后左右哪个方向移动
        //std::cout << temp_dre << std::endl;
        switch (temp_dre)
        {
        case 0:
            this->move_font(1);
            break;
        case 1:
            this->move_back(1);
            break;
        case 2:
            this->move_left(1);
            break;
        case 3:
            this->move_right(1);
            break;
        default:
            break;
        }
        if (move_counter == 100)
        {
            //随机运动100次就前进
            move_counter = 0;
        }
        break;
    case 1:
        //fight_flag为1时执行被击中后的爆炸操作与十秒后再度初始化（100次）
        move_counter++;
        this->fighten(move_counter);
        if (move_counter == 100)
        {
            //爆炸后就初始化
            fight_flag = 2;
            move_counter = 0;
        }
        break;
    //fight_flag为2时执行回到初始位置操作
    case 2:
        temp_dre = random(340);
        this->resize(temp_dre - 50, 20, 20, 20);
        this->color(FL_YELLOW);
        //初始化后前进
        fight_flag = 0;
        move_counter = 0;
        break;
    default:
        break;
    }
}

void enemy_flyer::fighten(int counter)
{
    int x, y, w, h;
    int count_flag;
    //每隔10次膨胀一点
    if (counter%10 == 0) { count_flag = 1; }
    else { count_flag = 0; }
    this->hide();
    x = this->x();
    y = this->y();
    w = this->w();
    h = this->h();
    this->resize(x, y, w + count_flag, h + count_flag);
    this->color(FL_RED);
    this->redraw();
    this->show();
}