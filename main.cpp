#include "Game.h"

int main()
{
    srand(time(0));
    Game g(500, 500, "Slayer");
    g.run();

    return 0;
}