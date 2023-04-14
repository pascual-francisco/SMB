#pragma once
#include "stdafx.h"

#ifndef WORLD11_H
#define WORLD11_H

class World11 : public Scene
{
public:
	World11(GLuint id, bool act, SDL_FRect viewport, GLuint program);
	~World11();

	void	initObjects();
	void	initBackground();
	void	initForeground();

	void	updateObjects();
	void	updateBackground();
	void	updateForeground();
};
#endif

