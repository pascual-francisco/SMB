#include "stdafx.h"

Troopa::Troopa(float x, float y)
{
	name = "Troopa";
	healthPoints = 1;
	attackDamage = 1;

//	sprite.push_back(new Sprite(TROOPA, 0, 1, 0, 10.0f, Sprite::AnimationStates::LOOP_FORWARD));

	mechanics.position.x = x;
	mechanics.position.y = y;
//	mechanics.speed.x = -0.3f;


}


Troopa::~Troopa()
{

}

void Troopa::update()
{

}

void Troopa::print() const
{
	Entity::print();
}
