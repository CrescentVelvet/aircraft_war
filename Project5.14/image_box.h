#ifndef _IMAGE_BOX_H
#define _IMAGE_BOX_H
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_JPEG_Image.H>

class image_box : public Fl_Box
{
public:
    image_box(int x, int y, int w, int h, const char *data);
    ~image_box();
    void show_image(Fl_PNG_Image *pic);
    void show_image(Fl_JPEG_Image *pic);
};

#endif // !_IMAGE_BOX_H

