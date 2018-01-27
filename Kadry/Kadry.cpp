// Kadry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mysql.h>
#include <iostream>
#include "PositionRepository.h"
#include "EmployeeRepository.h"
#include "EmployeeService.h"
using namespace std;

int main()
{
  /*
	MYSQL mysql;
	
	mysql_init(&mysql);
	if (mysql_real_connect(&mysql, "127.0.0.1", "root", "kadry", "kadry", 3306, NULL, 0))
		cout << "OK \n";
	else
		cout << "Blad";

	MYSQL_RES *idZapytania;
	MYSQL_ROW wiersz;

	mysql_select_db(&mysql, "kadry");
	mysql_query(&mysql, "SELECT * FROM positions");
	idZapytania = mysql_store_result(&mysql);

	while ((wiersz = mysql_fetch_row(idZapytania)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania); i++)
			cout << wiersz[i] << " ";
		cout << endl;
	}
	
	mysql_close(&mysql);
	int x;
	cin >> x;*/

	/*BaseRepository baza;
	baza.ConnectDB();
	vector<vector<string>> vector;
	vector = baza.ExecuteQueryDB2"SELECT employees.idemployees, name, surname, hourlyrate, holidays, town, postalcode, street, buildingnumber, phonenumber FROM kadry.employees, kadry.adresses WHERE employees.idemployees = adresses.idemployees;");
	baza.DisconnectDB();*/
	/*PositionRepository repo;
	EmployeeRepository erepo;
	vector<vector<string>> vector;
	vector = erepo.GetAllEmployees();

	repo.Delete("dupa2");*/
	EmployeeRepository erepo;
	EmployeeService eservice;
	vector<Employee> vector;
	int id;
	Address adres;
	adres.SetTown("Lodz");
	adres.SetStreet("Mickiewicza");
	adres.SetPostalCode("23232");
	adres.SetBuildingNumber("12/2");
	adres.SetPhoneNumber("32");
	Position pozycja;
	pozycja.SetName("CEO");
	id = eservice.AddEmployee("Ola", "Makota", 23.23, 12, adres, pozycja);
}

