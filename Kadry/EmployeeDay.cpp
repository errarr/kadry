#include "stdafx.h"
#include "EmployeeDay.h"

EmployeeDay::EmployeeDay()
{
}

EmployeeDay::~EmployeeDay()
{
}

void EmployeeDay::SetDayType(DayType dayType)
{
	this->dayType = dayType;
}

DayType EmployeeDay::GetDayType()
{
	return dayType;
}

void EmployeeDay::SetEmployeeId(int employeeId)
{
	this->employeeId = employeeId;
}

int EmployeeDay::GetEmployeeId()
{
	return employeeId;
}

void EmployeeDay::SetName(string name)
{
	this->name = name;
}

string EmployeeDay::GetName()
{
	return name;
}

void EmployeeDay::SetSurname(string surname)
{
	this->surname = surname;
}

string EmployeeDay::GetSurname()
{
	return surname;
}


