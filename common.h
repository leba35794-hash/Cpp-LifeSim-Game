#ifndef COMMON_H
#define COMMON_H

/* ====== 头文件区 ====== */
#include <iostream>
#include <string>
#include <unistd.h>
#include <unordered_map>
#include "random.h"

/* ====== 函数声明区 ======*/
class Game;
bool menu(Game& game);

/* ====== 类声明区 ====== */

class Backpack {
private:
    std::unordered_map<std::string, int> packet;
    void buyItem(int price,std::string name,Game& game);
    void useItem(std::string name,Game& game);
public:
    Backpack();
    void discard();
    void show();
    void buyMenu(Game& game);
    void useMenu(Game& game);
};



class Game {
private:
    int hp = 100;
    int maxHp = 100;
    int minHp = 0;
    bool dead = false;
    long long Money = 0;  //因为比较特殊整个游戏都是围绕着他进行的所以就给他大写
    long long days = 0;
    long long targetMoney = 100000000;
    bool lotteryCd = false;
    void familyResult(std::string m,int z);
public:
    Backpack backpack;
    int work();
    void randomFamily();
    bool checkGoal();
    void lottery();
    long long getMoney();
    long long getDays();
    bool getLotteryCd();
    long long getTargetMoney();
    int getHp();
    bool getDead();
    void die();
    void earnMoney(long long amount);
    void earnDays();
    void earnHp(int amount);
    bool spendMoney(long long amount);
    void spendHp(int amount);
    void nextDay();
    
};



#endif