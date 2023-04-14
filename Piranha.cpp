#pragma once
#include "stdafx.h"

Piranha::Piranha(float x, float y)
{
	name = "Piranha";
	healthPoints = 1;
	attackDamage = 1;

	sprite.push_back(new Sprite(PIRANHA, 0, 1, 0, 5.0f, Sprite::AnimationStates::LOOP_FORWARD));
	sprite[0]->hitBox.push_back(new HitBox());

	mechanics.position.x = x;
	mechanics.position.y = y;

}

Piranha::~Piranha()
{

}

void Piranha::update()
{
	sprite[0]->hitBox[0]->box.x = sprite[0]->transformation.translate.x;
	sprite[0]->hitBox[0]->box.y = sprite[0]->transformation.translate.y;

}

void Piranha::print() const
{
	Entity::print();
}
