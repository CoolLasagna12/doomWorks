#include "../EADK/eadkpp.h"
#include "../CHARACTERS/player.h"
#include "input_handler.h"

Player player;

void inputHandler() {
    EADK::Keyboard::State kbdState = EADK::Keyboard::scan();
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