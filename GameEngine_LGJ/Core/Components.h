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