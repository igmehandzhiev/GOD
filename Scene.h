#ifndef SCENE_H
#define SCENE_H
#include "Planet.h"
#include <vector>
class Scene
{
private:
	std::vector<Entity*>population;
	std::string planetName;
	EntityType type;
	int number;
public:
	std::vector<Planet*> planet;
	Scene();
	Scene(Scene& s);
	~Scene();
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
};
#endif