#include "game_window.h"
#include "my_bullet_draw.h"

my_bullet_draw::my_bullet_draw(int number)
{
    int length = number;
    bullet = new Fl_Box*[length];
    for (int i = 0; i < length; i++)
    {
        bullet[i] = new Fl_Box(0, 0, 10, 10);
        bullet[i]->color(FL_WRITE);
        bullet[i]->box(FL_OFLAT_BOX);
    }
}

my_bullet_draw::~my_bullet_draw()
{
}

void my_bullet_draw::my_bullet_drawing(my_bullet_list my_bullet_pos)
{
    int x, y, dre;
    for (int i = 0; i < my_bullet_pos.length(); i++)
    {
        if (i >= my_bullet_pos.length() || i < 0) { std::cout << "数组越界！" << std::endl; break; }
        if (50 <= my_bullet_pos.length()) { std::cout << "数组太长!" << std::endl; break; }
        x = my_bullet_pos.getX(i);
        y = my_bullet_pos.getY(i);
        dre = my_bullet_pos.getDre(i);
        if (x == 0 && y == 0) { continue; }
        bullet[i]->color(FL_GREEN);
        bullet[i]->hide();
        bullet[i]->position(x, y);
        bullet[i]->redraw();
        bullet[i]->show();
    }
}

void my_bullet_draw::my_bullet_collision(my_bullet_list my_bullet_pos, enemy_flyer *enemy_n)
{
    int x, y, dre;
    int x_enemy, y_enemy;
    x_enemy = enemy_n->x();
    y_enemy = enemy_n->y();
    for (int i = 0; i < my_bullet_pos.length(); i++)
    {
        x = my_bullet_pos.getX(i);
        y = my_bullet_pos.getY(i);
        dre = my_bullet_pos.getDre(i);
        if (x == 0 && y == 0) { continue; }
        if ((x_enemy - 5) < x && (x_enemy + 25) > x && (y_enemy - 5) < y && (y_enemy + 25) > y)
        {
            enemy_n->fight_flag = 1;//传递flag=1到敌机类中，再使用敌机运动函数（运动函数包括对flag的判断以及随机调用flyer类中的move函数）
            break;
        }
    }
}