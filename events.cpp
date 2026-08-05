#include "common.h"


int Game::work() {
    int a = random(200,500);
    std::cout << "工作中···" << std::endl;
    sleep(random(2,4));
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


bool Player::checkGoal() {
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
int Player::getHp() {
    return hp;
}
int Player::getHunger() {
    return hunger;
}
void Player::earnHunger(long long amount) {
    if(hunger + amount <= maxHunger)
    {
        hunger += amount;
    }
    else
    {
        hunger = maxHunger;
    }
}
void Player::spendHunger(long long amount) {
    if(hunger - amount >= minHunger)
    {
        hunger -= amount;
    }
    else
    {
        hunger = minHunger;
    }
}
int Player::getThirst() {
    return thirst;
}
void Player::earnThirst(long long amount) {
    if(thirst + amount <= maxThirst)
    {
        thirst += amount;
    }
    else
    {
        thirst = maxThirst;
    }
}
const std::unordered_map<std::string, int>& Backpack::getAllItems() const {
    return packet;
}

void Backpack::clear() {
    packet.clear();
}

void Backpack::addItem(const std::string& name, int count) {
    packet[name] = count;
}
void Player::setMoney(long long amount) {
    Money = amount;
}
void Player::setDays(long long amount) {
    days = amount;
}
void Player::setHp(int amount) {
    hp = amount;
}
void Player::setHunger(int amount) {
    hunger = amount;
}
void Player::setThirst(int amount) {
    thirst = amount;
}
    
void Player::spendThirst(long long amount) {
    if(thirst - amount >= minThirst)
    {
        thirst -= amount;
    }
    else
    {
        thirst = minThirst;
    }
}
long long Player::getMoney() {
    return Money;
}
long long Player::getDays() {
    return days;
}
bool Game::getLotteryCd() {
    return lotteryCd;
}
long long Player::getTargetMoney() {
    return targetMoney;
}
void Player::earnMoney(long long amount) {
    Money += amount;
}
void Player::earnDays() {
    days += 1;
}
bool Player::spendMoney(long long amount) {
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
void Player::earnHp(int amount) {
    if(hp + amount >= maxHp)
    {
        hp = maxHp;
    }
    else
    {
        hp += amount;
    }
}
void Player::spendHp(int amount,bool easterEgg) {
    if(hp - amount <= minHp)
    {
        die(easterEgg);
    }
    else
    {
        hp -= amount;
    }
}
void Player::die(bool easterEgg) {
    if(easterEgg)
    {
        std::cout << "您死了!原因:你在打游戏结束后猝死了...游戏结束!" << std::endl;
    }
    else
    {
        std::cout << "您死了!...游戏结束!" << std::endl;
    }
    hp = minHp;
    dead = true;
}
bool Player::getDead() {
    return dead;
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
    file >> Money >> days >> hp >> hunger >> thirst >> lottery;
    player.setMoney(Money);
    player.setDays(days);
    player.setHp(hp);
    player.setHunger(hunger);
    player.setThirst(thirst);
    lotteryCd = lottery;
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
        std::cout << "\n当前余额:" << game.player.getMoney() << "元人民币" << std::endl;
        std::cout << "请选择您要购买的物品:" << std::endl;
        std::cout << "1.手机 1000元" << std::endl;
        std::cout << "2.面包 5元" << std::endl;
        std::cout << "3.矿泉水 1元" << std::endl;
        std::cout << "4.药品 30元" << std::endl;
        std::cout << "5.饮料 3元" << std::endl;
        std::cout << "6.肉食 2元" << std::endl;
        std::cout << "7.水果 10元" << std::endl;
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
    if(game.player.getMoney() >= price)
    {

        std::cout << "购买成功!" << std::endl;
        packet[name] += 1;
        game.player.spendMoney(price);
    }
    else
    {
        std::cout << "余额不足!" << std::endl;
    }

}


bool Backpack::useItem(std::string name,Game& game) {
    auto it = packet.find(name);
    if (it == packet.end() || it->second <= 0) {
        std::cout << "没有这个物品！" << std::endl;
        return false;
    }
    else
    {
        if(name == "面包")
        {
            std::cout << "你吃了几口面包感觉非常美味 饥饿值 + 60 面包 - 1" << std::endl;
            packet[name] -= 1;
            game.player.earnHunger(60);
        }
        else if(name == "手机")
        {
            std::cout << "你拿起手机打开游戏当打手带着老板千万撤离 hp - 5 Money + 200" << std::endl;
            game.player.spendHp(5,true);
            game.player.earnMoney(200);
            if(game.player.getDead())
            {
                return false;
            }
        }
        else if(name == "药品")
        {
            std::cout << "药很苦但你很快就恢复了健康 hp = 100 药品 - 1" << std::endl;
            packet[name] -= 1;
            game.player.earnHp(100);
        }
        else if(name == "矿泉水")
        {
            std::cout << "只是普通的水而已 口渴值 + 60" << std::endl;
            packet[name] -= 1;
            game.player.earnThirst(60);
        }
        else if(name == "饮料")
        {
            std::cout << "非常的好喝的饮料 口渴值 + 40 饮料 - 1" << std::endl;
            packet[name] -= 1;
            game.player.earnThirst(40);
        }
        else if(name == "肉食")
        {
            std::cout << "非常的好吃的肉食 饥饿值 + 50 肉食 - 1" << std::endl;
            packet[name] -= 1;
            game.player.earnHunger(50);
        }
        else
        {
            std::cout << "非常的好吃的水果 饥饿值 + 25 水果 - 1" << std::endl;
            packet[name] -= 1;
            game.player.earnHunger(25);
        }
        
    }
    return true;
    
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
        std::cout << "1.手机" << std::endl;
        std::cout << "2.面包" << std::endl;
        std::cout << "3.矿泉水" << std::endl;
        std::cout << "4.药品" << std::endl;
        std::cout << "5.饮料" << std::endl;
        std::cout << "6.肉食" << std::endl;
        std::cout << "7.水果" << std::endl;
        std::cout << "0.退出\n" << std::endl;
        std::cin >> input;
        if(input == "1")
        {
            exitMenu = useItem("手机",game);
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
    std::cout << "当前版本为:" << VERSION_DISPLAY << std::endl;
    do {
        running = game.player.checkGoal();
        if(!running)
        {
            return false;
        }
        
        std::cout
                << "当前余额:" << game.player.getMoney() << "元人民币" << std::endl
                << "当前血量:" << game.player.getHp() << "/100" << std::endl
                << "当前饥饿值:" << game.player.getHunger() << "/100 当前口渴值:" << game.player.getThirst() << "/100" << std::endl
                << "当前天数第:" << game.player.getDays() << "天" << std::endl
                << "1.打工(日结)" << std::endl
                << "2.查看背包内物品" << std::endl
                << "3.丢掉背包内物品" << std::endl
                << "4.购买物品" << std::endl
                << "5.使用物品" << std::endl
                << "6.结束一天" << std::endl
                << "7.购买彩票" << std::endl
                << "8.保存存档" << std::endl
                << "9.加载存档" << std::endl
                << "10.检查更新" << std::endl
                << "0.退出" << std::endl;
        std::cin >> input;
        if(input == "1")
        {
            game.player.earnMoney(game.work());
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
            std::cout << "第" << game.player.getDays() << "天结束了" << std::endl;
            if(game.player.getHunger() >= 30)
            {
                std::cout << "饥饿值 - 30"<< std::endl;
                game.player.spendHunger(30);
            }
            else
            {
                std::cout << "由于饥饿值不足30所以扣除血量15" << std::endl;
                game.player.spendHp(15);
            }
            if(game.player.getThirst() >= 30)
            {
                std::cout << "口渴值 - 30"<< std::endl;
                game.player.spendThirst(30);
            }
            else
            {
                std::cout << "由于口渴值不足30所以扣除血量15" << std::endl;
                game.player.spendHp(15);
            }
            game.player.earnDays();
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
        else if(input == "8")
        {
            game.saveGame();
        }
        else if(input == "9")
        {
            game.loadGame();
        }
        else if(input == "10")
        {
            if(game.sendVersion() == true) {
                std::cout << "发现新版本请前往:" << SERVER << "下载" << std::endl;
            }
            else
            {
                std::cout << "未发现新版本" << std::endl;
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
        if(game.player.getDead())
        {
            return false;
        }

    }
    while(running);


}