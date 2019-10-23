#include "game_window.h"
#include "bullet_list_box.h"
#include "enemy_bullet_draw.h"

enemy_bullet_draw::enemy_bullet_draw(int number)
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

enemy_bullet_draw::~enemy_bullet_draw()
{
}

void enemy_bullet_draw::enemy_bullet_drawing(enemy_bullet_list enemy_bullet_pos)
{
    int x, y;
    for (int i = 0; i < enemy_bullet_pos.length(); i++)
    {
        x = enemy_bullet_pos.getX(i);
        y = enemy_bullet_pos.getY(i);
        bullet[i]->color(FL_YELLOW);
        bullet[i]->hide();
        bullet[i]->position(x, y);
        bullet[i]->redraw();
        bullet[i]->show();
    }
}

void enemy_bullet_draw::enemy_bullet_collision(enemy_bullet_list enemy_bullet_pos, my_flyer *my_plane)
{
    int x, y;
    int x_my, y_my;
    x_my = my_plane->x();
    y_my = my_plane->y();
    for (int i = 0; i < enemy_bullet_pos.length(); i++)
    {
        x = enemy_bullet_pos.getX(i);
        y = enemy_bullet_pos.getY(i);
        if (x == 0 && y == 0) { continue; }
        if ((x_my - 5) < x && (x_my + 25) > x && (y_my - 5) < y && (y_my + 25) > y)
        {
            my_plane->fight_flag = 1;//传递flag=1到我机类中
            break;
        }
    }
}