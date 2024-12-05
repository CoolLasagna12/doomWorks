#include "display.h"
#include "eadkpp.h"
#include "palette.h"
#include "eadk_vars.h"
#include "player.h"
#include <stdbool.h>

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "doomWorks";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main(int argc, char *argv[])
{
    EADK::Display::pushRectUniform(EADK::Screen::Rect, Black);

    bool running = true;

    Player player;
    
    while (running)
    {
        EADK::Keyboard::State kbdState = EADK::Keyboard::scan();
        running = !kbdState.keyDown(EADK::Keyboard::Key::Home);
        if (keyboardState.keyDown(EADK::Keyboard::Key::Up)) {
            player.move(0, -Player::k_step);
        }
        if (keyboardState.keyDown(EADK::Keyboard::Key::Down)) {
            player.move(0, Player::k_step);
        }
        if (keyboardState.keyDown(EADK::Keyboard::Key::Left)) {
            player.move(-Player::k_step, 0);
        }
        if (keyboardState.keyDown(EADK::Keyboard::Key::Right)) {
            player.move(Player::k_step, 0);
    }
        
    }
}
