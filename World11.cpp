#include "stdafx.h"

World11::World11(GLuint id, GLuint pro):Scene(id,pro,true,0,0,256,224,3)
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
   //ptrObjects->printDataArray();

}

void World11::initBackground()
{
	ptrBackground = new TileMapManager(1 * 14 * 16, 14 * 16, WORLD11MAPDATA, viewPort.w, viewPort.h, 16, 16, 1, 1, programID, GL_TRIANGLES);
	ptrBackground->loadFirstPage(0);
   ptrBackground->loadSecondPage(0);
   ptrBackground->loadThirdPage(0);
   ptrBackground->loadFourthPage(0);
  // ptrBackground->printDataArray();
}

void World11::initForeground()
{

}

void World11::updateObjects()
{


}

void World11::updateBackground()
{
   if(ptrBackground->offsetX < 256)
   {
      ptrBackground->offsetX += 0.001;
      ptrBackground->offsetY += 0.0001;
   }
   else
   {
      ptrBackground->offsetX = 0;
      ptrBackground->offsetY = 0;
   }



}

void World11::updateForeground()
{

}




