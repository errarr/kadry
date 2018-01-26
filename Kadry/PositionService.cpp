#include "stdafx.h"
#include "PositionService.h"


PositionService::PositionService()
{
}


PositionService::~PositionService()
{
}

bool PositionService::Add(string name)
{
	try
	{
		positionRepository.Add(name);
		return true;
	}
	catch (const std::exception& ex)
	{
		return false;
	}
}

bool PositionService::Edit(string name, string newName)
{
	try
	{
		positionRepository.Update(name, newName);
		return true;
	}
	catch (const std::exception& ex)
	{
		return false;
	}
	
}

bool PositionService::Delete(string name)
{
	try
	{
		positionRepository.Delete(name);
		return true;
	}
	catch (const std::exception& ex)
	{
		return false;
	}
}

vector<string> PositionService::GetAllPositions()
{
	try
	{
		return positionRepository.GetAllPositions();
	}
	catch (const std::exception& ex)
	{
		return vector<string>();
	}
	
}
