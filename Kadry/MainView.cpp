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
		cout << "\n\n\n---------------------------------------------------------------\n\n\n  ::::KADRY MENU::::\n\n\n   Wybierz modul, ktory chcesz uruchomic:\n\n     1. PRACOWNICY\n     2. HARMONOGRAMY\n     3. STANOWISKA\n\n     4. ZAKONCZ PROGRAM\n\n\n\nWybor:";
		cin >> action;

		switch (action)
		{
		case 1:
			employeeView.Menu();
			break;
		case 2:
			scheduleView.Menu();
			break;
		case 3:
			positionView.Menu();
			break;

		default:
			break;
		}
	} while (action != 4);
}
