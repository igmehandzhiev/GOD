#include "RandomGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
Point2D RandomGenerator::getRanodmCordinates()
{
	Point2D position;
	srand((unsigned)time(0));                 
	double x1 = rand() % 100 + 1;       
	double y1 = rand() % 100 + 1;
	position = Point2D(x1, y1);
	return position;
}

std::string RandomGenerator::getRandomName()
{
	srand((unsigned)time(0));
	std::string a = "ABNECASEDOFGHIUJEKSLNEMONOPYAEOSSTUVYZNEENAEOSEFHYILANOENSSTOEUVYAEFSOHOENENLAUSNOST";
	std::string r;
	int random_len;
	random_len = (rand() % 3) + 4;
	
	for (int i = 0; i < random_len; i++)
		r.push_back(a.at(size_t(rand() % 75)));
	std::cout << r << std::endl;
	return r;
}
  

void RandomGenerator::getRandomDamage(Entity& entity)
{
	srand((unsigned)time(0));
	int code = rand() % 3 + 1;            
	switch (code)
	{
	case 1:
		entity.setEnergy(entity.getEnergy() - 10);
		break;
	case 2:
		entity.setStrenght(entity.getStrenght() - 10);
		break;
	case 3:
		entity.setEnergy(entity.getEnergy() - 5);
		entity.setStrenght(entity.getEnergy() - 5);
		break;
	}
}