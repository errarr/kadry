#pragma once
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "Address.h"
#include "Position.h"
using namespace std;

class Employee
{
public:
	Employee();
	Employee(int id,
	string name,
	string surname,
	float hourlyRate,
	int holidays,
	Address address,
	Position position);
	~Employee();


private:
	int id;
	string name;
	string surname;
	float hourlyRate;
	int holidays;
	Address address;
	Position position;

public:
	void SetId(int id);
	int GetId();
	void SetName(string name);
	string GetName();
	void SetSurname(string surname);
	string GetSurname();
	void SetHourlyRate(float hourlyRate);
	float GetHourlyRate();
	void SetHolidays(int holidays);
	int GetHolidays();

};

