#pragma once
#include "BaseRepository.h"
#include "ConversionHelper.h"
#include <vector>
#include "Enums.h"
class EmployeeRepository :
	public BaseRepository
{
public:
	EmployeeRepository();
	~EmployeeRepository();
	vector<vector<string>> GetAllEmployees();
	int AddEmployee(string name,
		string surname,
		float hourlyRate,
		int holidays,
		string town,
		string street,
		string postalCode,
		string buildingNumber,
		string phoneNumber,
		string position);
	bool DeactivateEmployee(int employeeId);
	float GetEmployeeHourlyRate(int employeeId);
	vector<string> GetEmployeeWorkingDays(int employeeId, string dateFrom, string dateTo);
	vector<vector<string>> GetEmployeesWorkingDays(string dateFrom, string dateTo);
	bool IsEmployeeActive(int employeeId);
	bool IsEmployeeExist(int employeeId);
};

