#include "RandomGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
Point2D RandomGenerator::getRanodmCordinates()
{
	Point2D position;
	srand((unsigned)time(0));                  // scrand() gives the random fucntion a new starting point time(NULL)garanties getting a new starting point every time
	double x1 = rand() % 100 + 0;       //generates random numbers from 0 to 100
	double y1 = rand() % 100 + 0;
	position = Point2D(x1, y1);
	return position;
}

std::string RandomGenerator::getRandomName()
{
	unsigned srand(time(0));
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
		entity.setEnergy(entity.getEnergy() - 1);
		break;
	case 2:
		entity.setStrenght(entity.getStrenght() - 1);
		break;
	case 3:
		entity.setEnergy(entity.getEnergy() - 0.5);
		entity.setStrenght(entity.getEnergy() - 0.5);
		break;
	}
}