#ifndef _BULLET_LIST_BOX
#define _BULLET_LIST_BOX
#include <deque>

class bullet_list
{
public:
    std::deque<int>listX;
    std::deque<int>listY;
    std::deque<int>listDre;

    bullet_list();
    ~bullet_list();
    //在数组最后插入数据
    void pushX(int x);
    void pushY(int y);
    void pushDre(int dre);
    //取出数组中的一个数据，序号从零开始
    int getX(int i);
    int getY(int i);
    int getDre(int i);
    //删除数组的一个元素
    void dele(int i);
    //返回数组长度与是否为空
    int length();
    bool isEmpty();
};

#endif // !_BULLET_LIST_BOX