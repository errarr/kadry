#include "stdafx.h"
#include "ScheduleView.h"


ScheduleView::ScheduleView()
{
}


ScheduleView::~ScheduleView()
{
}

void ScheduleView::Menu()
{
	int action;
	do
	{
		cout << "\n\n\n---------------------------------------------------------------\n\n\n   ::::HARMONOGRAM MENU::::\n\n\n   Wybierz akcje, ktora chcesz wykonac:\n\n     1. Wyswietl harmonogram.\n     2. Dodaj pracownika do harmonogramu.\n     3. Usun pracownika z harmonogramu.\n     4. Wroc do poprzedniego menu\n\n\n\nWybor: ";
		cout << "schedule";
		cin >> action;

		switch (action)
		{
		case 1:
			PrintSchedule();
			break;
		case 2:
			AddEmployeeToSchedule();
			break;
		case 3:
			DeleteEmployeeFromSchedule();
			break;

		default:
			break;
		}
	} while (action != 4);
}

void ScheduleView::PrintSchedule()
{
	string date;
	cout << "Podaj date, dla ktorej chcesz pobrac harmonogram: ";
	cin >> date;
	Schedule schedule = scheduleService.GetSchedule(date);
	for (int i = 0; i < schedule.employeeDays.size(); i++)
	{
		EmployeeDay employeeDay = schedule.employeeDays[i];
		cout << "ID | Imie | Nazwisko | Typ dnia (1 - Praca, 2 - Urlop platny, 3 - Chorobowe)\n";
		cout << employeeDay.GetEmployeeId() << " " << employeeDay.GetName() << " " << employeeDay.GetSurname() << " " << employeeDay.GetDayType() << endl;
	}

}

void ScheduleView::AddEmployeeToSchedule()
{
	int employeeId;
	int dayType;
	string date;
	bool isAdded = false;
	do
	{

		cout << "Podaj ID pracownika: ";
		cin >> employeeId;
		if (scheduleService.IsEmployeeActive(employeeId))
		{
			cout << "Podaj date (DD-MM-RRRR): ";
			cin >> date;
			cout << "Podaj typ dnia (1 - Praca, 2 - Urlop platny, 3 - Chorobowe. Urlopu bezplatnego nie wprowadzamy do harmonogramu!): ";
			cin >> dayType;
			isAdded = scheduleService.AddEmployeeToSchedule(employeeId, date, (DayType)dayType);
			if (isAdded)
			{
				cout << "Dodano pracownika do harmonogramu!\n";
			}
			else
			{
				cout << "Wystapil blad przy dodawaniu pracownika do harmonogramu! \n";
			}
		}
		else
		{
			cout << "Wybrany pracownik nie jest aktywny!\n";
		}
	} while (isAdded);
}

void ScheduleView::DeleteEmployeeFromSchedule()
{
	int employeeId;
	string date;

	cout << "Podaj ID pracownika: ";
	cin >> employeeId;
	cout << "Podaj date (DD-MM-RRRR): ";
	cin >> date;

	bool isDeleted = scheduleService.DeleteEmployeeFromSchedule(employeeId, date);
	if (isDeleted)
	{
		cout << "Usunieto pracownika z harmonogramu!\n";
	}
	else
	{
		cout << "Wystapil blad przy usuwaniu pracownika z harmonogramu! \n";
	}
}