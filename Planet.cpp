#include "Planet.h"
#include "Animal.h"
#include "Human.h"
#include "God.h"
#include <time.h>
#include <iostream>
Planet::Planet(std::string name){ this->name = name;  }

void Planet::erasePopulation(){ population.clear(); }
Planet::~Planet()
{
	for (int i = 0; i < population.size(); ++i)
	{
		population.erase(population.begin() + i);
	}
}
void Planet::addPopulation(EntityType type, int number)
{
	for (int i = 0; i < number; i++)
	{
		switch (type)
		{
		case entity:
			population.push_back(new Entity()); break;
		case animal:
			population.push_back(new Animal()); break;
		case human:
			population.push_back(new Human()); break;
		case god:
			population.push_back(new God()); break;
		}
		
	}
}

void Planet::movePopulation()
{
	for (unsigned int j = 0; j < population.size(); j++)
	{
		population[j]->Move();
	}
	std::cout << "Population moving...";
}

void Planet::findPosition()
{
	Point2D a;
	for ( int j = 0; j <getPopulation(); j++)
	{
		for (int k = j + 1; k < getPopulation(); k++)
		{
			if (a.getDistance(population[j]->getPosition(), population[k]->getPosition()) < 5)
			{
				int random = rand() % 2 + 1;
				switch (random)
				{
				case 1:
					population[j]->Attack(*population[j]);
					break;
				case 2:
					addPopulation(entity, 1);

				}
			}
			else if (a.getDistance(population[j]->getPosition(), population[k]->getPosition()) == 0)
			{
				movePopulation();
			}
		}
	}
}
void Planet::Update(){

	for (unsigned int i = 1; i < population.size(); i++)
	{
		population[i]->DoAction();
	}
	std::cout << "DOingAction";
}