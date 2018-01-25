#include "stdafx.h"
#include "PositionView.h"


PositionView::PositionView()
{
}


PositionView::~PositionView()
{
}



void PositionView::Menu()
{
	int action;
	do
	{
		
		//TODO choose action wyswietlenie
		cout << "position";
		cin >> action;
		
		switch (action)
		{
		case 1:
			PrintAllPositions();
			break;
		case 2:
			Add();
			break;
		case 3:
			Edit();
			break;
		case 4:
			Delete();
		
		default:
			break;
		}
	} while (action != 5);

}

void PositionView::Add()
{
	string newPositionName;
	cout << "Wpisz nazwe pozycji: ";
	cin >> newPositionName;
	if (positionService.Add(newPositionName))
	{
		cout << "Dodano";
	}
	else
	{
		cout << "Cos jeblo";
	}
	
}

void PositionView::Edit()
{
	string newPositionName, oldPositionName;
	cout << "Wpisz nazwe pozycji, ktora chcesz edytowac: ";
	cin >> oldPositionName;
	cout << "Wpisz nowa nazwe dla pozycji " << oldPositionName <<": ";
	cin >> newPositionName;
	if (positionService.Edit(oldPositionName, newPositionName))
	{
		cout << "Edytowano";
	}
	else
	{
		cout << "Cos jeblo";
	}
}

void PositionView::Delete()
{
	string newPositionName;
	cout << "Wpisz nazwe pozycji, ktora chcesz usunac: ";
	cin >> newPositionName;
	if (positionService.Delete(newPositionName))
	{
		cout << "Usunieto";
	}
	else
	{
		cout << "Cos jeblo";
	}
}

void PositionView::PrintAllPositions()
{
	vector<string> allPositions = positionService.GetAllPositions();
	for (int i = 0; i < allPositions.size(); i++)
	{
		cout << allPositions[i] << endl;
	}
}


