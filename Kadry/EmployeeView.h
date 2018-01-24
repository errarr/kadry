#pragma once
#include "Employee.h"
#include "EmployeeService.h"
#include "ScheduleService.h"

class EmployeeView
{
public:
	EmployeeView();
	~EmployeeView();
	
	void Menu();
	void PrintEmployee(int employeeId);
	void AddEmployee();
	void EditEmployee(int employeeId);
	void PrintSchedule(string date);
	void AddEmployeeToSchedule(int employeeId, string date);
	void DeleteEmployeeFromSchedule(int employeeId, string date);
	void PrintEmployeeSalary(int employeeId, string dateFrom, string dateTo);
	void PrintAllEmployeesSummaricSalary(string dateFrom, string dateTo);
private:
	//TODO stworzyc i wywalic seriwsy (konstruktor/destruktor)
	EmployeeService employeeService;
	ScheduleService scheduleService;
};

