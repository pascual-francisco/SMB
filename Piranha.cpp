#pragma once
#include "stdafx.h"

Piranha::Piranha(float x, float y)
{
	name = "Piranha";
	healthPoints = 1;
	attackDamage = 1;

//	sprite.push_back(new Sprite(PIRANHA, 0, 1, 0, 5.0f, Sprite::AnimationStates::LOOP_FORWARD));
	mechanics.position.x = x;
	mechanics.position.y = y;

}

Piranha::~Piranha()
{

}

void Piranha::update()
{

}

void Piranha::print() const
{
	Entity::print();
}
