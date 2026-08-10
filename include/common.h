#ifndef COMMON_H
#define COMMON_H

/* ====== 头文件区 ====== */
#include <iostream>
#include <string>
/* ====== 函数/类声明区 ======*/
class Game;
class Backpack;
class Bank;
class Player;
bool menu(Game& game);

/* ====== 版本常量 ====== */
const std::string VERSION_PREFIX = "Alpha";
const std::string VERSION_NUM = "21";
const std::string VERSION_DISPLAY = "Alpha 0.21";
const std::string SERVER_API = "http://xiaomaoge.eu.cc/game/api";
const std::string SERVER = "http://xiaomaoge.eu.cc/game";

#endif