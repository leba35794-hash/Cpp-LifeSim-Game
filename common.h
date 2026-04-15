#ifndef COMMON_H
#define COMMON_H

/* ====== 头文件区 ====== */
#include <iostream>
#include <string>
#include <unistd.h>
#include <unordered_map>
#include "random.h"
/* ====== 变量区 ====== */
inline int hp = 100;    //后面有注释的都是在开发中
inline int maxHp = 100;   //一样
inline bool dead = false;   //一样
inline long long Money = 0;  //主角
inline long long days = 0;
inline long long targetMoney = 100000000;
inline bool lotteryCd = false;
/* ====== 函数声明区 ====== */
int work();
void randomFamily();
bool checkGoal();
void lottery();

/* ====== 类声明区 ====== */
class Backpack {
private:
    std::unordered_map<std::string, int> packet;
public:
    Backpack();
    void discard();
    void show();
    void buyMenu();
    void buyItem(int price,std::string name);
};




#endif