#include "stdafx.h"
#include "EmployeeView.h"
#include <string>

EmployeeView::EmployeeView()
{
}


EmployeeView::~EmployeeView()
{
}

void EmployeeView::Menu()
{
	int action;
	do
	{

		//TODO choose action wyswietlenie
		cout << "employee";
		cin >> action;

		switch (action)
		{
		case 1:
			PrintAllEmployees();
			break;
		case 2:
			AddEmployee();
			break;
		case 3:
			EditEmployee();
			break;
		case 4:
			DeleteEmployee();
		case 5:
			PrintEmployeeSalary();
		case 6:
			PrintAllEmployeesSummaricSalary();
		default:
			break;
		}
	} while (action != 5);

}


void EmployeeView::PrintEmployeeDetails()
{
	//TODO jak bedzie trza
}


void EmployeeView::AddEmployee()
{

}

void EmployeeView::EditEmployee()
{
}

void EmployeeView::DeleteEmployee()
{
	cout << "Podaj numer pracownika, ktorego chcesz usunac: ";
	int employeeId;
	cin >> employeeId;
	bool isDeleted = employeeService.DeactivateEmployee(employeeId);
	if (isDeleted)
	{
		cout << "Usunieto";
	}
	else
	{
		cout << "ni chuja";
	}
}



void EmployeeView::PrintEmployeeSalary()
{
}

void EmployeeView::PrintAllEmployeesSummaricSalary()
{
}

void EmployeeView::PrintAllEmployees()
{
	vector<Employee> allEmployees = employeeService.GetAllEmployees();
	for (int i = 0; i < allEmployees.size(); i++)
	{
		//TODO dopisac reszte danych
		cout << allEmployees[i].GetId() << " " << allEmployees[i].GetName() << " " << allEmployees[i].GetSurname() << "\n";
	}

}
