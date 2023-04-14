#pragma once
#include "stdafx.h"

#ifndef SUPERMARIOBROS_H
#define SUPERMARIOBROS_H

class SuperMarioBros: public Game
{
	public:		
	SuperMarioBros(bool mode, string file, GLuint x, GLuint y, GLuint w, GLuint h);
	~SuperMarioBros();

	void initScenes();
	void initTextures();
	void initSounds();
	void initUniforms();
	void initBuffers();

	void updateScene();
	void updateUniforms();
	void updateTextures();
	void updateSounds();
	void updateBuffers();	
	void update();
	void checkEvents();
};
#endif // !SUPERMARIOBROS_H

