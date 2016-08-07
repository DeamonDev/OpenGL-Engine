#include "game_manager.h"
#include "entity.h"
#include "line.h"

int main(int argc, const char *argv[])
{
    GameManager game(1280, 720, "Cyclone3D");
    game.run();

    return 0;
}

