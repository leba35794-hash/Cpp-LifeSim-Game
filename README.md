[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Cpp-LifeSim-Game

- 一个简单的C++人生模拟游戏

## 特别提醒

- 目前仅支持Linux、Android(Termux)、MacOS等环境，暂未适配 Windows

## 当前版本

- Alpha 0.21

## 游戏功能

- 打工赚钱
- 背包系统
- 彩票系统
- 天数系统
- 目标系统
- 每日随机事件
- 联网检测版本
- 银行系统

## 快速开始

### 如未安装g++ curl git请先安装:

#### Android(Termux)环境安装命令:

```bash
pkg install g++ curl git
```

#### Linux环境安装命令:

```bash
sudo apt install g++ curl git
```

#### MacOS环境安装命令:

```bash
brew install curl git
xcode-select --install
```
### 克隆仓库
```bash
git clone https://github.com/xmg0129/Cpp-LifeSim-Game.git
cd Cpp-LifeSim-Game
```

### 编译命令：

#### Linux、Android(Termux)环境编译命令:

```bash
g++ -std=c++11 -Iinclude src/*.cpp -o game -pthread -lcurl
```

#### MacOS环境编译命令:

```bash
clang++ -std=c++11 -Iinclude src/*.cpp -o game -pthread -lcurl
```

## 运行命令：

```bash
./game
```

注：本项目开发过程中使用了 AI 工具辅助部分代码编写。