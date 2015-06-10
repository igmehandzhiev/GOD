#include "Entity.h"
#include "RandomGenerator.h"
#include <time.h>
#include <iostream>
Entity::Entity()
{
	name="Gertrud";
	energy=250;
	size = 5;
    weight=50;
	strenght=45;
	setPosition(1,1);
	setCurrentState(Sleeping);
}
Entity::Entity(std::string name1)
{
	this->name = name1;
}

Entity::Entity(Entity& en)
{
	*this = en;
}
void Entity::Attack(Entity& entity)
{
	RandomGenerator object;
	if (this->strenght>entity.getStrenght())
		object.getRandomDamage(entity);
}
void Entity::Move()
{
	RandomGenerator object;
	this->position = object.getRanodmCordinates();
}

void Entity::DoAction()
{
	srand((unsigned)time(0));
	int random = rand() % 2;
	switch (random)
	{
	case 0:
		std::cout << "Entity Moving...";
		Move();
		setCurrentState(Moving);
		break;
	case 1:
		Entity enem;
		std::cout << "Entity Attacking enemy with " << enem.getEnergy() << " energy."<<std::endl;
		Attack(enem);
		std::cout << "Attacked enemy is now with " << enem.getEnergy() << " energy." << std::endl;;
		setCurrentState(Attacking); break;
	}
}
