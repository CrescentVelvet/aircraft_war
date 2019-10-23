#include "image_box.h"

image_box::image_box(int x, int y, int w, int h, const char *data = 0) : Fl_Box(x, y, w, h, data)
{
    this->box(FL_FLAT_BOX);
    this->color(FL_GRAY);
}

image_box::~image_box() {}

void image_box::show_image(Fl_PNG_Image *pic)
{
    this->box(FL_UP_BOX);
    this->image(pic);
}

void image_box::show_image(Fl_JPEG_Image *pic)
{
    this->box(FL_UP_BOX);
    this->image(pic);
}