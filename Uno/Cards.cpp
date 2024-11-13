#include "Cards.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>


//std::vector<std::string> Cards::namevector;



Cards & Cards::instance()
{
	static Cards theInstance;
	return theInstance;
}

void Cards::update()
{
	if (namevector.empty()==true){ 
		cards_initialized = false;
		init();}
}



void Cards::drawPlayer()
{

}

void Cards::drawMiddle(std::string crd)
{
	graphics::Brush br;

	//drawing player
	graphics::Brush brush;
	brush.texture = std::string(ASSET_PATH)  +crd+ ".png";
	brush.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, 80, 100, brush);
}

std::string Cards::TakeaCard()
{
	int i= namevector.size();
	std::string x=namevector[i-1];
	namevector.pop_back();
	return x;
	
	//kapws na apodesmeyetai;
}

void Cards::init()
{
	if (cards_initialized == false)
	{
		int k = 0; int i; int j; int x;
		for (x = 1; x <= 2; x++) {
			for (i = 1; i <= 4; i++)
			{
				for (j = 1; j <= 9; j++)
				{
					namevector.push_back("CARD" + std::to_string(j) + std::to_string(i));
					k++;
				}
			}
		}
		for (x = 1; x <= 2; x++)
		{
			for (i = 1; i <= 4; i++)
			{
				namevector.push_back("N" + std::to_string(i));
				k++;
				namevector.push_back("R" + std::to_string(i));
				k++;
				namevector.push_back("P" + std::to_string(i));
				k++;
			}
		}
		for (i = 1; i <= 4; i++)
		{
			namevector.push_back("CARD0" + std::to_string(i));
			k++;
			namevector.push_back("CHROMA");
			k++;
			namevector.push_back("TT");
			k++;
		}
		cards_initialized = true;
	}

}

void Cards::shuffle()
{
		// Initialize seed randomly
		srand(time(0));

		for (int i = 0; i < 108; i++)
		{
			// Random for remaining positions.
			int r = i + (rand() % (108 - i));
			std::string temp;
			temp = namevector[i];
			namevector[i] = namevector[r];
			namevector[r] = temp;
		}
	
}



/*Cards * Cards::m_instance = nullptr;

Cards * Cards::getInstance()
{
	if (!m_instance)
	{
		m_instance = new Cards();
	}
	return m_instance;
}*/
	
Cards::Cards()
{
}

Cards::~Cards()
{
}

