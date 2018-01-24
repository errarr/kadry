#include "stdafx.h"
#include "EmployeeRepository.h"
#include <string.h>
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
	const string query = "SELECT employees.idemployees, employees.name, surname, hourlyrate, holidays, town, postalcode, street, buildingnumber, phonenumber, positions.name FROM kadry.employees, kadry.adresses, kadry.positions WHERE employees.idemployees = adresses.idemployees AND employees.idpositions = positions.idpositions;";
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
	const string querySelectPositionId = "SELECT idpositions FROM kadry.positions where name = '" + positionName + "';";
	const string querySelectNewestEmployeeId = "SELECT MAX(idemployees) FROM employees";

	ConnectDB();

	string positionId = ExecuteQueryDB(querySelectPositionId)[0][0];

	const string queryInsertEmployee = "INSERT INTO `kadry`.`employees` (`name`, `surname`, `hourlyrate`, `holidays`, `idpositions`) VALUES ('"+ name +"', '"+ surname+"', '"+ ConversionHelper::FloatToString(hourlyRate) +"', '"+ ConversionHelper::IntToString(holidays) +"', '"+positionId+"');";
	ExecuteQueryDB(queryInsertEmployee);

	string employeeId = ExecuteQueryDB(querySelectNewestEmployeeId)[0][0];

	const string queryInsertAddress = "INSERT INTO `kadry`.`adresses` (`town`, `postalcode`, `street`, `buildingnumber`, `phonenumber`, `idemployees`) VALUES ('"+town+"', '"+postalCode+"', '"+street+"', '"+buildingNumber+"', '" + phoneNumber + "', '"+employeeId+"');";
	ExecuteQueryDB(queryInsertAddress);

	DisconnectDB();
	return ConversionHelper::StringToInt(employeeId);
	
}

