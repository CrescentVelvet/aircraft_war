#ifndef _MY_FLYER_BOX_H
#define _MY_FLYER_BOX_H
#include "flyer_box.h"

class my_flyer : public flyer
{
public:
    my_flyer(int x, int y, int w, int h, const char *data);
    ~my_flyer();
    int fight_flag = 0;
};

#endif // !_MY_FLYER_BOX_H

