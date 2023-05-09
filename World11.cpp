#include "stdafx.h"

World11::World11(GLuint id, GLuint pro):Scene(id, pro)
{
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
	ptrObjects->initDataArray();




}

void World11::initBackground()
{
	ptrBackground = new TileMapManager(1 * 14 * 16, 14 * 16, WORLD11MAPDATA, viewPort.w, viewPort.h, 16, 16, 1, 1, programID, GL_TRIANGLES);
	//ptrBackground->loadFirstPage();
	ptrBackground->loadSecondPage();
	//ptrBackground->loadThirdPage();
	//ptrBackground->loadFourthPage();

}

void World11::initForeground()
{

}

void World11::updateObjects()
{


}

void World11::updateBackground()
{

}

void World11::updateForeground()
{

}




