#include "stdafx.h"
#include "BaseRepository.h"
#include <stdexcept>

BaseRepository::BaseRepository()
{
}


BaseRepository::~BaseRepository()
{
}

void BaseRepository::ConnectDB()
{
	mysql_init(&mysql);
	//TODO przeniesc do resource
	mysql_real_connect(&mysql, "127.0.0.1", "root", "kadry", "kadry", 3306, NULL, 0);
	mysql_select_db(&mysql, "kadry");
}

void BaseRepository::DisconnectDB()
{
	mysql_close(&mysql);
}

vector<vector<string>> BaseRepository::ExecuteQueryDB(string query)
{
	MYSQL_RES *queryId;
	MYSQL_ROW fetchedRow;
	vector<vector<string>> rows;
	char* convertedQuery = ConversionHelper::StringToChar(query);
	mysql_query(&mysql, convertedQuery);
	if ((mysql.net.last_error != NULL) && (mysql.net.last_error[0] != '\0'))
	{
		const char * error = ConversionHelper::StringToChar("SQL error " + query);
		throw exception(error);
	}
	delete[] convertedQuery;
	queryId = mysql_store_result(&mysql);
	if (queryId != NULL)
	{
		while ((fetchedRow = mysql_fetch_row(queryId)) != NULL)
		{
			vector<string> row;
			for (int i = 0; i < mysql_num_fields(queryId); i++)
			{
				row.push_back(fetchedRow[i] != NULL ? fetchedRow[i] : "");
			}
			rows.push_back(row);
		}
	}
	return rows;
}
