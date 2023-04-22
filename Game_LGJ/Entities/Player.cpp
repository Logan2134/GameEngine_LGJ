#include "Player.h"

Player::Player(sf::Vector2f location) : Soldier("../debug/pictures/player_1.png", location)
{
	entity->assign<InputController>();
	entity->assign<Tag>();
	entity->get<Tag>()->AddTag("Player");
}
