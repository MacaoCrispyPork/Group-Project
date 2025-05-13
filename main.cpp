#include "Game.h"

int main()
{
    srand(time(0));
    Game g(1920, 1080, "Slayer");
    g.run();

    return 0;
}