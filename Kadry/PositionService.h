#pragma once

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "PositionRepository.h"
using namespace std;

class PositionService
{
public:
	PositionService();
	~PositionService();
	bool Add(string name);
	bool Edit(string name, string newName);
	bool Delete(string name);
	vector<string> GetAllPositions();
private:
	PositionRepository positionRepository;
};
