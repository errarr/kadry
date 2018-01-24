#pragma once
#include "Schedule.h"
class ScheduleService
{
public:
	ScheduleService();
	~ScheduleService();
	Schedule GetSchedule(string date);
	bool AddEmployeeToSchedule(int employeeId, string date);
	bool DeleteEmployeeFromSchedule(int employeeId, string date);
};

