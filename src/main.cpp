#include "display.h"
#include "eadkpp.h"
#include "palette.h"
#include "eadk_vars.h"
#include "player.h"
#include "raycasting.h"

int main(int argc, char *argv[])
{
    Raycasting raycasting_obj;

    raycasting_obj.Raycast();

    EADK::Display::pushRectUniform(EADK::Screen::Rect, Black);

    bool running = true;

    Player player;
    
    while (running)
    {
        EADK::Keyboard::State kbdState = EADK::Keyboard::scan();
        running = !kbdState.keyDown(EADK::Keyboard::Key::Home);
        EADK::Timing::msleep(16);
        if (kbdState.keyDown(EADK::Keyboard::Key::Up)) {
            player.move(0,-Player::k_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Down)) {
            player.move(0,Player::k_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Left)) {
            player.move(-Player::k_step,0);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Right)) {
            player.move(Player::k_step,0);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Back)) {
            player.turn(Player::k_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::OK)) {
            player.turn(-Player::k_step);
        }
    }
    return 0;
}
