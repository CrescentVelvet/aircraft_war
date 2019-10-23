#include "game_box.h"

game_box::game_box(int x, int y, int w, int h, const char *data = 0) : Fl_Box(x, y, w, h, data)
{
    this->box(FL_UP_BOX);
    this->color(FL_BLACK);
}
game_box::~game_box()
{
}