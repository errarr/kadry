#include "stdafx.h"
#include "Position.h"


Position::Position()
{
}

Position::Position(string name)
{
	this->name = name;
}


Position::~Position()
{
}

void Position::SetName(string name)
{
	this->name = name;
}

string Position::GetName()
{
	return name;
}
