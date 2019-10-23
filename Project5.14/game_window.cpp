#include "game_window.h"
#define DEFAULT_JPEG_FILE_PATH "..\..\JPEG\monai.JPG"

my_bullet_list game_window::my_bullet_pos;
enemy_bullet_list game_window::enemy_1_bullet_1_pos;
enemy_bullet_list game_window::enemy_1_bullet_2_pos;
enemy_bullet_list game_window::enemy_1_bullet_3_pos;
enemy_bullet_list game_window::enemy_2_bullet_1_pos;
enemy_bullet_list game_window::enemy_2_bullet_2_pos;
enemy_bullet_list game_window::enemy_2_bullet_3_pos;
enemy_bullet_list game_window::enemy_3_bullet_1_pos;
enemy_bullet_list game_window::enemy_3_bullet_2_pos;
enemy_bullet_list game_window::enemy_3_bullet_3_pos;
int game_window::flyer_dre = 0;
int game_window::bullet_dre = 0;
int game_window::use_time = 0;
int game_window::btn_event = 0;
int game_window::game_score = 100;
bool game_window::bullet_flag = FALSE;
//Fl_Image* game_window::jpeg_image;
std::ofstream game_window::outfile;

game_window::game_window(int w, int h, const char *title) : Fl_Double_Window(w, h, title)
{
    //main_window = new Fl_Double_Window(w, h, title);
    this->begin();
    game_box1 = new game_box(10, 10, 650, 450, 0);
    //子弹
    my_bullet = new my_bullet_draw(100);
    //飞机
    my_flyer1 = new my_flyer(320, 430, 20, 20, 0);
    fl_register_images();
    jpeg_flyer_box = Fl_Shared_Image::get("JPEG/myflyer.jpeg");
    jpeg_my_flyer = jpeg_flyer_box->copy(my_flyer1->w(), my_flyer1->h());
    my_flyer1->image(jpeg_my_flyer);

    enemy_1 = new enemy_flyer(100, 100, 20, 20, 0);
    fl_register_images();
    jpeg_flyer_box = Fl_Shared_Image::get("JPEG/enemy1.jpeg");
    jpeg_enemy1 = jpeg_flyer_box->copy(enemy_1->w(), enemy_1->h());
    enemy_1->image(jpeg_enemy1);

    enemy_2 = new enemy_flyer(320, 100, 20, 20, 0);
    fl_register_images();
    jpeg_flyer_box = Fl_Shared_Image::get("JPEG/enemy2.jpeg");
    jpeg_enemy2 = jpeg_flyer_box->copy(enemy_2->w(), enemy_2->h());
    enemy_2->image(jpeg_enemy2);

    enemy_3 = new enemy_flyer(540, 100, 20, 20, 0);
    fl_register_images();
    jpeg_flyer_box = Fl_Shared_Image::get("JPEG/enemy3.jpeg");
    jpeg_enemy3 = jpeg_flyer_box->copy(enemy_3->w(), enemy_3->h());
    enemy_3->image(jpeg_enemy3);

    //文字栏设置区域
    text_buff = new Fl_Text_Buffer();
    text_dis = new Fl_Text_Display(670, 70, 100, 100, "得分表");
    text_dis->buffer(text_buff);

    //敌机子弹，绘画太耗资源
    enemy_1_bullet_1 = new enemy_bullet_draw(100);
    enemy_1_bullet_2 = new enemy_bullet_draw(100);
    enemy_1_bullet_3 = new enemy_bullet_draw(100);
    enemy_2_bullet_1 = new enemy_bullet_draw(100);
    enemy_2_bullet_2 = new enemy_bullet_draw(100);
    enemy_2_bullet_3 = new enemy_bullet_draw(100);
    enemy_3_bullet_1 = new enemy_bullet_draw(100);
    enemy_3_bullet_2 = new enemy_bullet_draw(100);
    enemy_3_bullet_3 = new enemy_bullet_draw(100);
    //界面按钮设置区域
    main_menu_bar = new Fl_Menu_Bar(0, 0, 800, 25);
    btn_start = new color_button(670, 300, 50, 40, "@+2|>");
    btn_stop = new color_button(720, 300, 50, 40, "@||");
    btn_font = new color_button(700, 345, 40, 45, "@+48->");
    btn_back = new color_button(700, 390, 40, 45, "@+42->");
    btn_left = new color_button(670, 345, 30, 90, "@+4<-");
    btn_right = new color_button(740, 345, 30, 90, "@+4->");
    btn_close = new color_button(670, 440, 100, 40, "QUIT");
    //菜单栏设置区域
    main_menu_bar->add("@fileopen/Open", "^o", main_menu_cb, this);
    main_menu_bar->add("@fileopen/Quit", "^q", main_menu_cb, this);
    main_menu_bar->add("@filesave/Save", "^r", main_menu_cb, this);
    main_menu_bar->add("@filesave/Help", "^h", main_menu_cb, this);
    main_menu_bar->add("@filesaveas/Start", "^x", main_menu_cb, this);
    main_menu_bar->add("@filesaveas/Stop", "^z", main_menu_cb, this);
    main_menu_bar->add("@filesaveas/Font", "^w", main_menu_cb, this);
    main_menu_bar->add("@filesaveas/Back", "^s", main_menu_cb, this);
    main_menu_bar->add("@filesaveas/Left", "^a", main_menu_cb, this);
    main_menu_bar->add("@filesaveas/Right", "^d", main_menu_cb, this);
    //读取图片显示窗口
    jpeg_image_box = new Fl_Box(670, 180, 100, 100);
    jpeg_image = nullptr;
    jpeg_image_box->box(FL_UP_BOX);
    jpeg_image_box->color(FL_GRAY);
    fl_register_images();
    jpeg_image_orig = Fl_Shared_Image::get("JPEG/monai.jpeg");
    jpeg_image = jpeg_image_orig->copy(jpeg_image_box->w(), jpeg_image_box->h());
    jpeg_image_box->image(jpeg_image);
    //回调函数设置区域
    btn_start->callback((Fl_Callback*)btn_start_cb, this);
    btn_stop->callback((Fl_Callback*)btn_stop_cb, this);
    btn_font->callback((Fl_Callback*)btn_font_cb, this);
    btn_back->callback((Fl_Callback*)btn_back_cb, this);
    btn_left->callback((Fl_Callback*)btn_left_cb, this);
    btn_right->callback((Fl_Callback*)btn_right_cb, this);
    btn_close->callback((Fl_Callback*)btn_close_cb);
    btn_start->shortcut('o');
    btn_font->shortcut('w');
    btn_back->shortcut('s');
    btn_left->shortcut('a');
    btn_right->shortcut('d');
    btn_close->shortcut(FL_CTRL + 'q');
    //窗口结束
    this->end();
    this->resizable(this);
    Fl::visual(FL_RGB);
    Fl::visual(FL_DOUBLE | FL_INDEX);
    this->show();
}

game_window::~game_window() 
{
}

void game_window::btn_start_cb(Fl_Widget *w, void *data)
{
    btn_event = 5;
}

void game_window::btn_stop_cb(Fl_Widget *w, void *data)
{
    btn_event = 9;
}

void game_window::btn_font_cb(Fl_Widget *w, void *data)
{
    btn_event = 8;
    flyer_dre = 8;
}

void game_window::btn_back_cb(Fl_Widget *w, void *data)
{
    btn_event = 2;
    flyer_dre = 2;
}

void game_window::btn_left_cb(Fl_Widget *w, void *data)
{
    btn_event = 4;
    flyer_dre = 4;
}

void game_window::btn_right_cb(Fl_Widget *w, void *data)
{
    btn_event = 6;
    flyer_dre = 6;
}

void game_window::btn_close_cb(Fl_Widget *w, void *data)
{
    exit(0);
}

void game_window::main_menu_cb(Fl_Widget *w, void *data)
{
    Fl_Menu_Bar *my_bar = (Fl_Menu_Bar*)w;
    const Fl_Menu_Item *item = my_bar->mvalue();

    char ipath[256]; my_bar->item_pathname(ipath, sizeof(ipath));

    //fprintf(stderr, "callback: You picked '%s'", item->label());
    //fprintf(stderr, ", item_pathname() is '%s'", ipath);
    //fprintf(stderr, "\n");

    if (strcmp(item->label(), "Open") == 0)
    {
        ((game_window*)data)->jpeg_show_cb(w, data);
    }
    if (strcmp(item->label(), "Start") == 0)
    {
        ((game_window*)data)->btn_start_cb(w, data);
    }
    if (strcmp(item->label(), "Stop") == 0)
    {
        ((game_window*)data)->btn_stop_cb(w, data);
    }
    if (strcmp(item->label(), "Font") == 0)
    {
        ((game_window*)data)->btn_font_cb(w, data);
    }
    if (strcmp(item->label(), "Back") == 0)
    {
        ((game_window*)data)->btn_back_cb(w, data);
    }
    if (strcmp(item->label(), "Left") == 0)
    {
        ((game_window*)data)->btn_left_cb(w, data);
    }
    if (strcmp(item->label(), "Right") == 0)
    {
        ((game_window*)data)->btn_right_cb(w, data);
    }
    if (strcmp(item->label(), "Quit") == 0) 
    {
        exit(0); 
    }
    if (strcmp(item->label(), "Save") == 0)
    {
        int length = 100 - ((game_window*)data)->my_bullet_pos.length();
        int score = ((game_window*)data)->game_score;
        ((game_window*)data)->outfile.open("my_game_score.txt");
        ((game_window*)data)->outfile << "<------飞机大战------>" << std::endl;
        ((game_window*)data)->outfile << "剩余子弹数：" << length << std::endl;
        ((game_window*)data)->outfile << "游戏得分：  " << score << std::endl;
        ((game_window*)data)->outfile.close();
    }
    if (strcmp(item->label(), "Help") == 0)
    {
        ((game_window*)data)->help_show_cb(w, "HELP");
    }
}

void game_window::help_show_cb(Fl_Widget *w, void *data)
{
    ((Fl_Button*)w)->label((char*)data);
    fl_choice("屏幕左半为游戏界面，你可以在这个界面里进攻敌方飞机\n\
屏幕右上为游戏状态，显示您剩余的子弹数与剩余生命数。\n\
游戏开始阶段您一共有100发子弹与100条生命。\n\
屏幕右中为玩家头像，您可以在菜单栏中的Open打开图片修改头像。\n\
屏幕右下为控制按键，与菜单栏按键一样，\n\
Save存储游戏得分，Quit退出游戏，Open修改玩家头像。\n\
Start开始游戏并控制玩家飞机发射子弹，Stop暂停游戏，\n\
Font控制玩家飞机前进，Back控制玩家飞机后退，\n\
Left控制玩家飞机左移，Right控制玩家飞机右移\n\
祝您游戏愉快！", "听上去很好玩的样子！", "那就开始游戏吧！", 0);
}

void game_window::jpeg_show_cb(Fl_Widget *w, void *data)
{
    ((game_window*)data)->click_btn_show_jpeg(w, data);
}

void game_window::click_btn_show_jpeg(Fl_Widget *w, void *data)
{
    Fl_Native_File_Chooser file_chooser;
    file_chooser.directory(nullptr);
    file_chooser.title("Pick a file");
    file_chooser.type(Fl_Native_File_Chooser::BROWSE_FILE);
    const char* file_path = DEFAULT_JPEG_FILE_PATH;
    std::cout << file_path << std::endl;
    switch (file_chooser.show())
    {
    case -1:
        std::cout << "Error in Fl_Native_File_Chooser::show()" << std::endl;
        std::cout << file_chooser.errmsg();
        return;
    case 1:
        std::cout << "User cancelled the file selection dialog" << std::endl;
        return;
    default:
        file_path = file_chooser.filename();
        std::cout << file_path << std::endl;
        break;
    }
    fl_register_images();
    jpeg_image_orig = Fl_Shared_Image::get(file_path);
    if (jpeg_image) { delete jpeg_image; std::cout << "---" << std::endl; }
    jpeg_image = jpeg_image_orig->copy(jpeg_image_box->w(), jpeg_image_box->h());
    jpeg_image_box->image(jpeg_image);
    jpeg_image_box->redraw();
}