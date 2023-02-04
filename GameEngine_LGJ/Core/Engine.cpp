#include "Engine.h"

Engine& Engine::GetInstance(void)
{
	// TODO: insert return statement here
	static Engine instance;
	return instance;
}

void Engine::Start(sf::RenderWindow* window)
{
	bQuit = false;
	this->window = window;
	while (window->isOpen() == true)
	{
		Update();
	}
}

void Engine::Update(void)
{
	sf::Event event;
	while (window->pollEvent(event) == true)
	{
		//Closes event 
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}
