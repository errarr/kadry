#pragma once
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class EmployeeDay
{
public:
	enum DayType { Work = 1, Holiday = 2, Sick = 3 };
	Employee employee;
	EmployeeDay(Employee, DayType);
	~EmployeeDay();
	
private:
	DayType dayType;
};

