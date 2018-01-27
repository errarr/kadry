#pragma once
#include <iostream>
#include "EmployeeView.h"
#include "PositionView.h"
#include "ScheduleView.h"
#include "BaseView.h"

using namespace std;

class MainView : BaseView
{
public:
	MainView();
	~MainView();
	void Menu();

private:
	/*EmployeeView employeeView;
	PositionView positionView;
	ScheduleView scheduleView;*/
	BaseView *view;

};

