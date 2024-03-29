#include "MainCamera.h"
#include "States.h"

MainCamera::MainCamera(sf::Vector2f pivot)
{
	this->cameraView.setCenter(pivot);
}

void MainCamera::Update(ECS::World* world, float DeltaTime, sf::RenderWindow* window)
{
	if (States::GetPausedState() == false)
	{
		this->cameraView.setSize(static_cast<float>(window->getSize().x), static_cast<float> (window->getSize().y));
		const float camreaMoveSpeed = 0.1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
		{
			this->cameraView.move(-camreaMoveSpeed * DeltaTime, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
		{
			this->cameraView.move(camreaMoveSpeed * DeltaTime, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true)
		{
			this->cameraView.move(0, -camreaMoveSpeed * DeltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
		{
			this->cameraView.move(0, camreaMoveSpeed * DeltaTime);
		}

		window->setView(this->cameraView);
	}
}
