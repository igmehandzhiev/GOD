#include "Animal.h"

Animal::Animal(std::string name) :Entity(name){}

void Animal::Eat()
{
	setEnergy(getEnergy() + 5);
	setWeight(getWeight() + 10);
}

void Animal::Sleep()
{
	setEnergy(getEnergy() + 10);
	setWeight(getWeight() - 5);
}

void Animal::SearchingForFood()
{
	setEnergy(getEnergy() - 10);
	setWeight(getWeight() - 5);
}

void Animal::DoAction(State action)
{
	switch (action)
	{
	case Moving:
		setCurrentState(Moving); break;
	case Attacking:
		setCurrentState(Attacking); break;
	case Eating:
		setCurrentState(Eating); break;
	case SearchFood:
		setCurrentState(SearchFood); break;
	case Sleeping:
		setCurrentState(Sleeping); break;
	}
}

