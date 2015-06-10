#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "God.h"
#include "CommandManager.h"
#include <thread>
class Simulator
{
private:
	God* m_player = new God;
	Scene* sc = new Scene;
	CommandManager* command = new CommandManager;
public:
	Simulator(){}
	Simulator(Simulator& s){ *this = s; }
	Simulator& operator=(Simulator&);
	void Run();
	void Update();
	void Update1();
	void Menu();
	void Test();
	~Simulator(); 
};
#endif