#include "Board.h"

Board::Board()
{
	for(int i = 0; i < SPACE_NUM; i++)
	{
		this->BoardSpaces[i] = new Space;
	}
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
	int current = this->playerPieces[index].getPosition();
	this->playerPieces[index].setPosition((current + moveNum) % SPACE_NUM);
}

void Board::draw()
{
	std::cout << std::string(70, '\n');
	for(int i = 0; i < SPACE_NUM; i++)
	{
		std::cout << "Space " << i << "   ";
		for(int j = 0; j < PIECE_NUM; j++)
		{
			if(this->playerPieces[j].getPosition() == i)
			{
				std::cout << "piece " << j << " is here.   ";
			}
		}
		std::cout << "\n"; }
}
