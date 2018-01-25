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
	
//TODO zrobic settery/gettery, odkomentowac priveate
//private:
	DayType dayType;
	int employeeId;
	string name, surname;
};

