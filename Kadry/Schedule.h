#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "EmployeeDay.h"

using namespace std;

class Schedule
{
public:
	Schedule();
	~Schedule();


private:
	string date;
	
public://TODO dodac wsk
	EmployeeDay* employeeDays;
};

