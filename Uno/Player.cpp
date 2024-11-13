#include "Player.h"
#include "graphics.h"
#include "Game.h"
#include "Cards.h"
#include <vector>



void Player::ActivatePlayer()
{
	active = true;
}

bool Player::PlayerState()
{
	return active;
}

int Player::GivePlayer()
{
	return nplayers;
}

Player::Player(const Game & mygame)
	: GameObject(mygame)
{
	

}

/*void Player::GetPlayers(int i)
{
	nplayer = i;
}*/

void Player::filldeck(std::string str)
{
	
		playercardvector.push_back(str);
	
}

void Player::getMiddle(std::string str)
{
	Middle = str;
}

std::string Player::giveMiddle()
{
	return Middle;
}

std::string Player::Match(std::string card)
{
			
	std::string c= "CARD" ;
	std::string t= "TT" ;
	std::string xrwma= "CHROMA" ;
	bool flag = false;
	if (card != "CHROMA" && card != "TT")
	{
		if (card.substr(0, 4) == c)
		{
			if (card.at(5) == Middle.at(1) || card == Middle || card.at(5) == Middle.at(5) || card.at(4) == Middle.at(4) || card == Middle)
			{
				Middle = card;
				if (playercardvector[playercardvector.size() - 1] == Middle && flag==false)
				{
					playercardvector.pop_back();
					flag = true;
				}
				else
				{
					for (int i = 0; i < playercardvector.size() - 1; i++)
					{
						if (playercardvector[i] == Middle && flag == false)
						{
							playercardvector[i] = playercardvector[playercardvector.size() - 1];
							playercardvector.pop_back();
							flag = true;
						}
					}
				}
				match = card;
				takepunishment = false;
				tookcard = false;
				previousplayerpass = false;
				pass = false;
				active = false;

			}
		}

		else if (card.at(0) == Middle.at(0) || card.at(1) == Middle.at(1) || card.at(1) == Middle.at(5))
		{
			Middle = card;
			if (playercardvector[playercardvector.size() - 1] == Middle && flag==false)
			{
				playercardvector.pop_back();
				
				flag = true;
			}
			else
			{
				for (int i = 0; i < playercardvector.size() - 1; i++)
				{
					if (playercardvector[i] == Middle && flag == false) {
						playercardvector[i] = playercardvector[playercardvector.size() - 1];
						playercardvector.pop_back();
						
						flag = true;
					}
				}
			}
			match = card;
			takepunishment = false;
			tookcard = false;
			previousplayerpass = false;
			pass = false;
			active = false;

		}
		else {
			match = " "; 
			active = true;

		}

	}
	
	else 
	{
		Middle=card;
		ischroma=true;
		if (playercardvector[playercardvector.size() - 1] == Middle && flag==false)
		{
			playercardvector.pop_back();
			
			flag = true;
		}
		else
		{
			for (int i = 0 ; i < playercardvector.size() - 1; i++)
			{
				if(playercardvector[i] == Middle && flag==false) 
				{
					
					
			
					playercardvector[i] = playercardvector[playercardvector.size() - 1];
					playercardvector.pop_back();
					
					flag = true;
				}
			}
		}
		

		 
			match = card;
			takepunishment = false;
			previousplayerpass = false;
			tookcard = false;
			pass = false;
			

	}


		

	

	return match;
}

float Player::distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx*dx + dy * dy);
}

bool Player::contains(float mx, float my, float x, float y)
{
	return distance(mx, my, x, y) < 20;
}

bool Player::givePass()
{
	return pass;
}

void Player::getPass()
{
	previousplayerpass = true;
}

std::string Player::giveMatch()
{
	return match;
}

void Player::SetPreviousMatch(std::string card)
{
	previousmatch = card;
}

void Player::deactivatePreviousMatch()
{
	previousmatch=" " ;
}

void Player::deactivateMatch()
{
	match = " ";
}

void Player::DeactivatePreviousPass()
{
	previousplayerpass = false;
}

bool Player::giveReverse()
{
	return reverse;
}

void Player::DeactivateReverse()
{
	reverse=false;
}


bool Player::giveTakeCard()
{
	return takecard;
}

bool Player::giveTake4()
{
	return take4;
}

void Player::endTake4()
{
	take4 = false;
}

bool Player::giveTake2()
{
	return take2;
}

void Player::endTake2()
{
	take2 = false;
}

void Player::DeactivatePass()
{
	pass = false;
}

void Player::DeactivateTakeCard()
{
	takecard = false;
}

void Player::clearcardclick()
{
	cardclick.clear();
}

bool Player::givereadmiddle()
{
	return readmiddle;
}

void Player::readmiddletrue()
{
	readmiddle = true;
}

void Player::readmiddlebacktofalse()
{
	readmiddle = false;
}

bool Player::giveChroma()
{
	return chroma;
}

void Player::endChroma()
{
	chroma = false;
}

void Player::update()
{
	if (playercardvector.size() == 1) {
		

	}
	if (playercardvector.size() == 0) {
		
		active = false;
	}
	else {
		
		
	}
	
	
	if (active == true)
	{
		if (chroma == true)
		{
			chroma = false;
			ischroma = false;
			active = false;
		}
		pass = false;
		graphics::Brush brush;
		char info[40];
		sprintf_s(info, (Middle).c_str());
		brush.fill_color[0] = 0.0f;
		brush.fill_color[1] = 1.0f;
		brush.fill_color[2] = 0.0f;
		//graphics::drawText(CANVAS_WIDTH / 2-150, CANVAS_HEIGHT / 2, 100, info, brush);
	
		
		graphics::MouseState ms;
		graphics::getMouseState(ms);
		
		
		if ((Middle == "A222A2"|| Middle == "A111A1"|| Middle == "A444A4"|| Middle == "A333A3") && previousmatch =="TT" && takepunishment == false)
		{
			take4=true;
			takepunishment = true;
		}
		if ((Middle == "P1" || Middle == "P2" || Middle == "P3" || Middle == "P4") && (previousmatch == "P1" || previousmatch == "P2" || previousmatch == "P3" || previousmatch == "P4") && takepunishment == false)
		{
			take2 = true;
			takepunishment = true;
		}
		if ((Middle == "N1" || Middle == "N2" || Middle == "N3" || Middle == "N4") && (previousmatch == "N1" || previousmatch == "N2" || previousmatch == "N3" || previousmatch == "N4"))
		{
			cardclick.clear();
			previousplayerpass = false;
			match = " ";
			pass = true;
			active = false;

		} 


		if ((Middle == "R1" || Middle == "R2" || Middle == "R3" || Middle == "R4") && (previousmatch == "R1" || previousmatch == "R2" || previousmatch == "R3" || previousmatch == "R4"))
		{
			reverse = true;
			
		}
		

		
		float mx = graphics::windowToCanvasX(ms.cur_pos_x);
		float my = graphics::windowToCanvasY(ms.cur_pos_y);
		int k1 = 0;
		if (!cardclick.empty())
		{
			for (int i = 0; i <= playercardvector.size() ; i++)
			{
				if (contains(mx, my, cardclick[k1], cardclick[k1 + 1]))     
				{
					/*brush.fill_color[0] = 1.0f;
					brush.fill_color[1] = 0.0f;
					brush.fill_color[2] = 0.0f;
					graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 100, info, brush);*/
					if (ms.button_left_pressed) {
						if (cardclick[k1] == CANVAS_WIDTH / 2 + 90 && cardclick[k1+1] == CANVAS_HEIGHT / 2  && tookcard==false)
						{
							takecard = true;
							tookcard = true;
						}
						else if (cardclick[k1] == CANVAS_WIDTH / 2 + 90 && cardclick[k1+1] == CANVAS_HEIGHT / 2 && tookcard == true) 
						{ tookcard = true; }
						
						else {
							Match(playercardvector[i]);
						}
					}
				}
				k1 = k1 + 2;
				if (graphics::getKeyState(graphics::SCANCODE_SPACE) && tookcard==true)
				{
					previousplayerpass = false;
					pass = true;
					match = " ";
					tookcard = false;
					takepunishment = false;
					active = false;
				}
			}
		}
	}
	
	
}

void Player::draw(int player, float r,float g , float b)
{
	cardclick.clear();
	float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime() / 1000);
	if (player == 1)
	{
	graphics::Brush br;

	
	//gloss
	br.fill_color[0] =	r;
	br.fill_color[1] = g + glow * 0.5f;
	br.fill_color[2] = b;
	br.fill_opacity = 1.0f;
	br.fill_secondary_opacity = 0.0f;
	br.outline_opacity = 0.0f;
	graphics::drawDisk(pos_x, (pos_y*1.7)+15, 20, br);
	
	//drawing player
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH) + "player1.png";
	brush.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y*1.7f, 100, 100, brush);
	//drawing cards
	int k = 0; 
	int x = (playercardvector.size() - 7) * 50/4;
	for (int i = 0; i < playercardvector.size(); i++)
	{		
		if (active == true) {
			if (r == 1 && b == 0) { nplayers = 1; }
			if (g == 1) { nplayers = 2; }
			if (b == 1 && r == 0) { nplayers = 3; }
			if (r == 1 && b == 1) { nplayers = 4; }
			std::string a = ("Player " + std::to_string(nplayers));
			char inf[40];
			sprintf_s(inf, a.c_str());
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 0.0f;
			br.fill_color[2] = 1.0f;
			graphics::drawText(900, 650, 50, inf, br);
			graphics::Brush brsh;
			brsh.texture = std::string(ASSET_PATH) + std::string(playercardvector[i]) + ".png";
			brsh.outline_opacity = 0.0f;
			graphics::drawRect((pos_x - 250-x) + k, pos_y*1.4f, 60, 80, brsh);
			cardclick.push_back((pos_x - 250-x) + k); 
			cardclick.push_back(pos_y*1.4f); 
			k = k + 50;
			//karta gia paso
			if (i == playercardvector.size() - 1) {
				graphics::Brush brsh;
				brsh.texture = std::string(ASSET_PATH) + std::string("behind.png");
				brsh.outline_opacity = 0.0f;
				graphics::drawRect(CANVAS_WIDTH / 2 + 90, CANVAS_HEIGHT / 2, 60, 80, brsh);
				cardclick.push_back(CANVAS_WIDTH / 2 + 90);
				cardclick.push_back(CANVAS_HEIGHT / 2);
			}
			if (Middle == "CHROMA" || Middle=="TT")
			{
				char info[40];
				std::string b = "red->1 green->2 blue->3 yellow->4";
				sprintf_s(info, b.c_str());
				br.fill_color[0] = 0.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 0.0f;
				graphics::drawText(pos_x +150, pos_y*1.7f-30, 40, info, br);
				graphics::Brush brush;
				brush.texture = std::string(ASSET_PATH) + "colorchoice.png";
				brush.outline_opacity = 0.0f;
				graphics::drawRect(CANVAS_WIDTH / 2-130, CANVAS_HEIGHT / 2-30,150, 150, brush);
				if (graphics::getKeyState(graphics::SCANCODE_3))
				{
					Middle = "A333A3";
					chroma = true;
					//active = false;

				}
				if (graphics::getKeyState(graphics::SCANCODE_1))
				{
					Middle = "A111A1";
					chroma = true;
					//active = false;

				};
				if (graphics::getKeyState(graphics::SCANCODE_4))
				{
					Middle = "A444A4";
					chroma = true;
					//active = false;

				}
				if (graphics::getKeyState(graphics::SCANCODE_2))
				{
					Middle = "A222A2";
					chroma = true;
					//active = false;

				}
				//active = false;
				 
			}

		}
		else 
		{
			if (playercardvector.size()==1) {
				graphics::Brush brush;

					brush.fill_color[0] = 1.0f;
					brush.fill_color[1] = 0.0f;
					brush.fill_color[2] = 0.0f;
					br.fill_opacity = 1.0f;
					br.fill_secondary_opacity = 0.0f;
					br.outline_opacity = 0.0f;
					brush.texture = std::string(ASSET_PATH) + /*std::string(playervector[i])*/ +"1card.png";;
					graphics::drawRect((pos_x - 250) + k, pos_y*1.4f + 80, 20, 20, br);
			}
			graphics::Brush brsh;
			brsh.texture = std::string(ASSET_PATH) + std::string("behind.png");
			brsh.outline_opacity = 0.0f;
			graphics::drawRect((pos_x - 250) + k, pos_y*1.4f, 60, 80, brsh);
			k = k + 30;
		}
	}
	}	
	if (player == 3)
	{
		graphics::Brush br;
		//gloss
		br.fill_color[0] = r ;
		br.fill_color[1] = g;
		br.fill_color[2] = b;
		br.fill_opacity = 1.0f;
		br.fill_secondary_opacity = 0.0f;
		br.outline_opacity = 0.0f;
		graphics::drawDisk(pos_x, (pos_y/3)+15, 20, br);

		//drawing player
		graphics::Brush brush;
		brush.texture = std::string(ASSET_PATH) + "player1.png";
		brush.outline_opacity = 0.0f;
		graphics::drawRect(pos_x, pos_y / 3, 100, 100, brush);
		//drawing cards
		int k = 0;
		for (int i = 0; i < playercardvector.size(); i++)
		{
			if (active == true)
			{
				graphics::Brush brsh;
				brsh.texture = std::string(ASSET_PATH) + std::string(playercardvector[i]) +".png";
				brsh.outline_opacity = 0.0f;
				graphics::drawRect((pos_x - 250) + k, pos_y / 2.3f, 40, 60, brsh);
				cardclick.push_back(pos_x - 250 + k ); 
				cardclick.push_back(pos_y/2.3f ); 
				k = k + 30;
				//karta gia paso
				if (i == playercardvector.size() - 1) {
					graphics::Brush brsh;
					brsh.texture = std::string(ASSET_PATH) + std::string("behind.png");
					brsh.outline_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH / 2 + 90, CANVAS_HEIGHT / 2, 60, 80, brsh);
					cardclick.push_back(CANVAS_WIDTH / 2 + 90);
					cardclick.push_back(CANVAS_HEIGHT / 2);
				}
			}
			else
			{
				if (playercardvector.size()==1) {
					graphics::Brush brush;
					br.outline_opacity = 0.0f;
					br.outline_opacity = 0.0f;
					brush.texture = std::string(ASSET_PATH) + /*std::string(playervector[i])*/ +"1card.png";;
					graphics::drawRect((pos_x - 250) + k, pos_y / 2.3f -60, 30, 30, brush);
				}
				graphics::Brush brsh;
				brsh.texture = std::string(ASSET_PATH) + /*std::string(playervector[i])*/ +"behind.png";
				brsh.outline_opacity = 0.0f;
				graphics::drawRect((pos_x - 250) + k, pos_y / 2.3f, 25, 50, brsh);
				k = k + 12;
			}
		}
	}
	if (player == 4)
	{
		graphics::Brush br;
		//gloss
		br.fill_color[0] = r;
		br.fill_color[1] = g ;
		br.fill_color[2] = b;
		br.fill_opacity = 1.0f;
		br.fill_secondary_opacity = 0.0f;
		br.outline_opacity = 0.0f;
		graphics::drawDisk(pos_x/4, pos_y+15, 20, br);

		//drawing player
		graphics::Brush brush;
		brush.texture = std::string(ASSET_PATH) + "player1.png";
		brush.outline_opacity = 0.0f;
		graphics::drawRect(pos_x / 4, pos_y, 100, 100, brush);
		
		//drawing cards
		int k = 0;
		for (int i = 0; i < playercardvector.size(); i++)
		{
			if (active == true)
			{
				graphics::Brush brsh;
				brsh.texture = std::string(ASSET_PATH) + std::string(playercardvector[i]) +".png";
				brsh.outline_opacity = 0.0f;
				graphics::setOrientation(270);
				graphics::drawRect((pos_x / 4 + 100), pos_y - 40 + k, 25, 50, brsh);
				graphics::resetPose();
				cardclick.push_back(pos_x / 4 + 100);
				cardclick.push_back(pos_y - 40 + k);
				k = k + 12;
				//karta gia paso
				if (i == playercardvector.size() - 1) {
					graphics::Brush brsh;
					brsh.texture = std::string(ASSET_PATH) + std::string("behind.png");
					brsh.outline_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH / 2 + 90, CANVAS_HEIGHT / 2, 60, 80, brsh);
					cardclick.push_back(CANVAS_WIDTH / 2 + 90);
					cardclick.push_back(CANVAS_HEIGHT / 2);
				}
			}
			else
			{
				if (playercardvector.size()== 1) {
					graphics::Brush brush;
					brush.fill_opacity = 1.0f;
					brush.texture = std::string(ASSET_PATH) + /*std::string(playervector[i])*/ +"1card.png";
					graphics::drawRect((pos_x / 4 + 100 + 60), pos_y - 40 , 30, 30, brush);
				}
				graphics::Brush brsh;
				brsh.texture = std::string(ASSET_PATH) + std::string("behind.png");
				brsh.outline_opacity = 0.0f;
				graphics::setOrientation(270);
				graphics::drawRect((pos_x / 4 + 100), pos_y - 40 + k, 25, 50, brsh);
				graphics::resetPose();
				k = k + 12;
			}
		}
	}
	if (player == 2)
	{
		graphics::Brush br;
		//gloss
		br.fill_color[0] = r;
		br.fill_color[1] = g;
		br.fill_color[2] = b ;
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;
		br.fill_secondary_opacity = 0.0f;
		graphics::drawDisk(pos_x*1.75f, pos_y+15, 20, br);

		//drawing player
		graphics::Brush brush;
		brush.texture = std::string(ASSET_PATH) + "player1.png";
		brush.outline_opacity = 0.0f;
		graphics::drawRect(pos_x*1.75f, pos_y, 100, 100, brush);
		
		//drawing cards
		int k = 0;
		for (int i = 0; i < playercardvector.size(); i++)
		{
			/*if (active == true)
			{
				graphics::Brush brsh;
				brsh.texture = std::string(ASSET_PATH) + std::string(playercardvector[i]) +".png";
				brsh.outline_opacity = 0.0f;
				graphics::setOrientation(90);
				graphics::drawRect((pos_x - 250) + k, pos_y / 2.3f, 40, 60, brsh);
				graphics::resetPose();
				cardclick.push_back((pos_x - 250) + k ); 
				cardclick.push_back(pos_y / 2.3f ); 
				k = k + 30;
				//karta gia paso
				if (i == playercardvector.size() - 1) {
					graphics::Brush brsh;
					brsh.texture = std::string(ASSET_PATH) + std::string("behind.png");
					brsh.outline_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH / 2 + 90, CANVAS_HEIGHT / 2, 60, 80, brsh);
					cardclick.push_back(CANVAS_WIDTH / 2 + 90);
					cardclick.push_back(CANVAS_HEIGHT / 2);
				}
			else
			{*/
			if (playercardvector.size() == 1) {
				graphics::Brush brush;
				brush.fill_opacity = 1.0f;
				brush.texture = std::string(ASSET_PATH) + /*std::string(playervector[i])*/ +"1card.png";
				graphics::drawRect((pos_x *1.45f + 100 -60), pos_y - 40 + k, 30, 30, brush);
			}
				graphics::Brush brsh;
				brsh.texture = std::string(ASSET_PATH) + /*std::string(playervector[i])*/ +"behind.png";
				brsh.outline_opacity = 0.0f;
				graphics::setOrientation(90);
				graphics::drawRect((pos_x *1.45f + 100), pos_y - 40 + k, 25, 50, brsh);
				graphics::resetPose();
				k = k +12;
			//}
		}
	}
	
}

void Player::init()
{
}
