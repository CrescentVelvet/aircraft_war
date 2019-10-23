#ifndef _COLOR_BUTTON_H
#define _COLOR_BUTTON_H

#include <FL/Fl_Button.H>

class color_button : public Fl_Button
{
private:
	int handle(int e)
	{
		switch (e)
		{
		case FL_ENTER:
			color(FL_GREEN);
			labelsize(22);
			redraw();
			return 1;
		case FL_LEAVE:
			color(FL_GRAY);
			labelsize(20);
			redraw();
			return 1;
		default:
			return Fl_Button::handle(e);
		}
	}
public:
	color_button(int x, int y, int w, int h, const char*data);
    ~color_button();
};

#endif // !_COLOR_BUTTON_H
