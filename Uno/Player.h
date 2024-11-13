#pragma once
#include "GameObject.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Cards.h"

class Player : public GameObject
{
	std::string Middle ;
	float pos_x=CANVAS_WIDTH/2, pos_y=CANVAS_HEIGHT/2; //edw exoume douleia na kanoume
	
	std::vector<int>cardclick; //vector me suntetagmenes kartwn
	bool active = false;
	bool pass = false;
	std::string previousmatch=" ";
	std::string match = " ";
	bool tookcard = false;
	bool takecard = false;
	bool reverse = false;
	bool previousplayerpass = false;
	bool takepunishment = false;
	bool chroma = false;
	bool take2 = false;
	bool readmiddle = false;
	bool take4 = false;
	bool ischroma=false;
	int nplayers;
public:
	std::vector<std::string> playercardvector;// vector pou periexei ta xartia tou paixth
	void ActivatePlayer();
	bool PlayerState();
	int GivePlayer();
	Player(const class Game & mygame);
	void update() override;
	void draw(int player, float r,float g,float b ) override;
	void init() override;
	void filldeck(std::string str);
	void getMiddle(std::string str);
	std::string giveMiddle();
	std::string Match(std::string card);
	float distance(float x1, float x2, float y1, float y2);
	bool contains(float mx, float my, float x, float y);
	bool giveTakeCard();
	bool giveTake4();
	void endTake4();
	bool giveTake2();
	void endTake2();
	void DeactivateTakeCard();
	bool givePass();
	void getPass();
	std::string giveMatch();
	void deactivateMatch();
	void SetPreviousMatch(std::string card);
	void deactivatePreviousMatch();
	void DeactivatePreviousPass();
	bool giveReverse();
	void DeactivateReverse();
	void DeactivatePass();
	void clearcardclick();
	bool givereadmiddle();
	void readmiddletrue();
	void readmiddlebacktofalse();
	bool giveChroma();
	void endChroma();
	void drawUno();
	//void DeactivateMatch();
};
