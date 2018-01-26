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
	catch (const std::exception& ex)
	{
		return -1;
	}
}
//TODO do przemyslenia
bool EmployeeService::EditEmployee(int employeeId)
{
	return false;
}

bool EmployeeService::DeactivateEmployee(int employeeId)
{
	try
	{
		employeeRepository.DeactivateEmployee(employeeId);
		return true;
	}
	catch (const std::exception& ex)
	{
		return false;
	}
	
}

float EmployeeService::CalculateSalary(int employeeId, string dateFrom, string dateTo)
{

	try
	{
		float hourlyRate = employeeRepository.GetEmployeeHourlyRate(employeeId);
		float salary = 0;
		vector<string> workingDays = employeeRepository.GetEmployeeWorkingDays(employeeId, dateFrom, dateTo);
		for (int i = 0; i < workingDays.size(); i++)
		{
			DayType dayType = (DayType)(ConversionHelper::StringToInt(workingDays[i]));
			CalculateSalaryForDay(dayType, salary, hourlyRate);
		}
		return salary;
	}
	catch (const std::exception& ex)
	{
		return -1;
	}
	
}

bool EmployeeService::IsEmployeeExist(int employeeId)
{
	try
	{
		return employeeRepository.IsEmployeeExist(employeeId);
	}
	catch (const std::exception& ex)
	{
		return false;
	}
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
	catch (const std::exception& ex)
	{
		return vector<Employee>();
	}
	
}

float EmployeeService::CalculateSummaricSalary(string dateFrom, string dateTo)
{
	try
	{
		vector<vector<string>> dayTypeSalaries = employeeRepository.GetEmployeesWorkingDays(dateFrom, dateTo);
		float salary = 0;
		for (int i = 0; i < dayTypeSalaries.size(); i++)
		{
			vector<string> dayTypeSalary = dayTypeSalaries[i];
			DayType dayType = (DayType)(ConversionHelper::StringToInt(dayTypeSalary[0]));
			float hourlyRate = ConversionHelper::StringToFloat(dayTypeSalary[1]);

			CalculateSalaryForDay(dayType, salary, hourlyRate);
		}
		return salary;
	}
	catch (const std::exception& ex)
	{
		return -1;
	}
}
void EmployeeService::CalculateSalaryForDay(DayType dayType, float &salary, float hourlyRate)
{
	switch (dayType)
	{
	case Work: salary += hourlyRate * SHIFT * WORKRATE;
		break;
	case Holiday: salary += hourlyRate * SHIFT * HOLIDAYRATE;
		break;
	case Sick: salary += hourlyRate * SHIFT * SICKRATE;
		break;
	default:
		break;
	}
}

Employee EmployeeService::MapEmployee(vector<string> employeeToMap)
{
	Employee employee;
	Address address;
	Position position;

	employee.SetId(ConversionHelper::StringToInt(employeeToMap[0]));
	employee.SetName(employeeToMap[1]);
	employee.SetSurname(employeeToMap[2]);
	employee.SetHourlyRate(ConversionHelper::StringToFloat(employeeToMap[3]));
	employee.SetHolidays(ConversionHelper::StringToInt(employeeToMap[4]));

	address.SetTown(employeeToMap[5]);
	address.SetPostalCode(employeeToMap[6]);
	address.SetStreet(employeeToMap[7]);
	address.SetBuildingNumber(employeeToMap[8]);
	address.SetPhoneNumber(employeeToMap[9]);
	employee.SetAddress(address);

	position.SetName(employeeToMap[10]);
	employee.SetPosition(position);

	return employee;
}
