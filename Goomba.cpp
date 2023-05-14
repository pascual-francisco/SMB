#include "Goomba.h"

Goomba::Goomba(float x, float y)
{
	name = "Goomba";
	healthPoints = 1;
	attackDamage = 1;

   sprite.push_back(new Sprite(PALETTE_1));

	mechanics.position.x = x;
	mechanics.position.y = y;
	mechanics.speed.x = -0.2f;
	//alpha color = 146-144-255-1
}

Goomba::~Goomba()
{

}

void Goomba::update()
{

}

void Goomba::print() const
{
	Entity::print();
}


//Delegates//
Goomba::GoombaIdle::GoombaIdle(Goomba *goomba)
{

}

Goomba::GoombaIdle::~GoombaIdle()
{

}

void Goomba::GoombaIdle::enter()
{

}

void Goomba::GoombaIdle::exit()
{

}

void Goomba::GoombaIdle::update()
{

}



