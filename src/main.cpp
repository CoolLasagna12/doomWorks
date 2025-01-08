#include "display.h"
#include "eadkpp.h"
#include "palette.h"
#include "eadk_vars.h"
#include "player.h"
#include "raycasting.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    // Les petits textes ont l'air de faire 7 pixels, et les grands 10

    drawMenu();

    Raycasting raycasting_obj;

    raycasting_obj.Raycast();

    bool running = true;

    Player player;
    
    while (running)
    {
        EADK::Keyboard::State kbdState = EADK::Keyboard::scan();
        running = !kbdState.keyDown(EADK::Keyboard::Key::Home);
        if (kbdState.keyDown(EADK::Keyboard::Key::Up)) {
            player.move(Player::k_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Down)) {
            player.move(-Player::k_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Right)) {
            player.turn(Player::k_step);
        }
        if (kbdState.keyDown(EADK::Keyboard::Key::Left)) {
            player.turn(-Player::k_step);
        }
    }
    return 0;
}
