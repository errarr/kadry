#include "stdafx.h"
#include "EmployeeRepository.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

EmployeeRepository::EmployeeRepository()
{
}


EmployeeRepository::~EmployeeRepository()
{
}

vector<vector<string>> EmployeeRepository::GetAllEmployees()
{
	const string query = "SELECT employees.idemployees, employees.name, surname, hourlyrate, holidays, town, postalcode, street, buildingnumber, phonenumber, positions.name FROM kadry.employees, kadry.adresses, kadry.positions WHERE employees.isactive = 1 AND employees.idemployees = adresses.idemployees AND employees.idpositions = positions.idpositions;";
	ConnectDB();
	vector<vector<string>> employeesWithAddresses = ExecuteQueryDB(query);
	DisconnectDB();
	return employeesWithAddresses;
}

int EmployeeRepository::AddEmployee(
	string name,
	string surname,
	float hourlyRate,
	int holidays,
	string town,
	string street,
	string postalCode,
	string buildingNumber,
	string phoneNumber,
	string positionName)
{
	const string queryAddEmployee = "START TRANSACTION; SET @IDPOSITIONS: = (SELECT idpositions FROM kadry.positions where name = '" 
		+ positionName
		+"'); INSERT INTO `kadry`.`employees` (`name`, `surname`, `hourlyrate`, `holidays`, `idpositions`)	VALUES('" 
		+ name + "', '" 
		+ surname + "', " 
		+ ConversionHelper::FloatToString(hourlyRate) 
		+ ", " 
		+ ConversionHelper::IntToString(holidays) 
		+ ", @IDPOSITIONS); SET @NEWESTEMPLOYEEID: = (SELECT MAX(idemployees) FROM employees); INSERT INTO `kadry`.`adresses` (`town`, `postalcode`, `street`, `buildingnumber`, `phonenumber`, `idemployees`) VALUES('" 
		+ town 
		+ "', '" 
		+ postalCode 
		+ "', '" 
		+ street 
		+ "', '" 
		+ buildingNumber 
		+ "', " 
		+ phoneNumber 
		+ ", @NEWESTEMPLOYEEID);SELECT @NEWESTEMPLOYEEID;COMMIT;";

	ConnectDB();
	string employeeId = ExecuteQueryDB(queryAddEmployee)[0][0];
	DisconnectDB();
	return ConversionHelper::StringToInt(employeeId);
}

bool EmployeeRepository::DeactivateEmployee(int employeeId)
{
	string query = "UPDATE employees SET isactive =0 WHERE idemployees = '" + ConversionHelper::IntToString(employeeId) + "'";
	vector<string> positionNames;
	ConnectDB();
	ExecuteQueryDB(query);
	DisconnectDB();
	return true;
}

float EmployeeRepository::GetEmployeeHourlyRate(int employeeId)
{
	string query = "SELECT employees.hourlyrate FROM kadry.employees WHERE idemployees = '"+ ConversionHelper::IntToString(employeeId) + "'";
	ConnectDB();
	float hourlyRate = ConversionHelper::StringToFloat(ExecuteQueryDB(query)[0][0]);
	DisconnectDB();
	return hourlyRate;
}

vector<string> EmployeeRepository::GetEmployeeWorkingDays(int employeeId, string dateFrom, string dateTo)
{
	const string query = "SELECT daytype FROM employeeschedule where employeeschedule.idemployees = " + ConversionHelper::IntToString(employeeId) + " AND employeeschedule.idschedules IN(SELECT idschedules FROM schedules WHERE schedules.`date` between STR_TO_DATE('"+dateFrom+"', '%d-%m-%Y') AND STR_TO_DATE('"+dateTo+"', '%d-%m-%Y'))";
	ConnectDB();
	vector<vector<string>> result = ExecuteQueryDB(query);
	DisconnectDB();
	vector<string> days;
	for (int i = 0; i < result.size(); i++)
	{
		days.push_back(result[i][0]);
	}
	return days;
}

vector<vector<string>> EmployeeRepository::GetEmployeesWorkingDays(string dateFrom, string dateTo)
{
	const string query = "SELECT employeeschedule.daytype, employees.hourlyrate FROM employeeschedule LEFT JOIN employees ON employeeschedule.idemployees = employees.idemployees WHERE employeeschedule.idschedules IN (SELECT idschedules FROM schedules WHERE schedules.`date` between STR_TO_DATE('" + dateFrom + "', '%d-%m-%Y') AND STR_TO_DATE('" + dateTo + "', '%d-%m-%Y'))";
	ConnectDB();
	vector<vector<string>> result = ExecuteQueryDB(query);
	DisconnectDB();
	return result;
}

bool EmployeeRepository::IsEmployeeActive(int employeeId)
{
	const string query = "SELECT idemployees FROM employees WHERE employees.idemployees = "+ ConversionHelper::IntToString(employeeId) +" AND employees.isactive = 1";
	ConnectDB();
	vector<vector<string>> result = ExecuteQueryDB(query);
	DisconnectDB();
	return !result.empty();
}

bool EmployeeRepository::IsEmployeeExist(int employeeId)
{
	const string query = "SELECT idemployees FROM employees WHERE employees.idemployees = " + ConversionHelper::IntToString(employeeId);
	ConnectDB();
	vector<vector<string>> result = ExecuteQueryDB(query);
	DisconnectDB();
	return !result.empty();
}

