#ifndef BUILDINGSPACE_H
#define BUILDINGSPACE_H

#include "Space.h"
#include "Piece.h"

class BuildingSpace : public Space
{
private:
    std::string explainString;
    //Player Owner;
    int tire;
    int buy_cost, damage_cost, steal_cost;

public:
    BuildingSpace();
    void setExplainString(const std::string s){ explainString = s; }
    void explain(){ std::cout << explainString; }
    void buy();
    void take(Piece* p);
    void damage(Piece* p);
    void setTire(int tire){this->tire = tire;}
    int getTire(){return tire;}
    int getBuycost(){return buy_cost;}
    int getDamagecost(){return damage_cost;}
    int getStealcost(){return steal_cost;}
};

#endif // BUILDINGSPACE_H

