#pragma once
#include "Engine.h"



struct Transform
{
public:
	ECS_DECLARE_TYPE;
	float xPos, yPos;
	float rotationAngle;
	float rotationSpeed;
	float xSpeed, ySpeed;
	float xSpeedMod, ySpeedMod;
	bool bCollide;

	Transform(float xPos, float yPos, bool bCollide, float xSpeed = 0.0f, float ySpeed = 0.0f, float rotationAngle = 0.0f, float rotationSpeed = 0.0f)
	{
		this->xPos = xPos;
		this->yPos = yPos;
		this->xSpeed = xPos;
		this->ySpeed = yPos;
		this->xSpeedMod = xSpeed;
		this->ySpeedMod = ySpeed;
		this->rotationAngle = rotationAngle;
		this->rotationSpeed = rotationSpeed;
		this->bCollide = bCollide;
	}

	void Move()
	{
		if (bCollide == false)
		{
			this->xPos += xSpeed;
			this->yPos += ySpeed;
		}
	}
	
};
ECS_DEFINE_TYPE(Transform)
struct Sprite2D
{
public:
	ECS_DECLARE_TYPE;
	sf::Sprite self;
	std::string texturePath;
	float width, height;
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