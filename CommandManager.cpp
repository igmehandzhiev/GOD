#include "CommandManager.h"
#include <vector>
#include <iostream>
#include <sstream>
void CommandManager::readCommand()
{
	std::string str = "";
	std::cin.ignore();
	std::getline(std::cin, str);
	std::stringstream ss(str);
	std::string token;
	std::vector<std::string> command;
	while (ss >> token)
	{
		command.push_back(token);
	}
	if (command[0] == "add")
	{
		nameofPlanet = command[1];
		number = std::stoi(command[2]);
		if (command[3] == "entity")
		{
			type = entity;
		}
		else if (command[3] == "animal")
		{
			type = animal;
		}
		else if (command[3] == "human")
		{
			type = human;
		}
		else
		{
			type = god;
		}
	}
	
}