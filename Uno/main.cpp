#include "graphics.h"
#include "Game.h"
#include "Config.h"

void update(float ms)
{
	Game * game = Game::getInstance();//reinterpret_cast<Game *>(graphics::getUserData());
	game->update(); //kanonika einai update
}

void draw()
{
	Game * game = Game::getInstance();//reinterpret_cast<Game *>(graphics::getUserData());
	game->Draw(); //kanonika einai draw
}

int main()
{
	Game * mygame = Game::getInstance(); 
	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Uno");

	graphics::setUserData(&mygame);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(CANVAS_WIDTH,CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	mygame->init();// .
	graphics::startMessageLoop();

	return 0;
}