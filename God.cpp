#include "God.h"
#include <iostream>
God::God(std::string name) :Human(name){}

God::God()
{}

void God::CreatePlanets()
{
	sc->createPlanets();

}

void God::ErasePopulation(std::string planetName)
{
	sc->setPlanetName(planetName);
	sc->erasePopulation();

}

void God::DestroyPlanet(std::string planetName)
{
	sc->setPlanetName(planetName);
	sc->destroyPlanet();

}

void God::AddEntity(std::string planetName, int number, EntityType type)
{
	sc->setPlanetName(planetName);
	sc->setEntity(type);
	sc->setNumber(number);
	sc->addEntity();
}

void God::GetStatistics()
{
	sc->getStatistics();
}

int God::Check()
{
	sc->check();
	return 0;
}

God::~God()
{
	delete sc;
}

God& God:: operator=(God& s)
{
	sc = s.sc;
	return *this;
}