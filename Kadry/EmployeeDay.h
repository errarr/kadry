#pragma once
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "Enums.h"
using namespace std;

class EmployeeDay
{
public:
	EmployeeDay();
	~EmployeeDay();
	void SetDayType(DayType dayType);
	DayType GetDayType();
	void SetEmployeeId(int employeeId);
	int GetEmployeeId();
	void SetName(string name);
	string GetName();
	void SetSurname(string surname);
	string GetSurname();

private:
	DayType dayType;
	int employeeId;
	string name, surname;
};

