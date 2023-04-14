#pragma once
#include "stdafx.h"

Troopa::Troopa(float x, float y)
{
	name = "Troopa";
	healthPoints = 1;
	attackDamage = 1;

	sprite.push_back(new Sprite(TROOPA, 0, 1, 0, 10.0f, Sprite::AnimationStates::LOOP_FORWARD));
	sprite[0]->hitBox.push_back(new HitBox());

	mechanics.position.x = x;
	mechanics.position.y = y;
//	mechanics.speed.x = -0.3f;


}


Troopa::~Troopa()
{

}

void Troopa::update()
{
	sprite[0]->hitBox[0]->box.x = sprite[0]->transformation.translate.x;
	sprite[0]->hitBox[0]->box.y = sprite[0]->transformation.translate.y;
}

void Troopa::print() const
{
	Entity::print();
}
