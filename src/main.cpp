#include "display.h"
#include "eadkpp.h"
#include "palette.h"
#include "eadk_vars.h"
#include "player.h"
#include <stdbool.h>

int main(int argc, char *argv[])
{
    EADK::Display::pushRectUniform(EADK::Screen::Rect, Black);

    bool running = true;

    Player player;

    EADK::Display::drawString("doomWorks 0.0.1", EADK::Point{ 10, 0 }, false, White, Black);

    EADK::Display::drawString("inDev version - Made by RockingCha1r", EADK::Point{ 10, 20 }, false, White, Black);
    
    while (running)
    {
        EADK::Keyboard::State kbdState = EADK::Keyboard::scan();
        running = !kbdState.keyDown(EADK::Keyboard::Key::Home);
        EADK::Timing::msleep(16);
        if (kbdState.keyDown(EADK::Keyboard::Key::Up)) {
            player.move(-Player::k_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Down)) {
            player.move(Player::k_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Left)) {
            player.turn(Player::k_turn_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Right)) {
            player.turn(-Player::k_turn_step);
        }
        
    }
}
