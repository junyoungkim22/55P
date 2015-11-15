#include <iostream>
#include "Space.h"
#include "HealingSpace.h"

HealingSpace::HealingSpace()
{
	SetspaceType("Healing");
}
void HealingSpace::setheal(int heal)
{
	this->heal = heal;
}
int HealingSpace::getheal()
{
	return heal;
}
void HealingSpace::setExplainString(const std::string s){explainstring = s;}
void HealingSpace::explain(){ std::cout << explainstring; }
