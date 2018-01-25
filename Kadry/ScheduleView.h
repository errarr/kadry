#pragma once
#include "BaseView.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "ScheduleService.h"
using namespace std;
class ScheduleView : BaseView
{
public:
	ScheduleView();
	~ScheduleView();
	void Menu();
private:
	ScheduleService scheduleService;
	void PrintSchedule();
	void AddEmployeeToSchedule();
	void DeleteEmployeeFromSchedule();
	
};

