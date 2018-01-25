#pragma once
#include "BaseRepository.h"
#include "Enums.h"
class ScheduleRepository :
	public BaseRepository
{
public:
	ScheduleRepository();
	~ScheduleRepository();
	vector<vector<string>> GetSchedule(string date);
	void AddEmployeeToSchedule(int employeeId, string date, DayType dayType);
	void DeleteEmployeeFromSchedule(int employeeId, string date);
};

