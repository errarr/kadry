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
		cout << employeeDay.employeeId << endl; //TODO dokonczyc wypisywanie
	}

}

void ScheduleView::AddEmployeeToSchedule()
{
	cout << "Podaj dane";
	//TODO dokonczyc
	//cin >> dane; 
	//scheduleService.AddEmployeeToSchedule(employeeId, date, dayType);
}

void ScheduleView::DeleteEmployeeFromSchedule()
{
}