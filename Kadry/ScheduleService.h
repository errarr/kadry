#pragma once
#include "Schedule.h"
#include "ScheduleRepository.h"
#include "EmployeeDay.h"
class ScheduleService
{
public:
	ScheduleService();
	~ScheduleService();

	Schedule GetSchedule(string date);
	bool AddEmployeeToSchedule(int employeeId, string date, DayType dayType);
	bool DeleteEmployeeFromSchedule(int employeeId, string date);
	
private:
	ScheduleRepository scheduleRepository;
	vector<EmployeeDay> MapEmployeDay(vector<vector<string>> schedule);
};

