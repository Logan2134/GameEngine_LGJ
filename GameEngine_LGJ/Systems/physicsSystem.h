#pragma once
#include"../Core/Engine.h"
class physicsSystem : public ECS::EntitySystem
{
public:
	physicsSystem() = default;
	~physicsSystem() = default;

	bool IsColliding(
		ECS::ComponentHandle<BoxCollider>touchingBox,
		ECS::ComponentHandle<BoxCollider>touchedBox,
		float x, float y
	);

	bool IsColliding(
		ECS::ComponentHandle<BoxCollider>touchingBox,
		sf::RectangleShape touchRectangle,
		float x, float y
	);
	
	bool IsColliding(
		ECS::ComponentHandle<BoxCollider>touchingBox,
		ECS::ComponentHandle<BoxCollider>touchedBox
		);
	
	bool IsColliding(
		ECS::ComponentHandle<BoxCollider> touchingBox,
		sf::RectangleShape touchedRectangle
	);

	void PushEntity(
		ECS::ComponentHandle<Transform> transform,
		ECS::ComponentHandle<BoxCollider> touchingBox,
		ECS::ComponentHandle<BoxCollider> touchedBox
	);

	void PushEntity(
		ECS::ComponentHandle<Transform> transform,
		ECS::ComponentHandle<BoxCollider> touchingBox,
		sf::RectangleShape touchedRectangle
	);

	void PushEntity(
		ECS::Entity* touchingEntity,
		ECS::Entity* touchedEntity
	);

	void tick(
		ECS::World* world,
		float DeltaTime
	) override;
};

