#include "stdafx.h"
#include "ScheduleService.h"


ScheduleService::ScheduleService()
{
}


ScheduleService::~ScheduleService()
{
}

Schedule ScheduleService::GetSchedule(string date)
{
	Schedule schedule;
	schedule.date = date;
	try
	{
		vector<vector<string>> scheduleVector = scheduleRepository.GetSchedule(date);
		schedule.employeeDays = MapEmployeDay(scheduleVector);
	}
	catch (const std::exception&)
	{
	}
	return schedule;
}

bool ScheduleService::AddEmployeeToSchedule(int employeeId, string date, DayType dayType)
{
	try
	{
		scheduleRepository.AddEmployeeToSchedule(employeeId, date, dayType);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
	
}

bool ScheduleService::DeleteEmployeeFromSchedule(int employeeId, string date)
{
	try
	{
		scheduleRepository.DeleteEmployeeFromSchedule(employeeId, date);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
	
}

vector<EmployeeDay> ScheduleService::MapEmployeDay(vector<vector<string>> schedule)
{
	vector<EmployeeDay> employeeDays;
	for (int i = 0; i < schedule.size(); i++)
	{
		vector<string> row = schedule[i];
		EmployeeDay employeeDay;
		employeeDay.employeeId = ConversionHelper::StringToInt(row[0]);
		employeeDay.name = row[1];
		employeeDay.surname = row[2];
		employeeDay.dayType = (DayType)ConversionHelper::StringToInt(row[3]);
		employeeDays.push_back(employeeDay);
	}
	return employeeDays;
}