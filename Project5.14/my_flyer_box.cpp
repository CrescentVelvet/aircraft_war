#include "my_flyer_box.h"

my_flyer::my_flyer(int x, int y, int w, int h, const char *data = 0) : flyer(x, y, w, h, data)
{
    this->box(FL_FLAT_BOX);
    this->color(FL_GREEN);
}

my_flyer::~my_flyer() {}