#include "World11.h"

World11::World11(GLuint id, GLuint pro):Scene(id,pro,true)
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
	ptrBackground = new TileMapManager(1 * 14 * 16, 14 * 16, WORLD11MAPDATA, 256, 224, 16, 16, 1, 1, programID, GL_TRIANGLES);
	ptrBackground->loadFirstPage(0);
   ptrBackground->loadSecondPage(0);
   ptrBackground->loadThirdPage(0);
   ptrBackground->loadFourthPage(0);



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




