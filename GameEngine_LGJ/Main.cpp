#include "SFML/graphics.hpp"
#include "Core/Engine.h"

int main(int argc, char* args[])
{
	// declare and get instance of singelton
	Engine& GameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	// create world so we can add entities
	GameEngine.world = ECS::World::createWorld();

	//create our first entity
	ECS::Entity* myEnt;

	//add systems to the engine
	GameEngine.AddSystem(new RenderingSystem());

	//create 250 entites to the world
	for (int i = 0; i < 250; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			myEnt = GameEngine.world->create();
			myEnt->assign<Transform>(i * 250, j * 32);
			myEnt->assign<Sprite2D>("../Debug/Pictures/hero.png");
			std::cout << "id: " << myEnt->getEntityId() << std::endl;
		}
	}

	//pass window refernce to engine and start
	GameEngine.Start(&window);

	return 0;
}