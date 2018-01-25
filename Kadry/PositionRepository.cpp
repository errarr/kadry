#include "stdafx.h"
#include "PositionRepository.h"


PositionRepository::PositionRepository()
{
}


PositionRepository::~PositionRepository()
{
}

bool PositionRepository::Add(string name)
{
	string query = "INSERT INTO positions (name) VALUES ('" + name + "')";
	vector<string> positionNames;
	ConnectDB();
	ExecuteQueryDB(query);
	DisconnectDB();
	return true;

}

bool PositionRepository::Update(string name, string newName)
{
	string query = "UPDATE positions SET name ='" + newName + "' WHERE name = '" + name +"'";
	vector<string> positionNames;
	ConnectDB();
	ExecuteQueryDB(query);
	DisconnectDB();
	return true;

}

bool PositionRepository::Delete(string name)
{
	string query = "DELETE FROM positions WHERE name='" + name + "'";
	vector<string> positionNames;
	ConnectDB();
	ExecuteQueryDB(query);
	DisconnectDB();
	return true;
	
}

vector<string> PositionRepository::GetAllPositions()
{
	const string query = "SELECT name FROM positions";
	vector<string> positionNames;
	ConnectDB();
	vector<vector<string>> rows = ExecuteQueryDB(query);
	for (int i = 0; i < rows.size(); i++)
	{
		positionNames.push_back(rows[i][0]);
	}
	DisconnectDB();
	return positionNames;
	
	
	
	
}


