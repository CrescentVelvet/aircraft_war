#include "color_button.h"

color_button::color_button(int x, int y, int w, int h, const char*data) : Fl_Button(x, y, w, h, data)
{
    this->labelsize(20);
    this->labelcolor(FL_BLACK);
    this->labeltype(FL_ENGRAVED_LABEL);
}

color_button::~color_button()
{
}