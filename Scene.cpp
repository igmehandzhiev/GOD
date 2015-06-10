#include "Scene.h"
#include <iostream>
#include "RandomGenerator.h"
Scene::Scene(){}
void Scene::createPlanets()
{
	RandomGenerator object;
	std::string name = object.getRandomName();
	planet.push_back(new Planet(name));
}

void Scene::erasePopulation()
{
	check();
	int IStherePlanet=0;
	for (unsigned int i = 0; i < planet.size(); i++)
	{
		if (planet[i]->getName() == planetName.data())
		{
			planet[i]->erasePopulation();
			std::cout << "You have just erased the population of a planet!\n";
			std::cout << "\n";
			IStherePlanet = 1;
		}
		else
			IStherePlanet=0;
	}
	if (IStherePlanet == 0) std::cout << "There is no such a Planet\n";
	
}

void Scene::destroyPlanet()
{
	check();
	int IStherePlanet=0;
	for (unsigned int i = 0; i < planet.size(); i++)
	{
		if (planet[i]->getName() == planetName.data())
		{
			planet.erase(planet.cbegin() + i);
			std::cout << "You have just destroyed "<<i+1<<"th planet!\n";
			std::cout << "\n";
			IStherePlanet = 1;
			break;
		}
		else
		IStherePlanet = 0;
	}
	if (IStherePlanet == 0) std::cout << "There is no such a planet!\n";

}

void Scene::addEntity()
{
	
	for (unsigned int i = 0; i < planet.size(); i++)
	{

		if (planet[i]->getName() == planetName)
		{
				planet[i]->addPopulation(type, number);
		}
	}
	
}

void Scene::getStatistics()
{
	for (unsigned int i = 0; i < planet.size(); i++)
	{
		std::cout << "Planet "<< i+1<<" name is: "<< planet[i]->getName() << "\t";
		std::cout << "With population :"<<planet[i]->getPopulation() << std::endl;
	}
	if (planet.size() == 0)
	{
		std::cout << "You have no planets :("<<std::endl;
	}
}

int Scene::check()
{
	if (planet.size() == 0)
	{
		return 0;
	}
	return 1; 
}

Scene::~Scene()
{
	while (!planet.empty())
	{
		delete planet.back();
		planet.pop_back();
	}
}

void Scene::sceneUpdate()
{
	for (unsigned int i = 0;i<planet.size(); i++)
	{
		planet[i]->movePopulation();
		planet[i]->findPosition();
	}
	
}
