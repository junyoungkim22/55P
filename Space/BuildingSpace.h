#ifndef BUILDING_SPACE_H
#define BUILDING_SPACE_H

#include "Space.h"
#include "Piece.h"

class BuildingSpace : public Space
{
private:
	std::string explainString;
	//Player Owner;
	int tire;

public:
	BuildingSpace();
	void setExplainString(const std::string s){ explainString = s; };
	void explain(){ std::cout << explainString; };
	void buy();
	void take(Piece* p);
	void damage(Piece* p);
};

#endif
