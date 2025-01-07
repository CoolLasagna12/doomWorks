#include "menu.h"
#include "palette.h"

void drawMenu() {
	EADK::Display::pushRectUniform(EADK::Rect(0, 0, EADK::Screen::Width, EADK::Screen::Height), Black);
	EADK::Display::drawString("Welcome to DoomWorks v0.0.1", EADK::Point{ 10, 10 }, false, White, Black);
	EADK::Display::drawString("Made by RockingCha1r", EADK::Point{ 10, 30 }, false, White, Black);
	EADK::Display::drawString("This game is currently in development.", EADK::Point{ 10, 50 }, false, White, Black);
	EADK::Display::drawString("Maybe you should come back later?", EADK::Point{ 10, 70 }, false, White, Black);
}