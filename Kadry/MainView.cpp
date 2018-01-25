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
		//TODO choose action wyswietlenie
		cout << "main";
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
