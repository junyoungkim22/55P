#ifndef SPACE_H
#define SPACE_H

#include<iostream>

class Space
{
private:
	//Space* next;
	std::string spaceType;
	std::string name;
	bool PieceOn;

public:
	virtual ~Space(){};
	//bool hasPiece();
	//void setNext(Space* next){ this->next = next; };
	void setName(std::string name){ this->name = name; };
	void setSpaceType(const std::string& type){ spaceType = type; };
	std::string getSpaceType(){ return spaceType; };
	virtual void setExplainString(const std::string s){};
	virtual void explain(){ return; };

	//Space* getNext(){ return next; };
	std::string getName(){ return name; };
};

#endif
