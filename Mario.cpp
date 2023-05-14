#include "stdafx.h"

Mario::Mario(float x, float y)
{
	name = "Mario";
	healthPoints = 1;
	attackDamage = 1;
	direction = 0;

    marioIdle = nullptr;
	marioWalk = nullptr;
	marioShoot = nullptr;
	marioJump = nullptr;
	marioHit = nullptr;
	marioKO = nullptr;

	leftButton = false;
	rightButton = false;
	upButton = false;
	downButton = false;
	jumpButton = false;
	fireButton = false;

	sprite.push_back(new Sprite(PALETTE_8, 1));

	sprite[0]->transformation.pivot.x = 7.0f;
	mechanics.position.x = x;
	mechanics.position.y = y;
	mechanics.maxSpeed.x = 1.5f;
	mechanics.maxSpeed.y = 1.5f;
	mechanics.gravity.y = -0.1f;

	marioIdle = new MarioIdle(this);
	marioWalk = new MarioWalk(this);
	marioShoot = new MarioShoot(this);
	marioJump = new MarioJump(this);
	marioHit = new MarioHit(this);
	marioKO = new MarioKO(this);

	brain.push(marioIdle);
	brain.top()->enter();
}

Mario::~Mario()
{
	delete marioIdle;
	delete marioWalk;
	delete marioShoot;
	delete marioHit;
	delete marioKO;
}

void Mario::update()
{
   sprite[0]->transformation.rotate.y = direction;

	if( mechanics.position.x < 256)
	{
      mechanics.position.x++;
	}
	else
	{
	   mechanics.position.x = 0;
	}

//////
// GLint pageDimensionX = 0;
//   GLint pageDimensionY = 0;
//	glBindTexture(GL_TEXTURE_2D_ARRAY, sprite->texturePalette);
//	glGetTexLevelParameteriv(GL_TEXTURE_2D_ARRAY, 0, GL_TEXTURE_WIDTH, &pageDimensionX);
//	glGetTexLevelParameteriv(GL_TEXTURE_2D_ARRAY, 0, GL_TEXTURE_HEIGHT, &pageDimensionY);
//	glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
//
//  	GLfloat textureX = ( (sprite->tilePosition.x * sprite->tileDimension.x) + (1 *  sprite->tilePosition.x) ) / pageDimensionX;
//	GLfloat textureY = ( (sprite->tilePosition.y * sprite->tileDimension.y) + (1 *  sprite->tilePosition.y) ) / pageDimensionY;
//	GLfloat textureW = sprite->tileDimension.x / pageDimensionX;
//	GLfloat textureH = sprite->tileDimension.y / pageDimensionY;
////
//	if(sprite->ptrAnimation != nullptr)
//	{
//		textureX = ( ( (sprite->tilePosition.x + sprite->ptrAnimation->actualFrame) *  sprite->tileDimension.x ) + (1 *  sprite->tilePosition.x) ) / pageDimensionX;
//	}

//	if (!leftButton && !rightButton)
//		mechanics.speed.x = 0.0f;
//
//	if (!upButton && !downButton)
//		mechanics.speed.y = 0.0f;
//
//	if (leftButton)
//	{
//		direction = M_PI;
//		mechanics.speed.x = -1.0f;
//
//		if (fireButton)
//			mechanics.speed.x = -2.0f;
//	}
//
//	if (rightButton)
//	{
//		direction = 0.0f;
//		mechanics.speed.x = 1.0f;
//
//		if (fireButton)
//			mechanics.speed.x = 2.0f;
//	}
//
//	if (upButton)
//		mechanics.speed.y = 1.0f;
//
//	if (downButton)
//		mechanics.speed.y = -1.0f;
//
//	brain.top()->update();
}

void Mario::print() const
{
	Entity::print();
}

Mario::MarioIdle::MarioIdle(Mario* mario)
{
	this->mario = mario;
	name = "marioIdle";
}

Mario::MarioIdle::~MarioIdle()
{
}

void Mario::MarioIdle::enter()
{
	if (mario->brain.size() > 1)
	{
		mario->brain.pop();
		mario->brain.pop();
		mario->brain.push(mario->marioIdle);
	}


}

void Mario::MarioIdle::update()
{
	if (mario->mechanics.speed.x != 0.0f)
	{
		mario->brain.push(mario->marioWalk);
		exit();
	}
}

void Mario::MarioIdle::exit()
{
	mario->brain.top()->enter();
}

Mario::MarioWalk::MarioWalk(Mario* mario)
{
	this->mario = mario;
}

Mario::MarioWalk::~MarioWalk()
{
}

void Mario::MarioWalk::enter()
{
	mario->brain.pop();
	mario->brain.pop();
	mario->brain.push(mario->marioWalk);
	mario->sprite[0]->ptrAnimation = new Animation(1, 3, 1, 3.0f, Animation::LOOP_FORWARD);
}

void Mario::MarioWalk::update()
{
	if (mario->mechanics.speed.x == 0.0f)
	{
		mario->brain.push(mario->marioIdle);
		exit();
	}
}

void Mario::MarioWalk::exit()
{
	mario->brain.top()->enter();
}

Mario::MarioJump::MarioJump(Mario *mario)
{
	this->mario = mario;
}

Mario::MarioJump::~MarioJump()
{
}

void Mario::MarioJump::enter()
{
	mario->brain.pop();
	mario->brain.push(mario->marioJump);

}

void Mario::MarioJump::update()
{
	cout << "jump state" << endl;

	if (time > 0)
		time -= 0.01f;
	else
		time = 1.0f;

	//h(t) = v0 * t + 0.5 * g * t * t
}

void Mario::MarioJump::exit()
{
	cout << "exit jump state" << endl;
	mario->brain.top()->enter();
}

Mario::MarioShoot::MarioShoot(Mario *mario)
{
	this->mario = mario;
}

Mario::MarioShoot::~MarioShoot()
{
}

void Mario::MarioShoot::enter()
{

}


void Mario::MarioShoot::update()
{

}


void Mario::MarioShoot::exit()
{

}


Mario::MarioHit::MarioHit(Mario *mario)
{
	this->mario = mario;
}

Mario::MarioHit::~MarioHit()
{
}

void Mario::MarioHit::enter()
{

}

void Mario::MarioHit::update()
{

}

void Mario::MarioHit::exit()
{

}

Mario::MarioKO::MarioKO(Mario *)
{
	this->mario = mario;
}

Mario::MarioKO::~MarioKO()
{
}

void Mario::MarioKO::enter()
{
}

void Mario::MarioKO::update()
{
}

void Mario::MarioKO::exit()
{
}

