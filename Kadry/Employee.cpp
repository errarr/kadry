#include "stdafx.h"
#include "Employee.h"


Employee::Employee()
{
}

Employee::Employee(int id, string name, string surname, float hourlyRate, int holidays, Address address, Position position)
{
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->hourlyRate = hourlyRate;
	this->holidays = holidays;
	this->address = address;
	this->position = position;
}





Employee::~Employee()
{
	
}

void Employee::SetId(int id)
{
	this->id = id;
}

int Employee::GetId()
{
	return 0;
}

void Employee::SetName(string name)
{
}

string Employee::GetName()
{
	return string();
}

void Employee::SetSurname(string surname)
{
}

string Employee::GetSurname()
{
	return string();
}

void Employee::SetHourlyRate(float hourlyRate)
{
}

float Employee::GetHourlyRate()
{
	return 0.0f;
}

void Employee::SetHolidays(string holidays)
{
}

int Employee::GetHolidays()
{
	return 0;
}
