#include "Game.h"
#include "graphics.h"
#include "Config.h"
#include <string>

Game* Game::m_instance = nullptr;

Game * Game::getInstance()
{
	if (!m_instance)
		m_instance = new Game();
	return m_instance;
}

/*Game & Game::instance()
{
	static Game theInstance;
	return theInstance;
}*/

Player * Game::GetNextPlayer(Player * player) // san orisma to reverse h no h plus h kanoniki karta
{
	std::string mid = player->giveMiddle();
	//bool pass = player->givePass();
	//if (player->giveReverse()==false){

	
	for (int i =0 ; i<=playervector.size()-1;i++)
	{
		if (playervector[i] == player && i<playervector.size()-1)
		{
			//if no return playervector[i+2];
			//if reverse return playervector[i-1];
			//if kanoniki i p return:
			return playervector[i+1];
		}
		else if (playervector[i] == player && i == playervector.size() - 1)
		{
			return playervector[0];
		}
	}
	//}
	/*else{
		for (int i =0 ; i<=playervector.size()-1;i++)
	{
		if (playervector[i] == player && i>0)
		{
			 
			return playervector[i-1];
		}
		else if (playervector[i] == player && i == 0)
		{
			return playervector[4];
		}
	}
		
	}*/
}

void Game::updateStartScreen() {
	if (menu==false)
		nplayers = 2;
	
	if (graphics::getKeyState(graphics::SCANCODE_2))
	{
		nplayers = 2;
		menu = true;
	}
	if (graphics::getKeyState(graphics::SCANCODE_3))
	{
		nplayers = 3;
		menu = true;
	}
	if (graphics::getKeyState(graphics::SCANCODE_4))
	{
		nplayers = 4;
		menu = true;
	}
	
	
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
	}
}

void Game::updateGameScreen() {
	if (graphics::getGlobalTime() > 1000 && player_initialized == false)
	{
		/*for (int i = 1; i <= nplayers; i++)
				player = new Player();*/

		player_initialized = true;

		cards = new Cards();
		if (cards)
		{
			cards->init();
			cards->shuffle();
		}
		if (nplayers == 2)
		{
			player1 = new Player(*this);
			playervector.push_back(player1);
			
			fillmylist(player1);
			currplayer = player1;
			previousplayer = player1;

			player2 = new Player(*this);
			
			playervector.push_back(player2);
			fillmylist(player2);
			colorpallete.resize(6);
		}
		if (nplayers == 3)
		{

			player1 = new Player(*this);
			
			playervector.push_back(player1);
			fillmylist(player1);
			currplayer = player1;
			previousplayer = player1;
			player2 = new Player(*this);
			
			playervector.push_back(player2);
			fillmylist(player2);
			player3 = new Player(*this);
			
			playervector.push_back(player3);
			fillmylist(player3);
			colorpallete.resize(9);
		}
		if (nplayers == 4)
		{

			player1 = new Player(*this);
			
			playervector.push_back(player1);
			fillmylist(player1);
			currplayer = player1;
			previousplayer = player1;
			player2 = new Player(*this);
			
			playervector.push_back(player2);
			fillmylist(player2);
			player3 = new Player(*this);
			playervector.push_back(player3);
			
			fillmylist(player3);
			player4 = new Player(*this);
			
			playervector.push_back(player4);
			fillmylist(player4);
		}


	}
	 
	/*graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);*/
	
	for (auto i : playervector)
	{
		if (i == currplayer)
		{
			i->ActivatePlayer();
		}
	}
	
	
	int a = 0;
	if (player1){
		for (auto i : playervector)
		{
			//i->update(); 
			CheckPreviousMatch(i);
			i->update();
			cards->update(); 
			if (i == currplayer)
			{
				//CheckPreviousMatch(i);
				//i->update();
				TakeMiddle(currplayer,mid);
				//setChroma(i);
				TakeCard(i);
				TakeCard2(i);
				TakeCard4(i);
				//TakeCard4(currplayer);
				mid= currplayer->giveMiddle();
				ChangeSeats(currplayer);
				if ((currplayer->playercardvector.size()) == 0)
				{
					status = STATUS_END;
				}
				//cards->drawMiddle(mid);
				//if (mid!="")
				//mid= currplayer->giveMiddle();
				 

			}
			a = a + 1;
		}
	}


	if (player1) {
		if (currplayer->PlayerState() == false)
		{
			cards->drawMiddle(mid);
			previousplayer = currplayer;
			previousplayer->readmiddlebacktofalse();
			currplayer = Game::GetNextPlayer(currplayer);
		}

	}

	//cards->drawMiddle(mid);

	//cards->drawMiddle(mid);
	/*if (player1)
	{
		player1->update();
	}
	if (player2)
	{
		player2->update();
	}
	if (player3)
	{
		player3->update();
	}
	if (player4)
	{
		player4->update();
	}*/

	
	/*graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);*/
}

void Game::DrawStartScreen()
{
	graphics::Brush brush;
	char info[40];
	sprintf_s(info, "Choose no players and press ENTER");
	graphics::drawText(CANVAS_WIDTH/2.7f , CANVAS_HEIGHT/4.5f, 40, info, brush);

	sprintf_s(info, "2 Players - Press 2 ");
	graphics::drawText(CANVAS_WIDTH / 2.7f, CANVAS_HEIGHT / 2.3f, 40, info, brush);

	sprintf_s(info, "3 Players - Press 3");
	graphics::drawText(CANVAS_WIDTH / 2.7f, CANVAS_HEIGHT / 2.05f, 40, info, brush);

	sprintf_s(info, "4 Players - Press 4");
	graphics::drawText(CANVAS_WIDTH / 2.7f, CANVAS_HEIGHT / 1.85f, 40, info, brush);

	brush.texture = std::string(ASSET_PATH) + "menu.png";
	brush.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 /*+ offset*/, CANVAS_WIDTH, CANVAS_HEIGHT, brush);
}


void Game::DrawEndScreen()
{
	graphics::Brush brush;
	char info[40];
	sprintf_s(info, "GAME OVER");
	graphics::drawText(CANVAS_WIDTH/2 -100, CANVAS_HEIGHT/2 + 60, 40, info, brush);

	for (int i = 0; i <= playervector.size() - 1; i++)
	{
		if (playervector[i]->playercardvector.size() == 0)
		{
			winner = playervector[i]->GivePlayer();
		}
	}

	sprintf_s(info, std::to_string(winner).c_str());
	graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2.0, 40, info, brush);


	sprintf_s(info, "YOU WON PLAYER");
	graphics::drawText(CANVAS_WIDTH / 2-100, CANVAS_HEIGHT / 2 - 60, 40, info, brush);

	sprintf_s(info, "PRESS ESCAPE TO EXIT");
	graphics::drawText(CANVAS_WIDTH / 2-100, CANVAS_HEIGHT / 2 - 120, 40, info, brush);
	
	brush.texture = std::string(ASSET_PATH) + "end.png";
	brush.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2-100, CANVAS_HEIGHT / 2 /*+ offset*/, CANVAS_WIDTH, CANVAS_HEIGHT, brush);

	if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
	{
		Game::~Game();
	}
}






void Game::DrawGameScreen()
{
if (status == STATUS_PLAYING)
{
	
		graphics::Brush brush;
		brush.texture = std::string(ASSET_PATH) + "background.png";
		brush.outline_opacity = 0.0f;

		//float offset = CANVAS_HEIGHT * sinf(graphics::getGlobalTime()/1000.0f)/4;    GIA NA KOUNIETAI TO BAGKGROUND ARGA PANW KATW

		//draw background
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 /*+ offset*/, CANVAS_WIDTH, CANVAS_HEIGHT, brush);

		/*std::string ans = std::to_string(int(colorpallete[0]));
		std::string ans1 = std::to_string(int(colorpallete[1]));
		std::string ans2 = ans + ans1 + std::to_string(int(colorpallete[2]));
		graphics::Brush brsh;
		char info[40];
		sprintf_s(info, ans2.c_str());
		brsh.fill_color[0] = 1.0f;
		brsh.fill_color[1] = 0.0f;
		brsh.fill_color[2] = 0.0f;
		graphics::drawText(CANVAS_WIDTH / 2 - 200, CANVAS_HEIGHT / 2, 100, info, brsh);*/

		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "turn.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(960, 645, 200, 80, br);
		char info[40];
		std::string c = "Pass -> SPACEBAR";
		sprintf_s(info, c.c_str());
		br.fill_color[0] = 0.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		graphics::drawText(CANVAS_WIDTH / 2 - 100, 690, 40, info, br);

		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		br.texture = std::string(ASSET_PATH) + std::string("draw.png");
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2 + 200, CANVAS_HEIGHT / 2, 120, 120, br);

		//draw player
		if (player1) 
		{
			int k = 1;
			int x = 0;


			for (auto i : playervector)
			{
				i->draw(k, colorpallete[x], colorpallete[x + 1], colorpallete[x + 2]);
				k++;
				x = x + 3;
			}

		}

		if (cards) {
			if (middlecard_initialized == false)
			{
				mid = cards->TakeaCard();
				currplayer->getMiddle(mid);
				middlecard_initialized = true;
				
			}

		}
		cards->drawMiddle(mid);
	}
else {
	DrawEndScreen();
}

}


void Game::init() 
{
	graphics::setFont(std::string(ASSET_PATH) + "fonts.ttf");
	graphics::playMusic(std::string(ASSET_PATH) +"Ducktales.mp3",0.01f,true,4000);
}

void Game::fillmylist(Player* player)
{
	for (int i = 1; i <= 7; i++) 
	{
	std::string str = Game::cards->TakeaCard();
	player->filldeck(str);
	}
}

/*void Game::setChroma(Player * player)
{
	if (player->giveChroma())
	{
		player->DeactivateTakeCard();
		bool choose = false;
		while (choose==false)
		{
			graphics::Brush brush;
			brush.texture = std::string(ASSET_PATH) + "colorchoice.png";
			brush.outline_opacity = 0.0f;
			graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 100, 100, brush);

			if (graphics::getKeyState(graphics::SCANCODE_2))
			{
				player->getMiddle("A333A3");
				choose = true;

			}
			if (graphics::getKeyState(graphics::SCANCODE_2))
			{
				player->getMiddle("A111A1");
				choose = true;

			};
			if (graphics::getKeyState(graphics::SCANCODE_2))
			{
				player->getMiddle("A444A4");
				choose = true;

			}
			if (graphics::getKeyState(graphics::SCANCODE_2))
			{
				player->getMiddle("A222A2");
				choose = true;

			}


		}
		
		player->endChroma();
	}
}*/

/*void Game::Pass(Player * player)
{
	if (previousplayer->givePass())
	{
		player->getPass();
		previousplayer->DeactivatePass();
		//previousplayer->DeactivatePreviousPass();
	}
	/*else {
		player->DeactivatePreviousPass();
	}*/

	//player->update();
//}

void Game::TakeCard(Player * player)
{
	if (player->giveTakeCard())
	{
		player->DeactivateTakeCard();
		std::string str = Game::cards->TakeaCard();
		player->filldeck(str);
		player->clearcardclick();
	}
}

void Game::ChangeSeats(Player * player)
{
	if (player->PlayerState() == false)
	{
		if (player->giveReverse() == true) {
			//std::reverse(playervector.begin(), playervector.end());
			int k = 0;
			for (int i = 0; i <= playervector.size() - 1; i++)
			{
				std::reverse(colorpallete.begin() + k , colorpallete.begin() + k + 3);
				k = k + 3;
			}
			std::reverse(playervector.begin(), playervector.end());
			std::reverse(colorpallete.begin(), colorpallete.end());
			player->DeactivateReverse();
		}
			int k = 0;
			for (int i = 0; i <= playervector.size() - 1; i++)
			{
				if (playervector[i] == player && i < playervector.size() - 1)
				{
					Player* temp = playervector[i];
					playervector[i] = playervector[i + 1];
					playervector[i + 1] = temp;
					std::swap(colorpallete[k], colorpallete[k + 3]);
					std::swap(colorpallete[k + 1], colorpallete[k + 4]);
					std::swap(colorpallete[k + 2], colorpallete[k + 5]);

				}
				else if (playervector[i] == player && i == playervector.size() - 1)
				{
					Player* temp = playervector[0];
					playervector[0] = playervector[i + 1];
					playervector[i + 1] = temp;
					std::swap(colorpallete[k], colorpallete[k + 3]);
					std::swap(colorpallete[k + 1], colorpallete[k + 4]);
					std::swap(colorpallete[k + 2], colorpallete[k + 5]);
				}
				k = k + 3;
			}
		}
		/*else {
			int k = 0;
			for (int i = 0; i <= playervector.size() - 1; i++)
			{
				if (playervector[i] == player && i < playervector.size() - 1)
				{
					Player* temp = playervector[i];
					playervector[i] = playervector[i + 1];
					playervector[i + 1] = temp;
					std::swap(colorpallete[k], colorpallete[k - 3]);
					std::swap(colorpallete[k + 1], colorpallete[k - 2]);
					std::swap(colorpallete[k + 2], colorpallete[k - 1]);

				}
				else if (playervector[i] == player && i == playervector.size() - 1)
				{
					Player* temp = playervector[0];
					playervector[0] = playervector[i + 1];
					playervector[i + 1] = temp;
					std::swap(colorpallete[k], colorpallete[k - 3]);
					std::swap(colorpallete[k + 1], colorpallete[k - 2]);
					std::swap(colorpallete[k + 2], colorpallete[k - 1]);
				}
				k = k + 3;

			}
		}*/
	//}
}

void Game::TakeCard2(Player * player)
{
	if (player->giveTake2())
	{
		std::string str4 = Game::cards->TakeaCard();
		player->filldeck(str4);
		std::string str5= Game::cards->TakeaCard();
		player->filldeck(str5);
		player->endTake2();
	}
}

void Game::TakeCard4(Player * player)
{
	if (player->giveTake4())
	{
		std::string str = Game::cards->TakeaCard();
		player->filldeck(str);
		std::string str1 = Game::cards->TakeaCard();
		player->filldeck(str1);
		std::string str2 = Game::cards->TakeaCard();
		player->filldeck(str2);
		std::string str3 = Game::cards->TakeaCard();
		player->filldeck(str3);
		player->endTake4();
	}
}

void Game::CheckPreviousMatch(Player * player)
{
	if ((previousplayer->giveMatch())!=" ")
	{
		player->SetPreviousMatch(previousplayer->giveMatch());
		previousplayer->deactivatePreviousMatch();
		previousplayer->deactivateMatch();
		//previousplayer->DeactivatePreviousPass();
	}

}

void Game::TakeMiddle(Player * player, std::string mid)
{
	if (!player->givereadmiddle())
	{
		player->getMiddle(mid);
		player->readmiddletrue();
	}
}

/*void Game::Matching(Player * player)
{
	if (player->Match())
	{
		
		player->DeactivateMatch();
		
	}
	//player->update();
}*/


 
void Game::update()
{
	if (status == STATUS_START)
	{
		updateStartScreen();
	}
	else
	{
		updateGameScreen();
		 
	}
}

void Game::Draw() {
	if (status == STATUS_START)
	{
		DrawStartScreen();
	}
	else
	{
		DrawGameScreen();
	}

}


/*Game::Game()
{
}*/

Game::~Game()
{
	if (player1)
	{
		delete player1; delete player2; delete player3; delete player4; delete cards;
		/*delete player;*/
	}
}