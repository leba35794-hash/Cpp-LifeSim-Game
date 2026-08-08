#ifndef COMMON_H
#define COMMON_H

/* ====== 头文件区 ====== */
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <unordered_map>
#include "random.h"
#include <cstdio>

/* ====== 函数/类声明区 ======*/
class Game;
class Player;
bool menu(Game& game);

/* ====== 版本常量 ====== */
const std::string VERSION_PREFIX = "Alpha";
const std::string VERSION_NUM = "19";
const std::string VERSION_DISPLAY = "Alpha 0.19";
const std::string SERVER_API = "http://xiaomaoge.eu.cc/game/api";
const std::string SERVER = "http://xiaomaoge.eu.cc/game";

/* ====== 类声明区 ====== */

class Backpack {
private:
    std::unordered_map<std::string, int> packet;
    void buyItem(int price,std::string name,Game& game);
    bool useItem(std::string name,Game& game);
public:
    Backpack();
    void discard();
    void show();
    void buyMenu(Game& game);
    void useMenu(Game& game);
    const std::unordered_map<std::string, int>& getAllItems() const;
    void clear();
    void addItem(const std::string& name, int count);
};
class Player {
private:
    int hp = 100;
    int maxHp = 100;
    int minHp = 0;
    int hunger = 100;
    int maxHunger = 100;
    int minHunger = 0;
    int thirst = 100;
    int maxThirst = 100;
    int minThirst = 0;
    bool dead = false;
    long long Money = 0;  //因为比较特殊整个游戏都是围绕着他进行的所以就给他大写
    long long days = 0;
    long long targetMoney = 100000000;
public:
    long long getMoney();
    long long getDays();
    int getHp();
    int getHunger();
    void earnHunger(long long amount);
    void spendHunger(long long amount);
    int getThirst();
    void earnThirst(long long amount);
    void spendThirst(long long amount);
    bool checkGoal();
    long long getTargetMoney();
    void setMoney(long long amount);
    void setDays(long long amount);
    void setHp(int amount);
    void setHunger(int amount);
    void setThirst(int amount);
    bool getDead();
    void die(bool easterEgg);
    void earnMoney(long long amount);
    void earnDays();
    void earnHp(int amount);
    bool spendMoney(long long amount);
    void spendHp(int amount,bool easterEgg = false);
};
class Bank {
private:
    double balance = 0.0;
public:
    const double interestRate = 0.00025;
    void deposit(double amount,Player& player);
    void withdraw(double amount,Player& player);
    void checkBalance();
    void dailyInterest();
    double getBalance();
    void setBalance(double amount);
};
class Game {
private:
    bool lotteryCd = false;
    void familyResult(std::string m,int z);
    void randomEvent();
public:
    Bank bank;
    Player player;
    Backpack backpack;
    int work();
    void randomFamily();
    bool getLotteryCd();
    void lottery();
    void nextDay();
    void saveGame();
    void loadGame();
    bool sendVersion();
};

#endif