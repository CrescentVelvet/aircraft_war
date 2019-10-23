#ifndef _GAME_WINDOW_H
#define _GAME_WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <FL/Fl.H>
#include <iostream>
#include <fstream>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Text_Display.H>
#include "game_box.h"
#include "color_button.h"
#include "my_flyer_box.h"
#include "enemy_flyer_box.h"
#include "my_bullet_draw.h"
#include "my_bullet_list.h"
#include "enemy_bullet_draw.h"
#include "enemy_bullet_list.h"

class game_window : public Fl_Double_Window
{
public:
	static void btn_start_cb(Fl_Widget *w, void *data);
    static void btn_stop_cb(Fl_Widget *w, void *data);
	static void btn_font_cb(Fl_Widget *w, void *data);
	static void btn_back_cb(Fl_Widget *w, void *data);
	static void btn_left_cb(Fl_Widget *w, void *data);
	static void btn_right_cb(Fl_Widget *w, void *data);
	static void btn_close_cb(Fl_Widget *w, void *data);
	static void main_menu_cb(Fl_Widget *w, void *data);
    static void jpeg_show_cb(Fl_Widget *w, void *data);
    static void help_show_cb(Fl_Widget *w, void *data);
    void click_btn_show_jpeg(Fl_Widget *w, void *data);
	game_window(int w, int h, const char* title);
	~game_window();
    //Fl_Double_Window *main_window;
	Fl_Menu_Bar *main_menu_bar;
	Fl_Text_Buffer *text_buff;
	Fl_Text_Display *text_dis;
	color_button *btn_start;
	color_button *btn_stop;
	color_button *btn_font;
	color_button *btn_back;
	color_button *btn_left;
	color_button *btn_right;
	color_button *btn_close;
	game_box *game_box1;
    //飞机
	my_flyer *my_flyer1;
    enemy_flyer *enemy_1;
    enemy_flyer *enemy_2;
    enemy_flyer *enemy_3;
    //子弹
    my_bullet_draw *my_bullet;
    enemy_bullet_draw *enemy_1_bullet_1;
    enemy_bullet_draw *enemy_1_bullet_2;
    enemy_bullet_draw *enemy_1_bullet_3;
    enemy_bullet_draw *enemy_2_bullet_1;
    enemy_bullet_draw *enemy_2_bullet_2;
    enemy_bullet_draw *enemy_2_bullet_3;
    enemy_bullet_draw *enemy_3_bullet_1;
    enemy_bullet_draw *enemy_3_bullet_2;
    enemy_bullet_draw *enemy_3_bullet_3;
    //读取文件夹中图片
    Fl_Image *jpeg_image;
    Fl_Box *jpeg_image_box;
    Fl_Shared_Image *jpeg_image_orig;
    //给敌机我机添加图标
    Fl_Image *jpeg_my_flyer;
    Fl_Image *jpeg_enemy1;
    Fl_Image *jpeg_enemy2;
    Fl_Image *jpeg_enemy3;
    Fl_Shared_Image *jpeg_flyer_box;
    //保存游戏信息到文本
    static std::ofstream outfile;
    //静态变量
    static int bullet_dre;//用来向main函数传递子弹的方向，等于此刻飞机的方向，存储在my_bullet_pos中
    static my_bullet_list my_bullet_pos;//用来存储子弹们的位置与方向，每次刷新都改变数组的数据，再交给draw绘制出来
    static enemy_bullet_list enemy_1_bullet_1_pos;
    static enemy_bullet_list enemy_1_bullet_2_pos;
    static enemy_bullet_list enemy_1_bullet_3_pos;
    static enemy_bullet_list enemy_2_bullet_1_pos;
    static enemy_bullet_list enemy_2_bullet_2_pos;
    static enemy_bullet_list enemy_2_bullet_3_pos;
    static enemy_bullet_list enemy_3_bullet_1_pos;
    static enemy_bullet_list enemy_3_bullet_2_pos;
    static enemy_bullet_list enemy_3_bullet_3_pos;
    static int flyer_dre;//用来向main函数传递方向键，按一次键就改变飞机的方向，然后清零
    static int use_time;//用来计数，每过0.05秒增加1
    static int btn_event;//用来向main函数传递方向键，目前除了start之外似乎没什么用，子弹方向可以由飞机方向得到
    static bool bullet_flag;//
    static int game_score;//用于游戏计分，被敌机击中减分
};
#endif // !_GAME_WINDOW_H
