#include "stdafx.h"
#include "ScheduleRepository.h"


ScheduleRepository::ScheduleRepository()
{
}


ScheduleRepository::~ScheduleRepository()
{
}

vector<vector<string>> ScheduleRepository::GetSchedule(string date)
{
	const string query = "SELECT kadry.employees.idemployees, kadry.employees.`name`, kadry.employees.surname, kadry.employeeschedule.daytype FROM kadry.schedules, kadry.employees, kadry.employeeschedule WHERE kadry.employees.idemployees = kadry.employeeschedule.idemployees AND kadry.employeeschedule.idschedules = kadry.schedules.idschedules AND kadry.schedules.date = STR_TO_DATE('"+date+"', '%d-%m-%Y');";
	ConnectDB();
	vector<vector<string>> employees = ExecuteQueryDB(query);
	DisconnectDB(); 
	return employees;
	
}

void ScheduleRepository::AddEmployeeToSchedule(int employeeId, string date, DayType dayType)
{
	const string query = "INSERT INTO `kadry`.`employeeschedule` (`idemployees`, `idschedules`, `daytype`) VALUES ('"+ConversionHelper::IntToString(employeeId)+"', (SELECT idschedules FROM schedules WHERE  kadry.schedules.date = STR_TO_DATE('"+date+"', '%d-%m-%Y')), '"+ ConversionHelper::IntToString((int)dayType)+"')";
	ConnectDB();
	ExecuteQueryDB(query);
	DisconnectDB();
	
}

void ScheduleRepository::DeleteEmployeeFromSchedule(int employeeId, string date)
{
	const string query = "DELETE FROM `kadry`.`employeeschedule` WHERE kadry.employeeschedule.idschedules = (SELECT idschedules FROM schedules WHERE schedules.date = (STR_TO_DATE('"+date+"', '%d-%m-%Y'))) AND kadry.employeeschedule.idemployees = " + ConversionHelper::IntToString(employeeId) + ";";
	ConnectDB();
	ExecuteQueryDB(query);
	DisconnectDB();
}
