#include "stdafx.h"
#include "EmployeeService.h"


EmployeeService::EmployeeService()
{
}


EmployeeService::~EmployeeService()
{
}


int EmployeeService::AddEmployee(
	string name,
	string surname,
	float hourlyRate,
	int holidays,
	Address address,
	Position position)
{
	try
	{
	 return employeeRepository.AddEmployee(name,
			surname,
			hourlyRate,
			holidays,
			address.GetTown(),
			address.GetStreet(),
			address.GetPostalCode(),
			address.GetBuildingNumber(),
			address.GetPhoneNumber(),
			position.GetName());
	}
	catch (const std::exception&)
	{
		return -1;
	}
}
//TODO do przemyslenia
bool EmployeeService::EditEmployee(int employeeId)
{
	return false;
}

bool EmployeeService::DeleteEmployee(int employeeId)
{
	return false;
}

float EmployeeService::CalculateSalary(int employeeId, string dateFrom, string dateTo)
{
	return 0.0f;
}

vector<Employee> EmployeeService::GetAllEmployees()
{
	try
	{
		vector<Employee> employees;
		vector<vector<string>> employeesWithAddresses = employeeRepository.GetAllEmployees();
		for (int i = 0; i < employeesWithAddresses.size(); i++)
		{
			vector<string> employeeWithAddress = employeesWithAddresses[i];
			employees.push_back(MapEmployee(employeeWithAddress));
		}
		return employees;
	}
	catch (const std::exception&)
	{

	}
	
}

float EmployeeService::CalculateSummaricSalary(string dateFrom, string dateTo)
{
	return 0.0f;
}

Employee EmployeeService::MapEmployee(vector<string> employeeToMap)
{
	Employee employee;
	employee.SetId(atoi(employeeToMap[0].c_str()));
	employee.SetName(atoi(employeeToMap[0].c_str()));
	//TODO reszta metod, adress
	return employee;
}
