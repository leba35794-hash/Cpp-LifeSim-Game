#include "../include/common.h"
#include "../include/game.h"
#include "../include/player.h"
#include "../include/bank.h"
#include "../include/backpack.h"
#include "random.h"
#include <fstream>
#include <unistd.h>
#include <cstdio>
int Game::work() {
    int a = random(200,500);
    std::cout << "工作中···" << std::endl;
    sleep(random(1,2));
    std::cout << "工作了一天您赚到了:" << a << "元人民币" << std::endl;
    if(player.getHunger() >= 40)
    {
        std::cout << "饥饿值 - 40"<< std::endl;
        player.spendHunger(40);
    }
    else
    {
        std::cout << "由于饥饿值不足40所以扣除血量15" << std::endl;
        player.spendHp(15);
    }
    if(player.getThirst() >= 40)
    {
        std::cout << "口渴值 - 40"<< std::endl;
        player.spendThirst(40);
    }
    else
    {
        std::cout << "由于口渴值不足40所以扣除血量15" << std::endl;
        player.spendHp(15);
    }
    return a;
}

void Game::familyResult(std::string m,int z) {

    std::cout
            << "你出生了" << std::endl
            << "你是个男孩" << std::endl
            << "你的家境" << m << std::endl
            << "很快你成年了家里给了你一笔钱" << std::endl
            << "总共:" << z << "元人民币" << std::endl << std::endl;
    player.earnMoney(z);

}
bool Game::getLotteryCd() {
    return lotteryCd;
}
void Game::randomFamily() {
    int a = random(1,100);
    int n1 = 15;
    int n2 = 50;
    int n3 = 85;
    int z1;
    std::string m1;
    if (a <= n1)
    {
        m1 = "贫穷";
        z1 = random(200,800);
        familyResult(m1,z1);
    }
    else if(a <= n2)
    {
        m1 = "普通";
        z1 = random(800,1500);
        familyResult(m1,z1);
    }
    else if(a <= n3)
    {
        m1 = "小康";
        z1 = random(2000,3000);
        familyResult(m1,z1);
    }
    else
    {
        m1 = "富裕";
        z1 = random(4000,5000);
        familyResult(m1,z1);
    }


}
void Game::nextDay() {
    lotteryCd = false;
    randomEvent();
}
bool Game::sendVersion() {
    std::string cmd = "curl -s --max-time 5 \"" + SERVER_API + "/version.php\"";
    std::string versionStr;
    char buffer[128];
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return false;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        versionStr += buffer;
    }
    pclose(pipe);
    if (!versionStr.empty()) {
        size_t end = versionStr.find_last_not_of("\n\r");
        if (end != std::string::npos) {
            versionStr.erase(end + 1);
        } else {
            versionStr.clear();
        }
    }
    size_t pos = versionStr.find(' ');
    if (pos == std::string::npos) return false;
    
    std::string webPrefix = versionStr.substr(0, pos);
    std::string webNumStr = versionStr.substr(pos + 1);
    
    if (VERSION_PREFIX != webPrefix || VERSION_NUM != webNumStr) {
        return true;
    }
    return false;
}
void Game::randomEvent() {
    int ra = random(1,100);
    if(ra == 1)
    {
        std::cout << "你运气超好在路边免费抽奖抽中了10万元" << std::endl;
        player.earnMoney(100000);
    }
    else
    {
        switch(ra)
        {
              case 2:
              case 3:
              case 4:
              case 5:
              case 6:
                  std::cout << "你走在马路上，捡到了100块钱" << std::endl;
                  player.earnMoney(100);
                  break;
              case 7:
              case 8:
              case 9:
              case 10:
                  std::cout << "你一出门就踩到了一坨狗屎，你觉得倒霉透了" << std::endl;
                  break;
              case 11:
              case 12:
              case 13:
              case 14:
              case 15:
              case 16:
                  std::cout << "你走在马路上，突然被一颗石子绊倒了";
                  if(player.getMoney() == 0)
                  {
                      std::cout << "因为你没有钱买创可贴所以减少5的血量" << std::endl;
                      player.spendHp(5);
                  }
                  else
                  {
                      std::cout << "去药店买了个创可贴花费5元" << std::endl;
                      player.spendMoney(5);
                  }
                  break;
              case 17:
              case 18:
              case 19:
              case 20:
                  std::cout << "你刚一回到家，就发现自己的钱包不见了扣除500块" << std::endl;
                  player.spendMoney(500);
                  break;
              default:
                  std::cout << "今天无事发生" << std::endl;
                  break;
        }
    }
}
void Game::saveGame() {
    std::ofstream file("saveGame.txt");
    if(!file) {
        std::cout << "保存失败" << std::endl;
        return;
    }
    file << player.getMoney() << "\n";
    file << player.getDays() << "\n";
    file << player.getHp() << "\n";
    file << player.getHunger() << "\n";
    file << player.getThirst() << "\n";
    file << lotteryCd << "\n";
    file << bank.getBalance() << "\n";
    for (const auto& item : backpack.getAllItems()) {
        file << item.first << " " << item.second << "\n";
    }
    file.close();
    std::cout << "游戏已保存！" << std::endl;
}
void Game::loadGame() {
    std::ifstream file("saveGame.txt");
    if(!file)
    {
        std::cout << "未发现存档" << std::endl;
        return;
    }
    long long Money, days;
    int hp, hunger, thirst;
    bool lottery;
    double balance;
    file >> Money >> days >> hp >> hunger >> thirst >> lottery >> balance;
    player.setMoney(Money);
    player.setDays(days);
    player.setHp(hp);
    player.setHunger(hunger);
    player.setThirst(thirst);
    lotteryCd = lottery;
    bank.setBalance(balance);
    backpack.clear();
    std::string name;
    int count;
    while (file >> name >> count) {
        backpack.addItem(name, count);
    }
    file.close();
    std::cout << "读取存档成功！" << std::endl;
}

void Game::lottery()
{
    int a = random(1,10);
    long long b = 10000000;
    int input;
    std::string input2;
    bool mnl = true;
    bool mnl2 = true;
    std::cout << "彩票奖金为:1000万元人民币" << std::endl;
    while (mnl2)
    {
        std::cout << "当前余额:" << player.getMoney() << "元人民币" << std::endl;
        std::cout << "购买彩票需花费50元人民币" << std::endl;
        std::cout << "是否购买(y/n):";
        std::cin >> input2;

        if(input2 == "y")
        {
            if(player.getMoney() >= 50)
            {
                player.spendMoney(50);

                std::cout << "购买成功!" << std::endl;

                lotteryCd = true;

                while (mnl)
                {
                    std::cout << "请输入您选择的号码(1-10):";

                    std::cin >> input;
                    if(input >= 1 && input <= 10)
                    {
                        mnl = false;
                        break;
                    }
                    else
                    {
                        std::cout << "错误请重新输入" << std::endl;
                    }

                }

                sleep(1);
                if(input == a)
                {
                    std::cout << "恭喜您!您中奖"<< std::endl;
                    player.earnMoney(b);
                    mnl2 = false;
                    break;
                }
                else
                {
                    std::cout << "很遗憾的告诉您!未中奖" << std::endl;
                    mnl2 = false;
                    break;
                }
            }
            else
            {
                std::cout << "余额不足" << std::endl;
                mnl2 = false;
                break;
            }
        }
        else if(input2 == "n")
        {
            std::cout << "已取消" << std::endl;
            mnl2 = false;
            break;
        }
        else
        {
            std::cout << "错误请重新输入 "<< std::endl;
        }

    }

}
