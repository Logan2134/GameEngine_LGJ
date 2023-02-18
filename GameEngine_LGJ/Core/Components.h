#pragma once
#include "Engine.h"



struct Transform
{
public:
	ECS_DECLARE_TYPE;
	float xPos, yPos;
	float roatation{ 0.0f };

	Transform(float xPos, float yPos)
	{
		this->xPos = xPos;
		this->yPos = yPos;
	}
};
ECS_DEFINE_TYPE(Transform)
struct Sprite2D
{
public:
	ECS_DECLARE_TYPE;
	sf::Sprite self;
	std::string texturePath;
	int width, height;
	Sprite2D(std::string texturePath)
	{
		this->texturePath = texturePath;

	}
};
ECS_DEFINE_TYPE(sprite2D)

struct Animator
{
public:
	ECS_DECLARE_TYPE;

	int width, height, currentColumn, currentRow, totalColumns, totalRows;
	
	float currentTime, nextFrameTime;
	Animator(int width, int height, float nextFrameTime, int columns, int rows)
	{
		currentColumn = 0;
		currentRow = 0;
		currentTime = 0.0f;
		totalColumns = columns;
		totalRows = rows;
		this->height = height;
		this->width = width;
		this->nextFrameTime = nextFrameTime;
	}

}; ECS_DEFINE_TYPE(Animator)

struct InputController
{
public:
	ECS_DECLARE_TYPE;
	
	bool bInputActive;
	bool w, a, s, d, left, right, up, down, space;

	InputController()
	{
		std::memset(this, false, sizeof(InputController));
		this->bInputActive = true;
	}

}; ECS_DEFINE_TYPE(InputController)