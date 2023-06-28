#include "Troopa.h"

Troopa::Troopa(float x, float y)
{
	name = "Troopa";
	healthPoints = 1;
	attackDamage = 1;

   sprite.push_back(new Sprite(PALETTE_1));

	mechanics.position.x = x;
	mechanics.position.y = y;
   mechanics.speed.x = -0.3f;


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
