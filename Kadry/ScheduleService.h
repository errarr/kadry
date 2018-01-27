#pragma once
#include "Schedule.h"
#include "ScheduleRepository.h"
#include "EmployeeDay.h"
#include "EmployeeRepository.h"
class ScheduleService
{
public:
	ScheduleService();
	~ScheduleService();

	Schedule GetSchedule(string date);
	bool AddEmployeeToSchedule(int employeeId, string date, DayType dayType);
	bool DeleteEmployeeFromSchedule(int employeeId, string date);
	bool IsEmployeeActive(int employeeId);
private:
	ScheduleRepository scheduleRepository;
	EmployeeRepository employeeRepository;
	vector<EmployeeDay> MapEmployeDay(vector<vector<string>> schedule);

};