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
	return id;
}

void Employee::SetName(string name)
{
	this->name = name;
}

string Employee::GetName()
{
	return name;
}

void Employee::SetSurname(string surname)
{
	this->surname = surname;
}

string Employee::GetSurname()
{
	return surname;
}

void Employee::SetHourlyRate(float hourlyRate)
{
	this->hourlyRate = hourlyRate;
}

float Employee::GetHourlyRate()
{
	return hourlyRate;
}

void Employee::SetHolidays(int holidays)
{
	this->holidays = holidays;
}

int Employee::GetHolidays()
{
	return holidays;
}

void Employee::SetAddress(Address address)
{
	this->address = address;
}

Address Employee::GetAddress()
{
	return address;
}

void Employee::SetPosition(Position position)
{
	this->position = position;
}
Position Employee::GetPosition()
{
	return position;
}