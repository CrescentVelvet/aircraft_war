#ifndef _BULLET_DRAW_BOX
#define _BULLET_DRAW_BOX
#include <FL/Fl_Box.H>

class bullet_draw
{
public:
    //初始化box数组
    bullet_draw();
    bullet_draw(int number);
    ~bullet_draw();    
    Fl_Box **bullet;
};
#endif // !_BULLET_DRAW_BOX