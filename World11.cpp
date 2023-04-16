#pragma once
#include "stdafx.h"

World11::World11(GLuint id, GLuint pro):Scene()
{
	programID = pro;
	initObjects();
	initBackground();
	initForeground();
}

World11::~World11()
{

}

void World11::initObjects()
{
	ptrObjects = new ObjectManager(programID, GL_TRIANGLES);

	ptrObjects->entitiesArray.push_back(new Mario(3 * 16 , 14 * 16));
	ptrObjects->entitiesArray.push_back(new Goomba(5 * 16, 3 * 16));
	ptrObjects->entitiesArray.push_back(new Troopa(10 * 16, 3 * 16));
	ptrObjects->entitiesArray.push_back( new Piranha(8 * 16, 3 * 16));
	ptrObjects->initDataArray();
}

void World11::initBackground()
{
	ptrBackground = new TileMapManager(5 * 240, 240, WORLD11_MAP,  viewPort.w, viewPort.h, 16, 16, programID, GL_TRIANGLES);
	ptrBackground->loadPage(0, 0, 0, 0);
	ptrBackground->loadPage(16, 0, 1, 1);
}

void World11::initForeground()
{

}

void World11::updateObjects()
{

	for (int i = 0; i < 4; i++)
	{
		ptrObjects->entitiesArray[i]->mechanics.position.x += ptrBackground->speedX;
		ptrObjects->entitiesArray[i]->mechanics.position.y += ptrBackground->speedY;
		*ptrObjects->entitiesArray[0]->sprite[0] * *ptrObjects->entitiesArray[1]->sprite[0];
	}

}

void World11::updateBackground()
{



}

void World11::updateForeground()
{

}




