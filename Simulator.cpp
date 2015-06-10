#include "Simulator.h"
#include "Planet.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <windows.h>

void Simulator::Run()
{ 
	Menu();
	std::thread(&Simulator::Menu, Simulator());
}
void Simulator::Update()
{
	std::thread t1(&Simulator::Update1, this);
	t1.join();
	sc->sceneUpdate();
	for (int i = 0; i < sc->getPlanetSize(); i++)
	{
		sc->planet[i]->Update();
	}
}
void Simulator::Update1(){

	for ( int i = 0; i < sc->getPlanetSize(); i++)
	{
		sc->planet[i]->Update();
	}
}

Simulator::~Simulator()
{
	delete m_player;
	delete sc;
	delete command;
}

Simulator& Simulator::operator=( Simulator& sim)
{
	sc = sim.sc;
	m_player = sim.m_player;
	command = sim.command;
	return *this;
}
void Simulator::Menu()
{
	int selection;
	int howManyPlanets = 0;
	std::string str = "";
	std::cout << "                       #######      ########        ###" << std::endl;
	std::cout << "                       #######      ########        ####" << std::endl;
	std::cout << "                       ##  @##      ##    ##        ## ##" << std::endl;
	std::cout << "        @              ##           ##    ##        ##  ##" << std::endl;
	std::cout << "  @    ()    @         ##           ##    ##        ##   ##" << std::endl;
	std::cout << " ( )  (##)  ( )        ##           ##    ##        ##    ##" << std::endl;
	std::cout << " (##)(####)(##)        ##  ###      ##    ##        ##    ##" << std::endl;
	std::cout << "  (##########)         ##  ###      ##    ##        ##   ##" << std::endl;
	std::cout << "   ----------          ##   ##      ##    ##        ##  ##" << std::endl;
	std::cout << "   |########|          #######      ########        #####" << std::endl;
	std::cout << "---------------------- #######      ########        ####--------------------------------------------------------------------------------------------------------";
	std::cout << "  WELCOME!YOU'RE THE NEW GOD! PLEASE, CHOOSE ACTION FROM BELOW\n";
	std::cout << "  ====================================\n";
	std::cout << "  1.  Create new planet\n";
	std::cout << "  2.  Erase the population of a planet\n";
	std::cout << "  3.  Destroy planet\n";
	std::cout << "  4.  Get statistic about your planets\n";
	std::cout << "  5.  Add population to some planet\n";
	std::cout << "      Your command should look like this:\n ";
	std::cout << "      add <name of planet> <number> <entity|animal|human|god> ";
	std::cout << "\n";
	std::cout << "  6.  Update\n";
	std::cout << "  7.  See MENU again\n";
	std::cout << "  8.  Exit\n";
	std::cout << "  ====================================\n";


	do
	{
		std::cout << "Enter your command: ";
		std::cin >> selection;
		if (selection == 1) howManyPlanets++;
		std::cout << std::endl;
		switch (selection)
		{
		case 1:
			std::cout << "Congrats! You'veS created the planet:\n";
			m_player->CreatePlanets();
			std::cout << "\n";
			break;

		case 2:
			if (howManyPlanets == 0){
				std::cout << "You haven't created a Planet yet. Select 1 to create now!\n\n ";
				break;
			}
			else
			{
				std::cout << "Enter the name of the planet, which population you want ot erase:\n";
				std::cin.ignore();
				std::getline(std::cin, str);
				m_player->ErasePopulation(str);
			}
			break;
		case 3:
			if (howManyPlanets == 0){
				std::cout << "You haven't created a Planet yet. Select 1 to create now!\n\n ";
				break;
			}
			std::cout << "Enter the name of the planet, which you want ot destroy:\n";
			std::cin.ignore();
			std::getline(std::cin, str);
			m_player->DestroyPlanet(str);
			break;
		case 4:
			m_player->GetStatistics();
			break;
		case 5:
			if (howManyPlanets == 0){
				std::cout << "You haven't created a Planet yet. Select 1 to create now!\n\n ";
				break;
			}
			command->readCommand();
			m_player->AddEntity(command->getName(), command->getNumber(), command->getType());
			std::cout << "You have just added !\n";
			std::cout << "\n";
			break;
		case 6:
			std::cout << "Updating: ";
			Update();
			break;
		case 7: 
			std::cout << "  1.  Create new planet\n";
			std::cout << "  2.  Erase the population of a planet\n";
			std::cout << "  3.  Destroy planet\n";
			std::cout << "  4.  Get statistic about your planets\n";
			std::cout << "  5.  Add population to some planet\n";
			std::cout << "      Your command should look like this:\n ";
			std::cout << "      add <name of planet> <number> <entity|animal|human|god> ";
			std::cout << "\n";
			std::cout << "  6.  Update\n";
			std::cout << "  7.  See MENU again\n";
			std::cout << "  8.  Exit\n";
			std::cout << "  ====================================\n";
			break;
		case 8:
			std::cout << "THANK YOU FOR PLAYING. GOODBYE!\n";
			Sleep(999);
			exit(0);
			system("pause");
			break;

		default: std::cout << selection << "It is not a valid action.Please choose allowed action!\n";

			std::cout << std::endl;
		}

	} while (str != "7");

}