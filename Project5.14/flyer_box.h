#ifndef _FLYER_BOX_H
#define _FLYER_BOX_H
#include <FL/Fl_Box.H>

class flyer : public Fl_Box
{
public:
	flyer(int x, int y, int w, int h, const char *data);
	~flyer();
	void move_font(int i);
    void move_back(int i);
    void move_left(int i);
    void move_right(int i);
};

#endif // !_FLYER_BOX_H
