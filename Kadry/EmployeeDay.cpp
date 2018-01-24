#include "stdafx.h"
#include "EmployeeDay.h"





EmployeeDay::~EmployeeDay()
{
}

EmployeeDay::EmployeeDay(Employee employee, DayType dayType)
{
	this->employee = employee;
	this->dayType = dayType;
}