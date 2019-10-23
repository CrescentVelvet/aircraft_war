#include "game_window.h"

void time_callback(void* game)
{
    game_window::use_time++;
    if (game_window::use_time > 200) { game_window::use_time = 0; }
    int x = 0;
    int y = 0;
    //start按键控制flyer子弹发射
    switch (((game_window*)game)->btn_event)
    {
    //按下start按钮，就会将飞机所在的x，y坐标与朝向读取出来并赋值给list数组
    case 5:
        x = ((game_window*)game)->my_flyer1->x();
        y = ((game_window*)game)->my_flyer1->y();
        if (((game_window*)game)->bullet_dre == 0)
        {
            ((game_window*)game)->bullet_dre = 8;
        }
        ((game_window*)game)->my_bullet_pos.pushX(x);
        ((game_window*)game)->my_bullet_pos.pushY(y);
        ((game_window*)game)->my_bullet_pos.pushDre(((game_window*)game)->bullet_dre);
        ((game_window*)game)->bullet_flag = TRUE;
        ((game_window*)game)->btn_event = 0;
        break;
    //暂停
    case 9:
        ((game_window*)game)->bullet_flag = FALSE;
        ((game_window*)game)->btn_event = 0;
        break;
    //前进
    case 8:
        ((game_window*)game)->bullet_dre = 8;
        ((game_window*)game)->btn_event = 0;
        break;
    //后退
    case 2:
        ((game_window*)game)->bullet_dre = 2;
        ((game_window*)game)->btn_event = 0;
        break;
    //左向行驶
    case 4:
        ((game_window*)game)->bullet_dre = 4;
        ((game_window*)game)->btn_event = 0;
        break;
    //右向行驶
    case 6:
        ((game_window*)game)->bullet_dre = 6;
        ((game_window*)game)->btn_event = 0;
        break;
    default:
        break;
    }
    //文本栏显示子弹数量与得分情况
    if (((game_window*)game) != NULL)
    {
        char str_length[40];
        int length = 100 - ((game_window*)game)->my_bullet_pos.length();
        char num_bullet[4];
        _itoa_s(length, num_bullet, 4, 10);
        char str_bullet[] = "Bullet:";
        for (int i = 0; i < 7; i++) { str_length[i] = str_bullet[i]; }
        for (int i = 7; i < 10; i++) { if (num_bullet[i - 7] == 0) { str_length[i] = ' '; } else { str_length[i] = num_bullet[i - 7]; } }
        int score = ((game_window*)game)->game_score;
        char num_score[4];
        _itoa_s(score, num_score, 4, 10);
        char str_score[] = "\nScore:";
        for (int i = 10; i < 17; i++) { str_length[i] = str_score[i - 10]; }
        for (int i = 17; i < 21; i++) { str_length[i] = num_score[i - 17]; }
        ((game_window*)game)->text_buff->text(str_length);
    }
    //绘制我的飞机flyer的子弹
    if (((game_window*)game) != NULL && ((game_window*)game)->bullet_flag == true)
    {
        //按照my_bullet_pos中的信息绘制my_bullet中的box
        ((game_window*)game)->my_bullet->my_bullet_drawing(((game_window*)game)->my_bullet_pos);
        //把my_bullet_pos中存储的所有坐标都按照方向移动一位
        for (int i = 0; i < ((game_window*)game)->my_bullet_pos.length(); i++)
        {
            ((game_window*)game)->my_bullet_pos.change(i);
        }
    }
    //方向键控制我的飞机flyer前后左右移动
    switch (((game_window*)game)->flyer_dre)
    {
    case 8:
        ((game_window*)game)->my_flyer1->move_font(5);
        ((game_window*)game)->bullet_dre = 8;
        ((game_window*)game)->flyer_dre = 0;
        break;
    case 2:
        ((game_window*)game)->my_flyer1->move_back(5);
        ((game_window*)game)->bullet_dre = 2;
        ((game_window*)game)->flyer_dre = 0;
        break;
    case 4:
        ((game_window*)game)->my_flyer1->move_left(5);
        ((game_window*)game)->bullet_dre = 4;
        ((game_window*)game)->flyer_dre = 0;
        break;
    case 6:
        ((game_window*)game)->my_flyer1->move_right(5);
        ((game_window*)game)->bullet_dre = 6;
        ((game_window*)game)->flyer_dre = 0;
        break;
    default:
        break;
    }
    //我机被击中后变红30次刷新
    if (((game_window*)game)->my_flyer1->fight_flag > 0 && ((game_window*)game)->my_flyer1->fight_flag < 30)
    {
        ((game_window*)game)->my_flyer1->color(FL_RED);
        ((game_window*)game)->my_flyer1->fight_flag++;
    }
    else if (((game_window*)game)->my_flyer1->fight_flag == 30)
    {
        ((game_window*)game)->my_flyer1->color(FL_GREEN);
        ((game_window*)game)->game_score--;//计分，每当被敌机击中就减分
        ((game_window*)game)->my_flyer1->fight_flag = 0;
    }
    else if (((game_window*)game)->my_flyer1->fight_flag == 0)
    {
    }
    //enemy_time控制敌人飞机enemy移动与子弹发射
    int enemy_time = 0;
    if (game_window::use_time < 30)
    {
        //等于1时才发射子弹，发射3个子弹
        enemy_time = game_window::use_time % 10;
    }
    else if (game_window::use_time >= 30 && game_window::use_time < 60)
    {
        //等于0
        enemy_time = 0;
    }
    else if (game_window::use_time >= 60 && game_window::use_time < 90)
    {
        //等于1时才发射子弹，发射1个子弹
        enemy_time = 1;
    }
    else if (game_window::use_time >= 90 && game_window::use_time < 120)
    {
        //等于2
        enemy_time = 2;
    }
    else if (game_window::use_time >= 120 && game_window::use_time < 150)
    {
        //等于1时才发射子弹，发射1个子弹
        enemy_time = 1;
    }
    else if (game_window::use_time >= 150 && game_window::use_time < 200)
    {
        enemy_time = 0;
    }
    static int enemy_bullet_time = 0;
    //敌机四个方向随机移动与被击中运动
    if (((game_window*)game)->bullet_flag == true)
    {
        ((game_window*)game)->enemy_1->enemy_flyer_move(1);
        ((game_window*)game)->enemy_2->enemy_flyer_move(2);
        ((game_window*)game)->enemy_3->enemy_flyer_move(3);

        switch (enemy_time)
        {
        case 0:
            //等于0
            enemy_bullet_time = 0;
            break;
        case 1:
            //当enemy_time等于1且发生变化时才发射子弹
            if (enemy_bullet_time != 1)
            {
                //当子弹数量过多时删掉旧子弹(deque使用pop时只是清空指针，没有清理内存，有问题）
                if (200 <= ((game_window*)game)->enemy_1_bullet_1_pos.length())
                {
                    ((game_window*)game)->enemy_1_bullet_1_pos.dele(0);
                    ((game_window*)game)->enemy_1_bullet_2_pos.dele(0);
                    ((game_window*)game)->enemy_1_bullet_3_pos.dele(0);
                    ((game_window*)game)->enemy_2_bullet_1_pos.dele(0);
                    ((game_window*)game)->enemy_2_bullet_2_pos.dele(0);
                    ((game_window*)game)->enemy_2_bullet_3_pos.dele(0);
                    ((game_window*)game)->enemy_3_bullet_1_pos.dele(0);
                    ((game_window*)game)->enemy_3_bullet_2_pos.dele(0);
                    ((game_window*)game)->enemy_3_bullet_3_pos.dele(0);
                }
                x = ((game_window*)game)->enemy_1->x();
                y = ((game_window*)game)->enemy_1->y();
                ((game_window*)game)->enemy_1_bullet_1_pos.pushX(x);
                ((game_window*)game)->enemy_1_bullet_1_pos.pushY(y);
                ((game_window*)game)->enemy_1_bullet_2_pos.pushX(x);
                ((game_window*)game)->enemy_1_bullet_2_pos.pushY(y);
                ((game_window*)game)->enemy_1_bullet_3_pos.pushX(x);
                ((game_window*)game)->enemy_1_bullet_3_pos.pushY(y);
                x = ((game_window*)game)->enemy_2->x();
                y = ((game_window*)game)->enemy_2->y();
                ((game_window*)game)->enemy_2_bullet_1_pos.pushX(x);
                ((game_window*)game)->enemy_2_bullet_1_pos.pushY(y);
                ((game_window*)game)->enemy_2_bullet_2_pos.pushX(x);
                ((game_window*)game)->enemy_2_bullet_2_pos.pushY(y);
                ((game_window*)game)->enemy_2_bullet_3_pos.pushX(x);
                ((game_window*)game)->enemy_2_bullet_3_pos.pushY(y);
                x = ((game_window*)game)->enemy_3->x();
                y = ((game_window*)game)->enemy_3->y();
                ((game_window*)game)->enemy_3_bullet_1_pos.pushX(x);
                ((game_window*)game)->enemy_3_bullet_1_pos.pushY(y);
                ((game_window*)game)->enemy_3_bullet_2_pos.pushX(x);
                ((game_window*)game)->enemy_3_bullet_2_pos.pushY(y);
                ((game_window*)game)->enemy_3_bullet_3_pos.pushX(x);
                ((game_window*)game)->enemy_3_bullet_3_pos.pushY(y);
            }
            enemy_bullet_time = 1;
            break;
        case 2:
            //等于2
            enemy_bullet_time = 2;
            break;
        default:
            break;
        }
    }
    //按照enemy_bullet_pos中的信息绘制子弹
    if (((game_window*)game) != NULL && ((game_window*)game)->bullet_flag == true)
    {
        ((game_window*)game)->enemy_1_bullet_1->enemy_bullet_drawing(((game_window*)game)->enemy_1_bullet_1_pos);
        ((game_window*)game)->enemy_1_bullet_2->enemy_bullet_drawing(((game_window*)game)->enemy_1_bullet_2_pos);
        ((game_window*)game)->enemy_1_bullet_3->enemy_bullet_drawing(((game_window*)game)->enemy_1_bullet_3_pos);
        ((game_window*)game)->enemy_2_bullet_1->enemy_bullet_drawing(((game_window*)game)->enemy_2_bullet_1_pos);
        ((game_window*)game)->enemy_2_bullet_2->enemy_bullet_drawing(((game_window*)game)->enemy_2_bullet_2_pos);
        ((game_window*)game)->enemy_2_bullet_3->enemy_bullet_drawing(((game_window*)game)->enemy_2_bullet_3_pos);
        ((game_window*)game)->enemy_3_bullet_1->enemy_bullet_drawing(((game_window*)game)->enemy_3_bullet_1_pos);
        ((game_window*)game)->enemy_3_bullet_2->enemy_bullet_drawing(((game_window*)game)->enemy_3_bullet_2_pos);
        ((game_window*)game)->enemy_3_bullet_3->enemy_bullet_drawing(((game_window*)game)->enemy_3_bullet_3_pos);

        //把my_bullet_pos中存储的所有坐标都按照方向移动一位
        for (int j = 0; j < ((game_window*)game)->enemy_1_bullet_1_pos.length(); j++)
        {
            ((game_window*)game)->enemy_1_bullet_1_pos.enemy_bullet1(j);
            ((game_window*)game)->enemy_2_bullet_1_pos.enemy_bullet1(j);
            ((game_window*)game)->enemy_3_bullet_1_pos.enemy_bullet1(j);
            ((game_window*)game)->enemy_1_bullet_2_pos.enemy_bullet2(j);
            ((game_window*)game)->enemy_2_bullet_2_pos.enemy_bullet2(j);
            ((game_window*)game)->enemy_3_bullet_2_pos.enemy_bullet2(j);
            ((game_window*)game)->enemy_1_bullet_3_pos.enemy_bullet3(j);
            ((game_window*)game)->enemy_2_bullet_3_pos.enemy_bullet3(j);
            ((game_window*)game)->enemy_3_bullet_3_pos.enemy_bullet3(j); 
        }
    }
    //敌机碰撞检测
    ((game_window*)game)->my_bullet->my_bullet_collision(((game_window*)game)->my_bullet_pos, ((game_window*)game)->enemy_1);
    ((game_window*)game)->my_bullet->my_bullet_collision(((game_window*)game)->my_bullet_pos, ((game_window*)game)->enemy_2);
    ((game_window*)game)->my_bullet->my_bullet_collision(((game_window*)game)->my_bullet_pos, ((game_window*)game)->enemy_3);
    //我机碰撞检测
    ((game_window*)game)->enemy_1_bullet_1->enemy_bullet_collision(((game_window*)game)->enemy_1_bullet_1_pos, ((game_window*)game)->my_flyer1);
    ((game_window*)game)->enemy_1_bullet_2->enemy_bullet_collision(((game_window*)game)->enemy_1_bullet_2_pos, ((game_window*)game)->my_flyer1);
    ((game_window*)game)->enemy_1_bullet_3->enemy_bullet_collision(((game_window*)game)->enemy_1_bullet_3_pos, ((game_window*)game)->my_flyer1);
    ((game_window*)game)->enemy_2_bullet_1->enemy_bullet_collision(((game_window*)game)->enemy_2_bullet_1_pos, ((game_window*)game)->my_flyer1);
    ((game_window*)game)->enemy_2_bullet_2->enemy_bullet_collision(((game_window*)game)->enemy_2_bullet_2_pos, ((game_window*)game)->my_flyer1);
    ((game_window*)game)->enemy_2_bullet_3->enemy_bullet_collision(((game_window*)game)->enemy_2_bullet_3_pos, ((game_window*)game)->my_flyer1);
    ((game_window*)game)->enemy_3_bullet_1->enemy_bullet_collision(((game_window*)game)->enemy_3_bullet_1_pos, ((game_window*)game)->my_flyer1);
    ((game_window*)game)->enemy_3_bullet_2->enemy_bullet_collision(((game_window*)game)->enemy_3_bullet_2_pos, ((game_window*)game)->my_flyer1);
    ((game_window*)game)->enemy_3_bullet_3->enemy_bullet_collision(((game_window*)game)->enemy_3_bullet_3_pos, ((game_window*)game)->my_flyer1);

    Fl::repeat_timeout(0.01, time_callback, game);
}

int main()
{
    game_window *window;
    window = new game_window(800, 494, "飞机大战");
    Fl::add_timeout(1.0, time_callback, window);
    return Fl::run();
}