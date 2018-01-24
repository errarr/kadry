#pragma once
#include <mysql.h>
#include <iostream>
#include "ConversionHelper.h"
#include <vector>

using namespace std;
class BaseRepository
{
public:
	BaseRepository();
	~BaseRepository();

protected:
	MYSQL mysql;
	void ConnectDB();
	void DisconnectDB();
	vector<vector<string>> ExecuteQueryDB(string query);
};