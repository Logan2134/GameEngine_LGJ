#include "SFML/graphics.hpp"
#include"Entities/Player.h"
#include "Entities/Dummy.h"
#include "Core/Engine.h"
#include "Entities/Enemy.h"


int main(int argc, char* args[])
{
	// declare and get instance of singelton
	Engine& GameEngine = Engine::GetInstance();
	

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	// create world so we can add entities
	GameEngine.world = ECS::World::createWorld();

	//create our first entity
	ECS::Entity* background;
	/*ECS::Entity* myEnt;
	ECS::Entity* tux;*/

	//add systems to the engine
	GameEngine.AddSystem(new RenderingSystem());
	GameEngine.AddSystem(new AnimationSystem());
	GameEngine.AddSystem(new MovementSystem());
	GameEngine.AddSystem(new InputSystem());
	GameEngine.AddSystem(new physicsSystem());
	GameEngine.AddSystem(new TileMapSystem());
	
	background = GameEngine.world->create();
	background->assign<Transform>(0, 0, false);
	background->assign<Sprite2D>("../Debug/Pictures/bg.jpg");
	std::cout << "id: " << background->getEntityId() << std::endl;
	
	//tux = GameEngine.world->create();
	//tux->assign<Transform>(400, 400, true, 0.3f, 0.3f, 0.0f, 0.2f);
	//tux->assign<Sprite2D>("../Debug/Pictures/Tux_from_linux.png");
	//tux->assign<Animator>(56, 72, 2000.0f, 3, 9);
	//tux->assign<InputController>();
	//tux->assign<BoxCollider>();
	//tux->get<Animator>()->currentRow = 8;
	//std::cout << "id: " << tux->getEntityId() << std::endl;
	//
	//myEnt = GameEngine.world->create();
	//myEnt->assign<Transform>(200, 300, true);
	//myEnt->assign<Sprite2D>("../Debug/Pictures/herosheet.png");
	//myEnt->assign<Animator>(32, 32, 200.0f, 4, 1);
	//myEnt->assign<BoxCollider>();
	//std::cout << "id: " << myEnt->getEntityId() << std::endl;
	//Create instances of entites 
	
	Entity* player = new Player(sf::Vector2f(300.0f, 300.0f),0.05f);
	Entity* enemy = new Enemy(sf::Vector2f(200, 200),0.05f);
	Entity* dummy = new Dummy("../debug/pictures/bluebox.png", sf::Vector2f(400.0f, 400.0f));

	std::cout << dummy->entity->get<Transform>()->xPos << std::endl;
	

	//pass window refernce to engine and start
	GameEngine.Start(&window);

	return 0;
}