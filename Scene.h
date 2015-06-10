#ifndef SCENE_H
#define SCENE_H
#include "Planet.h"
#include <vector>
class Scene
{
private:
	std::string planetName;
	EntityType type;
	int number;
public:
	Scene();
	std::vector<Planet*> planet;
	void setPlanetName(std::string name){ this->planetName = name; };
	void setEntity(EntityType& t){ this->type = t; };
	void setNumber(int n){ this->number = n; };
	int getPlanetSize()const{ return planet.size(); }
	void createPlanets();
	void erasePopulation();
	void destroyPlanet();
	void addEntity();
	void getStatistics();
	void sceneUpdate();
	int check();
	~Scene();
};
#endif