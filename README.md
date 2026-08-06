[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Cpp-LifeSim-Game

- 一个简单的C++人生模拟游戏

## 特别提醒

- 目前仅支持Linux、Android(Termux)、MacOS等环境，暂未适配 Windows

## 当前版本

- Alpha 0.19

## 游戏功能

- 打工赚钱
- 背包系统
- 彩票系统
- 天数系统
- 目标系统
- 每日随机事件
- 联网检测版本

## 怎么编译

### 如未安装g++ curl请先安装:

#### Android(Termux)环境安装命令:

```bash
pkg install g++ curl
```

#### Linux环境安装命令:

```bash
sudo apt install g++ curl
```

#### MacOS环境安装命令:

```bash
brew install curl
xcode-select --install
```
### 编译命令：

#### Linux、Android(Termux)环境编译命令:

```bash
g++ -std=c++11 Main.cpp events.cpp -o game -pthread -lcurl
```

#### MacOS环境编译命令:

```bash
clang++ -std=c++11 -o game Main.cpp events.cpp -lcurl
```

## 运行命令：

```bash
./game
```

注：本项目开发过程中使用了 AI 工具辅助部分代码编写。