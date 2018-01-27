#include "stdafx.h"
#include "Address.h"


Address::Address()
{
}

Address::Address(string town, string street, string postalCode, string buildingNumber, string phoneNumber)
{
	this->town = town;
	this->street = street;
	this->postalCode = postalCode;
	this->buildingNumber = buildingNumber;
	this->phoneNumber = phoneNumber;
}


Address::~Address()
{
}



void Address::SetTown(string town)
{
	this->town = town;
}


string Address::GetTown()
{
	return town;
}

void Address::SetStreet(string street)
{
	this->street = street;
}

string Address::GetStreet()
{
	return street;
}

void Address::SetPostalCode(string postalCode)
{
	this->postalCode = postalCode;
}

string Address::GetPostalCode()
{
	return postalCode;
}

void Address::SetBuildingNumber(string buildingNumber)
{
	this->buildingNumber = buildingNumber;
}

string Address::GetBuildingNumber()
{
	return buildingNumber;
}


void Address::SetPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

string Address::GetPhoneNumber()
{
	return phoneNumber;
}
