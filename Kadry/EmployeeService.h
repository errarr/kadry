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
	float CalculateSalary(int employeeId, string dateFrom, string dateTo);
	vector<Employee> GetAllEmployees();
	float CalculateSummaricSalary(string dateFrom, string dateTo);

private:
	EmployeeRepository employeeRepository;
	Employee MapEmployee(vector<string> employeeToMap);
};

