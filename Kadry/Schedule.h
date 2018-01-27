#pragma once
#include <string>
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


//private: dopisac setter/getter
	string date;
	vector<EmployeeDay> employeeDays;
};

