#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
class Position
{
public:
	Position();
	Position(string name);
	~Position();
private:
	string name;
public:
	void SetName(string name);
	string GetName();
};

