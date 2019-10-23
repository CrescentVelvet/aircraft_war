#include "flyer_box.h"

flyer::flyer(int x, int y, int w, int h, const char *data = 0) : Fl_Box(x, y, w, h, data)
{
    this->box(FL_FLAT_BOX);
    this->color(FL_GREEN);
}

flyer::~flyer() 
{
}

void flyer::move_font(int i)
{
    int x, y, w, h;
    this->hide();
    x = this->x();
    y = this->y();
    w = this->w();
    h = this->h();
    this->resize(x, y - i, w, h);
    this->redraw();
    this->show();
}

void flyer::move_back(int i)
{
    int x, y, w, h;
    this->hide();
    x = this->x();
    y = this->y();
    w = this->w();
    h = this->h();
    this->resize(x, y + i, w, h);
    this->redraw();
    this->show();
}

void flyer::move_left(int i)
{
    int x, y, w, h;
    this->hide();
    x = this->x();
    y = this->y();
    w = this->w();
    h = this->h();
    this->resize(x - i, y, w, h);
    this->redraw();
    this->show();
}

void flyer::move_right(int i)
{
    int x, y, w, h;
    this->hide();
    x = this->x();
    y = this->y();
    w = this->w();
    h = this->h();
    this->resize(x + i, y, w, h);
    this->redraw();
    this->show();
}