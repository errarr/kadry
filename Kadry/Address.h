#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Address
{
public:
	Address();
	Address(string town,
		string street,
		string postalCode,
		string buildingNumber,
		string phoneNumber);
	~Address();
	


private:
	string town;
	string street;
	string postalCode;
	string buildingNumber;
	string phoneNumber;
public:
	void SetTown(string town);
	string GetTown();
	void SetStreet(string street);
	string GetStreet();
	void SetPostalCode(string postalCode);
	string GetPostalCode();
	void SetBuildingNumber(string buildingNumber);
	string GetBuildingNumber();
	void SetPhoneNumber(string phoneNumber);
	string GetPhoneNumber();



};

