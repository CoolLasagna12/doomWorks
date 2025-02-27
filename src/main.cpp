#include "EADK/eadkpp.h"
#include "EADK/eadk_vars.h"
#include "GUI/menu.h"
#include "HANDLERS/graphics_handler.h"
#include "HANDLERS/input_handler.h"

int main(int argc, char *argv[])
{
    drawMenu();

    bool running = true;

    while (running)
    {
        EADK::Keyboard::State kbdState = EADK::Keyboard::scan();
        running = !kbdState.keyDown(EADK::Keyboard::Key::Home);
        inputHandler();
        graphicsHandler();
    }
    return 0;
}
