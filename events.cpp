#include "common.h"

int work() {
    int a = random(100,300);
    std::cout << "工作中···" << std::endl;
    sleep(random(4,7));
    std::cout << "工作了一天您赚到了:" << a << "元人民币" << std::endl;
    return a;
}

void familyResult(std::string m,int z) {

    std::cout
            << "你出生了" << std::endl
            << "你是个男孩" << std::endl
            << "你的家境" << m << std::endl
            << "很快你成年了家里给了你一笔钱" << std::endl
            << "总共:" << z << "元人民币" << std::endl << std::endl;
    Money += z;

}

void randomFamily() {
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

void Backpack::buyMenu() {
    std::string input;
    bool a = true;
    do{
        std::cout << "\n当前余额:" << Money << "元人民币" << std::endl;
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
            buyItem(1000,"手机");
        }
        else if(input == "2")
        {
            buyItem(5,"面包");
        }
        else if(input == "3")
        {
            buyItem(1,"矿泉水");
        }
        else if(input == "4")
        {
            buyItem(30,"药品");
        }
        else if(input == "5")
        {
            buyItem(3,"饮料");
        }
        else if(input == "6")
        {
            buyItem(2,"肉食");
        }
        else if(input == "7")
        {
            buyItem(10,"水果");
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

void Backpack::buyItem(int price,std::string name) {
    if(Money >= price)
            {
                
                std::cout << "购买成功!" << std::endl;
                packet[name] += 1;
                Money -= price;
            }
            else
            {
                std::cout << "余额不足!" << std::endl;
            }
    
    
    
}

bool checkGoal() {
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


void lottery()
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