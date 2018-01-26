#include "stdafx.h"
#include "MainView.h"


MainView::MainView()
{
}


MainView::~MainView()
{
}

void MainView::Menu()
{
	int action;
	do
	{
		system("cls");
		cout << "\n\n\n---------------------------------------------------------------\n\n\n  ::::KADRY MENU::::\n\n\n   Wybierz modul, ktory chcesz uruchomic:\n\n     1. PRACOWNICY\n     2. HARMONOGRAMY\n     3. STANOWISKA\n\n     4. ZAKONCZ PROGRAM\n\n\n\nWybor:";
		cin >> action;

		switch (action)
		{
		case 1:
			view = new EmployeeView();
			break;
		case 2:
			view = new ScheduleView();
			break;
		case 3:
			view = new PositionView();
			break;
			
		default:
			break;
		}

		if (action == 4)
		{
			break;
		}

		view->Menu();
		delete view;
	} while (true);
}
