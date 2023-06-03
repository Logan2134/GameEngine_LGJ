#pragma once
#include<iostream>
#include"SFML/graphics.hpp"
#include "ECS.h"
#include "Components.h"
#include "..\Systems\RenderingSystem.h"
#include "..\Systems\AnimationSystem.h"
#include"../Systems/MovementSystem.h"
#include "../Systems/InputSystem.h"
#include"..\Systems\physicsSystem.h"
#include"../Interface/States.h"
#include "../Systems/TileMapSystem.h"

class PauseMenu;
class States;
class MainCamera;

class Engine
{
public:
	sf::RenderWindow* window{ nullptr };
	ECS::World* world{ nullptr };
	PauseMenu* pauseMenu{ nullptr };
	MainCamera* mainCamera{ nullptr };

private:
	bool bQuit;
	const float deltaTime = 10.0f;

private:
	Engine(void) = default;
	~Engine(void) = default;
	
	
public:
	// required to prevent the reference from being copied, moved, or assigned
	Engine(Engine& copy) = delete; // hide copy constructer
	Engine(Engine&& other) = delete; // hide move constructer
	Engine& operator= (Engine& copy) = delete; // hide assignment operator
	
public:
	static Engine& GetInstance(void);
	void Start(sf::RenderWindow* window);
	void AddSystem(ECS::EntitySystem* newSystem) const;

private:
	void Update(void);
	void OnPaused()const;
};

