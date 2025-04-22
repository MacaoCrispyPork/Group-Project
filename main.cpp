#include <SFML/Graphics.hpp>
#include <thread>
#include <cmath>
#include <math.h>
using namespace std::chrono_literals;
int main()
{
    Game g(500,500,"Slayer");
    g.run();
    return 0;
}