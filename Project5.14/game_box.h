#ifndef _GAME_BOX_H
#define _GAME_BOX_H

#include <FL/Fl_Box.H>

class game_box : public Fl_Box
{
public:
	game_box(int x, int y, int w, int h, const char *data);
	~game_box();
};

#endif // !_GAME_BOX_H
