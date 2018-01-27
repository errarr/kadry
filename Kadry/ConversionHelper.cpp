#include "stdafx.h"
#include "ConversionHelper.h"
#include <sstream>


char * ConversionHelper::StringToChar(string str)
{
	//po tej metodzie u¿yæ delete
	int lenght = str.length() + 1;
	char *cstr = new char[lenght];
	strcpy(cstr, str.c_str());
	return cstr;
}
string ConversionHelper::FloatToString(float number)
 {
	ostringstream buff;
	buff << number;
	return buff.str();
}

string ConversionHelper::IntToString(int number)
{
	stringstream ss;
	ss << number;
	string str = ss.str();
	return str;
}

int ConversionHelper::StringToInt(string text)
{
	return atoi(StringToChar(text));
}
