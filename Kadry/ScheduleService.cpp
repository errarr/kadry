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
	catch (const std::exception& ex)
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
	catch (const std::exception& ex)
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
	catch (const std::exception& ex)
	{
		return false;
	}
	
}

bool ScheduleService::IsEmployeeActive(int employeeId)
{
	try
	{
		return employeeRepository.IsEmployeeActive(employeeId);
	}
	catch (const std::exception& ex)
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
		employeeDay.SetEmployeeId(ConversionHelper::StringToInt(row[0]));
		employeeDay.SetName(row[1]);
		employeeDay.SetSurname(row[2]);
		employeeDay.SetDayType((DayType)ConversionHelper::StringToInt(row[3]));
		employeeDays.push_back(employeeDay);
	}
	return employeeDays;
}