#include "Piranha.h"

Piranha::Piranha(float x, float y)
{
	name = "Piranha";
	healthPoints = 1;
	attackDamage = 1;

   sprite.push_back(new Sprite(PALETTE_1));
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
