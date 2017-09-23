#include "display.hpp"

int main()
{
    Display dis(800, 600, "Hello World");

    while (!dis.isClosed())
    {
        dis.clear(0.1f, 0.2f, 0.3f, 1.0f);
        dis.update();
    }
    return (0);
}