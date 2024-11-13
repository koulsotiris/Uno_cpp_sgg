#pragma once
#include "GameObject.h"
#include "config.h"
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Player.h"

static class Cards 
{
	//static Cards * m_instance;
private:
	

	int ncards = 0;
	
public:
	/*static*/ std::vector<std::string> namevector;
	static Cards & instance();
	bool cards_initialized = false;
	//static Cards * getInstance();
	void update();
	Cards();
	void drawPlayer();
	void init();
	void shuffle();
	void drawMiddle(std::string crd);
	std::string TakeaCard();
	~Cards();
};
