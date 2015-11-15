#ifndef HEALING_SPACE_H
#define HEALING_SPACE_H

#include "space.h"

class HealingSpace : public Space
{
private:
	int heal;
	std::string explainstring;

public:
	HealingSpace();
	void setheal(int heal);
	int getheal();
	void setExplainString(const std::string s);
	void explain();
};

#endif
