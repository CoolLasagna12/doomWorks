#include "EADK/eadkpp.h"
#include "EADK/palette.h"
#include "EADK/eadk_vars.h"
#include "CHARACTERS/player.h"
#include "RAYCASTING/raycasting.h"
#include "GUI/menu.h"

int main(int argc, char *argv[])
{
    // Petite police : 12x7
    // Grande police : 16x10
    // Merci yaya

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
