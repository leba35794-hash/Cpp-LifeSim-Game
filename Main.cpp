#include "common.h"

int main() {
    Backpack p1;
    randomFamily();
    bool running = true;
    std::string input;
    std::cout << "当前版本为:Alpha 0.13"<< std::endl;
    do {
        running = checkGoal();
        if(running == false)
        {
            break;
        }

        std::cout
                << "当前余额:" << Money << "元人民币" << std::endl
                << "当前天数第:" << days << "天" << std::endl
                << "1.打工(日结)" << std::endl
                << "2.查看背包内物品" << std::endl
                << "3.丢掉背包内物品" << std::endl
                << "4.购买物品" << std::endl
                << "5.使用物品(开发中)" << std::endl
                << "6.结束一天" << std::endl
                << "7.购买彩票" << std::endl
                << "0.退出" << std::endl;
        std::cin >> input;
        if(input == "1")
        {
            Money += work();
        }
        else if(input == "2")
        {
            p1.show();
        }
        else if(input == "3")
        {
            p1.show();
            p1.discard();
        }
        else if(input == "4")
        {
            p1.buyMenu();
        }
        else if(input == "5")
        {

        }
        else if(input == "6")
        {
            std::cout << "第" << days << "天结束了" << std::endl;
            days += 1;
            lotteryCd = false;
            sleep(1);
        }
        else if(input == "7")
        {
            if(!lotteryCd)
            {
                lottery();
            }
            else
            {
                std::cout << "今日已经买过一次了，请明日再来" << std::endl;

            }


        }
        else if(input == "0")
        {
            std::cout << "已退出" << std::endl;
            running = false;
            break;
        }
        else
        {
            std::cout << "错误!" << std::endl;
        }


    }
    while(running);


}