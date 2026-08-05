#include "common.h"

int main() {
    Game game;
    game.randomFamily();
    bool running = true;
    while(running)
    {
        if(game.player.getDead())
        {
            return 0;
        }
        running = menu(game);
    }
}