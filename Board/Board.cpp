#include "Board.h"

Board::Board()
{
	for(int i = 0; i < SPACE_NUM - 1; i++)
	{
		this->BoardSpaces[i] = new Space;
	}
	this->BoardSpaces[SPACE_NUM - 1] = new BuildingSpace;
	this->BoardSpaces[SPACE_NUM - 1]->setExplainString("Library\n");
}

Board::~Board()
{
	for(int i = 0; i < SPACE_NUM; i++)
	{
		delete this->BoardSpaces[i];
	}
}

void Board::move(int index, int moveNum)
{
	//경원이가 piece가 move하는 것을 이미 구현함
	int current = this->playerPieces[index].getPosition();
	this->playerPieces[index].setPosition((current + moveNum) % SPACE_NUM);
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
			if(this->playerPieces[j].getPosition() == i)
			{
				std::cout << "piece " << j << " is here.   ";
				
				//if piece is on a buildling, explain building
				if(this->BoardSpaces[i]->getSpaceType() == "Building")
				{
					this->BoardSpaces[i]->explain();
				}
			}
		}
		std::cout << "\n"; 
	}
}
