#include "SFML/graphics.hpp"
#include "Core/Engine.h"

int main(int argc, char* args[])
{
	// declare and get instance of singelton
	Engine& GameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");
	//pass window refernce to engine and start
	GameEngine.Start(&window);

	return 0;
}