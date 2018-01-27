#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "PositionService.h"
#include "BaseView.h"
using namespace std;
class PositionView : public BaseView
{
public:
	PositionView();
	~PositionView();
	void Menu();
	void Add();
	void Edit();
	void Delete();
	void PrintAllPositions();

private:
	PositionService positionService;

};

