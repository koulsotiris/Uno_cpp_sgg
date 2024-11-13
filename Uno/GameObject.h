#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>


class GameObject
{
	const class Game & game;
public:
	GameObject(const class Game & mygame);
	virtual void update() = 0;
	virtual void draw(int player, float r,float g,float b) = 0;
	virtual void init() = 0;
};
