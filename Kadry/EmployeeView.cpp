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
		
		
		cout << "\n\n\n---------------------------------------------------------------\n\n\n   ::::PRACOWNIK MENU::::\n\n\n   Wybierz akcje, ktora chcesz wykonac:\n\n     1. Wyswietl dane wszystkich pracownikow.\n     2. Dodaj pracownika.\n     3. Edytuj pracownika.\n     4. Usun pracownika.\n     5. Wyswietl zarobki wybranego pracownika.\n     6. Wyswietl sume zarobkow wszystkich pracownikow.\n     7. Wroc do poprzedniego menu\n\n\n\nWybor: ";
		cin >> action;
		system("cls");
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
			break;
		case 5:
			PrintEmployeeSalary();
			break;
		case 6:
			PrintAllEmployeesSummaricSalary();
			break;
		default:
			break;
		}

		system("pause");
		//system("cls");
	} while (action != 7);

}





void EmployeeView::AddEmployee()
{
	string name, surname;
	float hourlyRate;
	int holidays;
	Address address;
	Position position;
	string positionName;
	string street;
	string buildingNumber;
	string postalCode;
	string town;
	string phoneNumber;

	cout << "Podaj dane nowego pracownika.\n\nImie: ";
	cin >> name;
	cout << "Nazwisko: ";
	cin >> surname;
	cout << "Stawke godzinowa: ";
	cin >> hourlyRate;
	cout << "Ilosc dni urlopowych: ";
	cin >> holidays;

	cout << "Wybierz stanowisko. Oto dostepne mozliwosci: \n";
	positionView.PrintAllPositions();
	cout << "Stanowisko: ";
	cin >> positionName;
	position.SetName(positionName);

	cout << "Podaj adres pracownika.\n Ulica: ";
	cin >> street;
	cout << "Numer budynku/mieszkania: ";
	cin >> buildingNumber;
	cout << "Kod pocztowy: ";
	cin >> postalCode;
	cout << "Miasto: ";
	cin >> town;
	cout << "Numer telefonu";
	cin >> phoneNumber;
	address.SetStreet(street);
	address.SetBuildingNumber(buildingNumber);
	address.SetPostalCode(postalCode);
	address.SetTown(town);
	address.SetPhoneNumber(phoneNumber);
	
	int isAdded = employeeService.AddEmployee(name, surname, hourlyRate, holidays, address, position);
	if (isAdded != -1)
	{
		cout << "Dodano pracownika. Jego ID to " << isAdded;
	}
	else
	{
		cout << "Wystapil blad przy tworzeniu pracownika.";
	}
}

void EmployeeView::EditEmployee()
{
	cout << "Podaj numer pracownika, ktorego chcesz edytowac: ";
	int employeeId;
	cin >> employeeId;
	string name, surname;
	float hourlyRate;
	int holidays;
	Address address;
	Position position;
	string positionName;
	string street;
	string buildingNumber;
	string postalCode;
	string town;
	string phoneNumber;

	cout << "Podaj nowe dane pracownika.\n\nImie: ";
	cin >> name;
	cout << "Nazwisko: ";
	cin >> surname;
	cout << "Stawke godzinowa: ";
	cin >> hourlyRate;
	cout << "Ilosc dni urlopowych: ";
	cin >> holidays;

	cout << "Wybierz nowe stanowisko. Oto dostepne mozliwosci: \n";
	positionView.PrintAllPositions();
	cout << "Stanowisko: ";
	cin >> positionName;
	position.SetName(positionName);

	cout << "Podaj nowy adres pracownika.\n Ulica: ";
	cin >> street;
	cout << "Numer budynku/mieszkania: ";
	cin >> buildingNumber;
	cout << "Kod pocztowy: ";
	cin >> postalCode;
	cout << "Miasto: ";
	cin >> town;
	cout << "Numer telefonu";
	cin >> phoneNumber;
	address.SetStreet(street);
	address.SetBuildingNumber(buildingNumber);
	address.SetPostalCode(postalCode);
	address.SetTown(town);
	address.SetPhoneNumber(phoneNumber);
	bool isEdited = employeeService.EditEmployee(employeeId, name, surname, hourlyRate, holidays, address, position);
	if (isEdited)
	{
		cout << "Wyedytowano pracownika.";
	}
	else
	{
		cout << "Wystapil blad przy edycji pracownika.";
	}
}

void EmployeeView::DeleteEmployee()
{
	cout << "Podaj numer pracownika, ktorego chcesz usunac: ";
	int employeeId;
	cin >> employeeId;
	bool isDeleted = employeeService.DeactivateEmployee(employeeId);
	if (isDeleted)
	{
		cout << "Usunieto pracownika.";
	}
	else
	{
		cout << "Wystapil blad przy usuwaniu pracownika.";
	}
}



void EmployeeView::PrintEmployeeSalary()
{

	int employeeId;
	string dateFrom, dateTo;
	do
	{
		cout << "\nPodaj id pracownika, dla ktorego chcesz wyliczyc wynagrodzenie: ";
		cin >> employeeId;
		if (employeeService.IsEmployeeExist(employeeId))
		{
			cout << "\nPodaj date poczatkowa w formacie DD-MM-RRRR: ";
			cin >> dateFrom;
			cout << "\nPodaj date koncowa w formacie DD-MM-RRRR: ";
			cin >> dateTo;
			float calculatedSalary = employeeService.CalculateSalary(employeeId, dateFrom, dateTo);
			if (calculatedSalary == -1)
			{
				cout << "\nNie udalo sie obliczyc wyplaty dla pracownika o id " << employeeId;
			}
			else
			{
				cout << "\nPracownik o id = " << employeeId << " w podanym przedziale czasowym zarobil " << calculatedSalary;
			}

			break;
		}
		else
		{
			cout << "Pracownik o podanym ID nie istnieje.\n";
		}
	} while (true);
}

void EmployeeView::PrintAllEmployeesSummaricSalary()
{
	string dateFrom, dateTo;
	cout << "\nPodaj date poczatkowa w formacie DD-MM-RRRR: ";
	cin >> dateFrom;
	cout << "\nPodaj date koncowa w formacie DD-MM-RRRR: ";
	cin >> dateTo;
	float calculatedSalary = employeeService.CalculateSummaricSalary(dateFrom, dateTo);
	if (calculatedSalary == -1)
		cout << "\nNie udalo sie wyliczyc sumy wyplat w podanym okresie";
	else
		cout << "\nSuma wyplat w podanym okresie to " << calculatedSalary;
}

void EmployeeView::PrintAllEmployees()
{
	vector<Employee> allEmployees = employeeService.GetAllEmployees();
	cout << "ID | Imie | Nazwisko | Stanowisko | Stawka godzinowa | Ulica  Nr domu | Kod pocztowy  Miasto | Telefon\n";
	for (int i = 0; i < allEmployees.size(); i++)
	{
		cout << allEmployees[i].GetId() << " | " << allEmployees[i].GetName() << " | " << allEmployees[i].GetSurname() << " | " << allEmployees[i].GetPosition().GetName() << " | " << allEmployees[i].GetHourlyRate() <<" zl | " << allEmployees[i].GetAddress().GetStreet() << " " << allEmployees[i].GetAddress().GetBuildingNumber() << " | " << allEmployees[i].GetAddress().GetPostalCode() << " " << allEmployees[i].GetAddress().GetTown() << " | " << allEmployees[i].GetAddress().GetPhoneNumber() << "\n";

	}

}
