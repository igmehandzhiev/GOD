#include "Scene.h"
#include <iostream>
#include "RandomGenerator.h"
Scene::Scene(){}

Scene::Scene(Scene& s)
{
	*this = s;
}
Scene::~Scene()
{
	int size = planet.size();
		for (unsigned int i = 0; i < size; i++)
		{
			delete planet.back();
			planet.pop_back();
		}
}

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
			std::cout << "You have just erased the population of the planet " << planet[i]->getName();
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
	int IStherePlanet=0;
	for (unsigned int i = 0; i < planet.size(); i++)
	{
		if (planet[i]->getName() == planetName.data())
		{
			IStherePlanet = 1;
			int c = i % 10;
			switch (c)
			{
				case 0: std::cout << "You have just destroyed " << i + 1 << "st planet!\n\n"; break;
				case 1: std::cout << "You have just destroyed " << i + 1 << "nd planet!\n\n"; break;
				case 2: std::cout << "You have just destroyed " << i + 1 << "rd planet!\n\n"; break;
				default: std::cout << "You have just destroyed " << i + 1 << "th planet!\n\n"; break;
				break;
			}
					delete planet[i];
					planet.erase(planet.begin() + i);
					std::cout << planet.size();
					i--;
		}
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



void Scene::sceneUpdate()
{
	for (unsigned int i = 0;i<planet.size(); ++i)
	{
		planet[i]->movePopulation();
		planet[i]->findPosition();
		std::cout << "Population Moving...\n\n";
	}
	std::cout << "Population Moving...\n\n";
	
	
}
