#include "TileMapSystem.h"
#include "../Interface/Gui_Components/ButtonMap.h"
#include "../Interface/Gui_Components/Button.h"

void TileMapSystem::tick(ECS::World* world, float DeltaTime)
{
	if (States::GetPausedState() == false)
	{
		Engine::GetInstance().world->each<TileMap>(
			[&](ECS::Entity* entity, ECS::ComponentHandle<TileMap> tilemap)->void 
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					this->AddTileOnClick(true, tilemap);
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)
				{
					this->AddTileOnClick(false, tilemap);
				}

				if (ButtonMap::GetMap()["SAVE"]->bClicked == true)
				{
					tilemap->SaveTileMap("Tiletest.txt");
					ButtonMap::GetMap()["SAVE"]->bClicked = false;
					std::cout << "SAVED" << std::endl;
				}
				
				if (ButtonMap::GetMap()["LOAD"]->bClicked == true)
				{
					tilemap->LoadTileMap("Tiletest.txt");
					ButtonMap::GetMap()["LOAD"]->bClicked = false;
					std::cout << "LOADED" << std::endl;
				}
			});

	}
}

void TileMapSystem::AddTileOnClick(bool bHasCollision, ECS::ComponentHandle<TileMap> tileMap) const
{
	//reference for window pointer to determine active cursor position for adding tiles

	sf::RenderWindow* winref = Engine::GetInstance().window;

	sf::Vector2f mousePosView = winref->mapPixelToCoords(sf::Mouse::getPosition(*winref));

	sf::Vector2i mousePosGrid(static_cast<int>(mousePosView.x / tileMap->gridSizeF), static_cast<int>(mousePosView.y / tileMap->gridSizeF));
	tileMap->AddTile(mousePosGrid.x, mousePosGrid.y, 0, bHasCollision);
}
