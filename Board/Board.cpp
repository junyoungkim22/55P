#include "Board.h"

Board::Board()
{
	for(int i = 0; i < PIECE_NUM; i++)
	{
		playerPieces[i] = new Piece;
	}

	BoardSpaces[0] = new HealSpace;
	BoardSpaces[0]->setExplainString("Healing!!");

	for(int i = 1; i <= 19; i++)
	{
		if(i % 5 != 0)
		{
			BoardSpaces[i] = new BuildingSpace;
			BoardSpaces[i]->setExplainString("Building");
		}
		else
		{
			BoardSpaces[i] = new HealSpace;
			BoardSpaces[i]->setExplainString("Healing!");
		}
	}
	BoardSpaces[20] = new BuildingSpace;
	BoardSpaces[20]->setExplainString("Building");
	BoardSpaces[21] = new BuildingSpace;
	BoardSpaces[21]->setExplainString("Building");
	BoardSpaces[22] = new HealSpace;
	BoardSpaces[22]->setExplainString("Healing!!");
	BoardSpaces[23] = new BuildingSpace;
	BoardSpaces[23]->setExplainString("Building");
	BoardSpaces[24] = new BuildingSpace;
	BoardSpaces[24]->setExplainString("Building");
	BoardSpaces[25] = new BuildingSpace;
	BoardSpaces[25]->setExplainString("Building");
	BoardSpaces[26] = new BuildingSpace;
	BoardSpaces[26]->setExplainString("Building");
	BoardSpaces[27] = new BuildingSpace;
	BoardSpaces[27]->setExplainString("Building");
	BoardSpaces[28] = new BuildingSpace;
	BoardSpaces[28]->setExplainString("Building");
}

Board::~Board()
{
	for(int i = 0; i < SPACE_NUM; i++)
	{
		delete BoardSpaces[i];
	}

	for(int i = 0; i < PIECE_NUM; i++)
	{
		delete playerPieces[i];
	}
}

void Board::move(int index, int moveNum)
{
	//move piece
	BoardSpaces[playerPieces[index]->getPosition()]->setPieceOn(false);
	playerPieces[index]->move(moveNum);
	BoardSpaces[playerPieces[index]->getPosition()]->setPieceOn(true);


	//this->playerPieces[index].setPosition((current + moveNum) % SPACE_NUM);
}

void Board::update()
{
	for(int i = 0; i < PIECE_NUM; i++)
	{
		BoardSpaces[playerPieces[i]->getPosition()]->effect(playerPieces[i]);
	}
}

//draw current board state
void Board::draw()
{
	std::cout << std::string(70, '\n');
	for(int i = 0; i < SPACE_NUM; i++)
	{
		std::cout << "Space " << i << "   ";
		for(int j = 0; j < PIECE_NUM; j++)
		{
			//show piece location
			if(playerPieces[j]->getPosition() == i)
			{
				std::cout << "piece " << j << " is here.";
				BoardSpaces[i]->explain();
			}
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
	std::cout << "piece fatigue: " << playerPieces[0]->getHP() << std::endl; 
}
