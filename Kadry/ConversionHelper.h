#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
static class ConversionHelper
{
public:
	
	static char * StringToChar(string text);
	static string FloatToString(float number);
	static string IntToString(int number);
	static int StringToInt(string text);
	static float StringToFloat(string text);
};

