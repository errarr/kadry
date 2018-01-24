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
	return Schedule();
}

bool ScheduleService::AddEmployeeToSchedule(int employeeId, string date)
{
	return false;
}

bool ScheduleService::DeleteEmployeeFromSchedule(int employeeId, string date)
{
	return false;
}
