#pragma once
#include "Player.h"
#include "Cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

class Game
{
	static Game * m_instance;
	Game() {}
	
	typedef enum {STATUS_START, STATUS_PLAYING , STATUS_END} status_t;
	
	Player * player1 = nullptr;
	Player * player2 = nullptr;
	Player * player3 = nullptr;
	Player * player4 = nullptr;
	
	
	Player * currplayer = nullptr;
	Player * previousplayer = nullptr;

	bool player_initialized = false;
	bool menu = false;
	bool middlecard_initialized = false;

	std::vector<Player*> playervector;// vector pou periexei paixtes
	std::vector<float> colorpallete{1.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,1.0f,1.0f,0.0f,1.0f};// vector pou periexei paixtes
	
	status_t status = STATUS_START;
	int winner ;


public:
	std::string mid = "";
	Cards * cards = nullptr;
	static Game * getInstance();
	//static Game & instance();
	int nplayers = 0;
	Player* GetNextPlayer(Player* player);
	void updateStartScreen();
	void updateGameScreen();
	void DrawStartScreen();
	void DrawGameScreen();
	void DrawEndScreen();
	void Draw();
	void update();
	void init();
	void fillmylist(Player* player);
	void TakeCard(Player* player);
	void ChangeSeats(Player* player);//experimental
	void TakeCard2(Player* player);
	void TakeCard4(Player * player);
	void CheckPreviousMatch(Player * player);
	void TakeMiddle(Player* player,std::string mid);
	~Game();


};