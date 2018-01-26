#pragma once
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Schedule.h"
#include "Address.h"
#include <vector>
#include "ConversionHelper.h"
//#include "BaseRepository.h"
#include "EmployeeRepository.h"
using namespace std;

class EmployeeService
{
public:
	EmployeeService();
	~EmployeeService();
	//TODO employee + address parametry
	int AddEmployee(
		string name,
		string surname,
		float hourlyRate,
		int holidays,
		Address address,
		Position position); //-1 jesli zle
	bool EditEmployee(int employeeId);
	bool DeactivateEmployee(int employeeId);
	vector<Employee> GetAllEmployees();
	float CalculateSummaricSalary(string dateFrom, string dateTo);
	float CalculateSalary(int employeeId, string dateFrom, string dateTo);
	bool IsEmployeeExist(int employeeId);

private:
	const float WORKRATE = 1;
	const float HOLIDAYRATE = 1;
	const float SICKRATE = 0.8;
	const float SHIFT = 8;
	EmployeeRepository employeeRepository;
	Employee MapEmployee(vector<string> employeeToMap);
	void CalculateSalaryForDay(DayType dayType, float &salary, float hourlyRate);
};

