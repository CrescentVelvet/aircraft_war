#include "game_window.h"
#include "bullet_draw_box.h"

bullet_draw::bullet_draw()
{
    int length = 1;
    bullet = new Fl_Box*[length];
    bullet[0] = new Fl_Box(0, 0, 10, 10);
}
bullet_draw::bullet_draw(int number)
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
bullet_draw::~bullet_draw()
{
}