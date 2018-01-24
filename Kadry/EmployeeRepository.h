#pragma once
#include "BaseRepository.h"
#include "ConversionHelper.h"
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
};

