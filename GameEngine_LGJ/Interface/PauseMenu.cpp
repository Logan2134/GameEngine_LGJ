#include "PauseMenu.h"
#include "Gui_Components/ButtonMap.h"
#include "States.h"
#include "Gui_Components/Button.h"

PauseMenu::PauseMenu(sf::RenderWindow* window)
{
	States::SetPausedState(false);
	InitButtons();
}

void PauseMenu::Update(sf::Event event, float DeltaTime, sf::RenderWindow* window) const
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Pause))
		{
			States::SetPausedState(States::GetPausedState() == false);

		}
	}

	if (States::GetPausedState() == true)
	{
		ButtonMap::GetMap()["RESUME"]->Update(event, DeltaTime);
		ButtonMap::GetMap()["LOAD"]->Update(event, DeltaTime);
		ButtonMap::GetMap()["SAVE"]->Update(event, DeltaTime);
		ButtonMap::GetMap()["QUIT"]->Update(event, DeltaTime);
		
		if (ButtonMap::GetMap()["RESUME"]->bClicked == true)
		{
			States::SetPausedState(false);
			ButtonMap::GetMap()["RESUME"]->bClicked = false;
		
		}
		if (ButtonMap::GetMap()["QUIT"]->bClicked == true)
		{
			this->Quit(window);
			ButtonMap::GetMap()["RESUME"]->bClicked = false;
		}
	}
	
}

void PauseMenu::Render(sf::RenderWindow* window, float DeltaTime, sf::Vector2f resumePosition)
{
	sf::Font font;
	font.loadFromFile("../Debug/Fonts/Times.TTF");
	sf::Vector2f sizeOffset = ButtonMap::GetMap()["RESUME"]->buttonBG.getSize()/2.0f;

	ButtonMap::GetMap()["RESUME"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -80) - sizeOffset);
	ButtonMap::GetMap()["RESUME"]->buttonText.setFont(font);
	ButtonMap::GetMap()["RESUME"]->buttonText.setPosition(ButtonMap::GetMap()["RESUME"]->buttonBG.getPosition());
	ButtonMap::GetMap()["RESUME"]->Highlight(window);
	ButtonMap::GetMap()["RESUME"]->Render(window, DeltaTime);

	ButtonMap::GetMap()["LOAD"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -40) - sizeOffset);
	ButtonMap::GetMap()["LOAD"]->buttonText.setFont(font);
	ButtonMap::GetMap()["LOAD"]->buttonText.setPosition(ButtonMap::GetMap()["LOAD"]->buttonBG.getPosition());
	ButtonMap::GetMap()["LOAD"]->Highlight(window);
	ButtonMap::GetMap()["LOAD"]->Render(window, DeltaTime);

	ButtonMap::GetMap()["SAVE"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 0) - sizeOffset);
	ButtonMap::GetMap()["SAVE"]->buttonText.setFont(font);
	ButtonMap::GetMap()["SAVE"]->buttonText.setPosition(ButtonMap::GetMap()["SAVE"]->buttonBG.getPosition());
	ButtonMap::GetMap()["SAVE"]->Highlight(window);
	ButtonMap::GetMap()["SAVE"]->Render(window, DeltaTime);

	ButtonMap::GetMap()["QUIT"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 40) - sizeOffset);
	ButtonMap::GetMap()["QUIT"]->buttonText.setFont(font);
	ButtonMap::GetMap()["QUIT"]->buttonText.setPosition(ButtonMap::GetMap()["QUIT"]->buttonBG.getPosition());
	ButtonMap::GetMap()["QUIT"]->Highlight(window);
	ButtonMap::GetMap()["QUIT"]->Render(window, DeltaTime);

	window->display();
}

void PauseMenu::InitButtons()
{
	sf::Vector2f size(125.0f, 35.0f);

	ButtonMap::GetMap().insert(
		{
			"RESUME",new Button(size, sf::Color(100,100,100,255), "Resume Game")
		});
	ButtonMap::GetMap().insert(
		{
			"LOAD",new Button(size, sf::Color(100,100,100,255), "Load Tile Map")
		});
	ButtonMap::GetMap().insert(
		{
			"SAVE",new Button(size, sf::Color(100,100,100,255), "Save Tile Map")
		});
	ButtonMap::GetMap().insert(
		{
			"QUIT",new Button(size, sf::Color(100,100,100,255), "Quit Game")
		});

}

void PauseMenu::Quit(sf::RenderWindow* window)
{
	window->close();
}
