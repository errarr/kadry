#pragma once
#include "Employee.h"
#include "EmployeeService.h"
#include "ScheduleService.h"
#include "BaseView.h"
class EmployeeView : public BaseView
{
public:
	EmployeeView();
	~EmployeeView();
	void Menu();
	void PrintEmployeeDetails ();
	void AddEmployee();
	void EditEmployee();
	void DeleteEmployee();
	void PrintEmployeeSalary();
	void PrintAllEmployeesSummaricSalary();
	void PrintAllEmployees();
private:
	EmployeeService employeeService;
	ScheduleService scheduleService;
};

