#include "common.h"


int Game::work() {
    int a = random(100,300);
    std::cout << "工作中···" << std::endl;
    sleep(random(2,5));
    std::cout << "工作了一天您赚到了:" << a << "元人民币" << std::endl;
    return a;
}

void Game::familyResult(std::string m,int z) {

    std::cout
            << "你出生了" << std::endl
            << "你是个男孩" << std::endl
            << "你的家境" << m << std::endl
            << "很快你成年了家里给了你一笔钱" << std::endl
            << "总共:" << z << "元人民币" << std::endl << std::endl;
    Money += z;

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


bool Game::checkGoal() {
    if(Money >= targetMoney)
    {
        std::cout << "\n恭喜你!你达成目标"<< std::endl;
        return false;
    }
    else
    {
        return true;
    }

}

long long Game::getMoney() {
    return Money;
}
long long Game::getDays() {
    return days;
}
bool Game::getLotteryCd() {
    return lotteryCd;
}
long long Game::getTargetMoney() {
    return targetMoney;
}
void Game::earnMoney(long long amount) {
    Money += amount;
}
void Game::earnDays() {
    days += 1;
}
bool Game::spendMoney(long long amount) {
    if (Money >= amount) {
        Money -= amount;
        return true;
    }
    else
    {
        return false;
    }
}
void Game::nextDay() {
    lotteryCd = false;
}
int Game::getHp() {
    return hp;
}
void Game::earnHp(int amount) {
    if(hp + amount >= maxHp)
    {
        hp = maxHp;
    }
    else
    {
        hp += amount;
    }
}
void Game::spendHp(int amount) {
    if(hp - amount <= minHp)
    {
        die();
    }
    else
    {
        hp -= amount;
    }
}
void Game::die() {
    std::cout << "您死了!...游戏结束!" << std::endl;
    hp = minHp;
    dead = true;
}
bool Game::getDead() {
    return dead;
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
        std::cout << "当前余额:" << Money << "元人民币" << std::endl;
        std::cout << "购买彩票需花费50元人民币" << std::endl;
        std::cout << "是否购买(y/n):";
        std::cin >> input2;


        if(input2 == "y")
        {
            if(Money >= 50)
            {
                Money -= 50;

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
                    Money += b;
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


Backpack::Backpack() {
    packet["手机"] = 1;
    packet["面包"] = 2;
    packet["矿泉水"] = 2;
    packet["药品"] = 0;
    packet["饮料"] = 0;
    packet["肉食"] = 0;
    packet["水果"] = 0;
}

void Backpack::discard() {
    std::string name;
    int count = 1;
    std::cout << "请输入你要丢弃的物品(格式:名称 数量)" << std::endl;
    std::cin >> name >> count;

    auto it = packet.find(name);

    if (it == packet.end()) {
        std::cout << "背包中没有" << name << std::endl;
    } else if (it->second < count) {
        std::cout << "数量不足！只有 " << it->second << " 个" << std::endl;
    } else {
        it->second -= count;
        std::cout << "已丢出 " << count << " 个" << name << std::endl;
        if (it->second == 0) packet.erase(it);
    }
}
void Backpack::show() {
    if(!packet.empty())
    {
        std::cout << "你当前背包内的物品:" << std::endl;
        for(auto& sy : packet) {
            std::cout << sy.first << "x" << sy.second << std::endl;
        }
    }
    else
    {
        std::cout << "你的背包是空的" << std::endl;
    }

}

void Backpack::buyMenu(Game& game) {
    std::string input;
    bool a = true;
    do {
        std::cout << "\n当前余额:" << game.getMoney() << "元人民币" << std::endl;
        std::cout << "请选择您要购买的物品:" << std::endl;
        std::cout << "1. 手机 1000元" << std::endl;
        std::cout << "2. 面包 5元" << std::endl;
        std::cout << "3. 矿泉水 1元" << std::endl;
        std::cout << "4. 药品 30元" << std::endl;
        std::cout << "5. 饮料 3元" << std::endl;
        std::cout << "6. 肉食 2元" << std::endl;
        std::cout << "7. 水果 10元" << std::endl;
        std::cout << "0.退出\n" << std::endl;
        std::cin >> input;
        if(input == "1")
        {
            buyItem(1000,"手机",game);
        }
        else if(input == "2")
        {
            buyItem(5,"面包",game);
        }
        else if(input == "3")
        {
            buyItem(1,"矿泉水",game);
        }
        else if(input == "4")
        {
            buyItem(30,"药品",game);
        }
        else if(input == "5")
        {
            buyItem(3,"饮料",game);
        }
        else if(input == "6")
        {
            buyItem(2,"肉食",game);
        }
        else if(input == "7")
        {
            buyItem(10,"水果",game);
        }
        else if(input == "0")
        {
            std::cout << "已退出" << std::endl;
            a = false;
            break;
        }
        else
        {
            std::cout << "错误!" << std::endl;
        }
    }
    while(a);

}

void Backpack::buyItem(int price,std::string name,Game& game) {
    if(game.getMoney() >= price)
    {

        std::cout << "购买成功!" << std::endl;
        packet[name] += 1;
        game.spendMoney(price);
    }
    else
    {
        std::cout << "余额不足!" << std::endl;
    }

}


void Backpack::useItem(std::string name,Game& game) {
    auto it = packet.find(name);
    if (it == packet.end() || it->second <= 0) {
        std::cout << "没有这个物品！" << std::endl;
        return;
    }
    else
    {
        if(name == "面包")
        {
            std::cout << "你吃了几口面包感觉非常美味 hp + 5 面包 - 1" << std::endl;
            packet[name] -= 1;
            //我操了，写到这里才发现，还要顺带写个血量系统
            game.earnHp(5);
        }
        else if(name == "手机")
        {
            std::cout << "你拿起手机当打手带着老板千万撤离 hp - 5 Money + 200" << std::endl;
            game.spendHp(5);
            game.earnMoney(200);
        }
        else if(name == "药品")
        {
            std::cout << "药很苦但你很快就恢复了健康 hp = 100 药品 - 1" << std::endl;
            packet[name] -= 1;
            game.earnHp(100);
        }
        else if(name == "矿泉水")
        {
            std::cout << "只是普通的水而已 hp + 5" << std::endl;
            packet[name] -= 1;
            game.earnHp(5);
        }
        else if(name == "饮料")
        {
            std::cout << "非常的好喝的饮料 hp + 10 饮料 - 1" << std::endl;
            packet[name] -= 1;
            game.earnHp(10);
        }
        else if(name == "肉食")
        {
            std::cout << "非常的好吃的肉食 hp + 15 肉食 - 1" << std::endl;
            packet[name] -= 1;
            game.earnHp(15);
        }
        else
        {
            std::cout << "非常的好吃的水果 hp + 20 水果 - 1" << std::endl;
            packet[name] -= 1;
            game.earnHp(20);
        }
        
    }
    
    
}

void Backpack::useMenu(Game& game) {
    if(packet.empty())
    {
        std::cout << "背包是空的没有物品可用" << std::endl;
        return;
    }
    std::string input;
    bool exitMenu = true;
    do{
        std::cout << "请选择您要使用的物品:" << std::endl;
        std::cout << "1. 手机" << std::endl;
        std::cout << "2. 面包" << std::endl;
        std::cout << "3. 矿泉水" << std::endl;
        std::cout << "4. 药品" << std::endl;
        std::cout << "5. 饮料" << std::endl;
        std::cout << "6. 肉食" << std::endl;
        std::cout << "7. 水果" << std::endl;
        std::cout << "0.退出\n" << std::endl;
        std::cin >> input;
        if(input == "1")
        {
            useItem("手机",game);
        }
        else if(input == "2")
        {
            useItem("面包",game);
        }
        else if(input == "3")
        {
            useItem("矿泉水",game);
        }
        else if(input == "4")
        {
            useItem("药品",game);
        }
        else if(input == "5")
        {
            useItem("饮料",game);
        }
        else if(input == "6")
        {
            useItem("肉食",game);
        }
        else if(input == "7")
        {
            useItem("水果",game);
        }
        else if(input == "0")
        {
            std::cout << "已退出" << std::endl;
            exitMenu = false;
            return;
        }
        else
        {
            std::cout << "错误请重新输入" << std::endl;
        }
        
    }while(exitMenu);
    
}







bool menu(Game& game) {
    bool running = true;
    std::string input;
    std::cout << "当前版本为:Alpha 0.15"<< std::endl;
    do {
        running = game.checkGoal();
        if(!running)
        {
            return false;
        }
        
        std::cout
                << "当前余额:" << game.getMoney() << "元人民币" << std::endl
                << "当前血量:" << game.getHp() << "/100" << std::endl
                << "当前天数第:" << game.getDays() << "天" << std::endl
                << "1.打工(日结)" << std::endl
                << "2.查看背包内物品" << std::endl
                << "3.丢掉背包内物品" << std::endl
                << "4.购买物品" << std::endl
                << "5.使用物品" << std::endl
                << "6.结束一天" << std::endl
                << "7.购买彩票" << std::endl
                << "0.退出" << std::endl;
        std::cin >> input;
        if(input == "1")
        {
            game.earnMoney(game.work());
        }
        else if(input == "2")
        {
            game.backpack.show();
        }
        else if(input == "3")
        {
            game.backpack.show();
            game.backpack.discard();
        }
        else if(input == "4")
        {
            game.backpack.buyMenu(game);
        }
        else if(input == "5")
        {
            game.backpack.useMenu(game);
        }
        else if(input == "6")
        {
            std::cout << "第" << game.getDays() << "天结束了" << std::endl;
            game.earnDays();
            game.nextDay();
            sleep(1);
        }
        else if(input == "7")
        {
            if(!game.getLotteryCd())
            {
                game.lottery();
            }
            else
            {
                std::cout << "今日已经买过一次了，请明日再来" << std::endl;

            }


        }
        else if(input == "0")
        {
            std::cout << "已退出" << std::endl;
            return false;
        }
        else
        {
            std::cout << "错误!" << std::endl;
        }


    }
    while(running);


}