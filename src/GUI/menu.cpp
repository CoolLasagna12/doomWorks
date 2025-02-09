#include "menu.h"
#include "../EADK/palette.h"

void newChoice(int actualChoice) {
    if (actualChoice % 2 == 0) {
        EADK::Display::drawString("> Play", EADK::Point{ 115, 130 }, true, White, Black);
        EADK::Display::drawString("Options", EADK::Point{ 115, 150 }, true, White, Black);
        EADK::Display::pushRectUniform(EADK::Rect(185, 150, 20, 20), Black);
    }
    else {
        EADK::Display::drawString("Play", EADK::Point{ 115, 130 }, true, White, Black);
        EADK::Display::drawString("> Options", EADK::Point{ 115, 150 }, true, White, Black);
        EADK::Display::pushRectUniform(EADK::Rect(155, 130, 20, 20), Black);
    }
}

void drawMenu() {
	EADK::Display::pushRectUniform(EADK::Rect(0, 0, EADK::Screen::Width, EADK::Screen::Height), Black);
	EADK::Display::drawString("DOOMWORKS", EADK::Point{ 115, 10 }, true, White, Black);
	EADK::Display::drawString("Made by RockingCha1r", EADK::Point{ 90, 30 }, false, White, Black);
    EADK::Display::drawString("v0.1.0", EADK::Point{ 278, 230}, false, White, Black);

    bool waitingInput = true;

    int choice = 0;

    EADK::Display::drawString("> Play", EADK::Point{ 115, 130 }, true, White, Black);
    EADK::Display::drawString("Options", EADK::Point{ 115, 150 }, true, White, Black);

    EADK::Timing::msleep(200);

    while (waitingInput) {
        EADK::Keyboard::State firstInput = EADK::Keyboard::scan();
        if (firstInput.keyDown(EADK::Keyboard::Key::Up)) {
            choice -= 1;
            newChoice(choice);
            EADK::Timing::msleep(200);
        }
        if (firstInput.keyDown(EADK::Keyboard::Key::Down)) {
            choice += 1;
            newChoice(choice);
            EADK::Timing::msleep(200);
        }
        if (firstInput.keyDown(EADK::Keyboard::Key::OK)) {
            waitingInput = false;
        }
        if (firstInput.keyDown(EADK::Keyboard::Key::Home)) {
            waitingInput = false;
        }
    }
}