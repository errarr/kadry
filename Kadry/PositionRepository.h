#pragma once

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "BaseRepository.h"

using namespace std;
class PositionRepository:BaseRepository
{
public:
	PositionRepository();
	~PositionRepository();
	bool Add(string name);
	bool Update(string name, string newName);
	bool Delete(string name);
	vector<string> GetAllPositions();
	
};

