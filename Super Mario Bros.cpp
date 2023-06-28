#include "SuperMarioBros.h"

SuperMarioBros::SuperMarioBros(string name, bool mode, string file, GLuint w, GLuint h) :Game(name, mode, file, w, h)
{
	actualScene = 0;
	initUniforms();
	initTextures();
	initBuffers();
	initSounds();
	initScenes();
   update();
}

SuperMarioBros::~SuperMarioBros()
{
	delete ptrTextureManager;
	delete ptrSoundManager;
}

void SuperMarioBros::initScenes()
{
   scenes.push_back(new World11(WORLD11, ptrRenderer->shaders[0]->programID));
   scenes.push_back(new World11(WORLD11, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD12, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD13, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD14, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD21, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD22, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD23, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD24, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD31, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD32, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD33, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD34, ptrRenderer->shaders[0]->programID));


}

void SuperMarioBros::initTextures()
{
	ptrTextureManager = new TextureManager();
	ptrTextureManager->initTexture(PALETTE_1, "Assets/Textures/palette_1_", 5, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_2, "Assets/Textures/palette_2_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_3, "Assets/Textures/palette_3_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_4, "Assets/Textures/palette_4_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_5, "Assets/Textures/palette_5_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_6, "Assets/Textures/palette_6_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_7, "Assets/Textures/palette_7_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_8, "Assets/Textures/palette_8_", 11, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_9, "Assets/Textures/palette_9_", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_10, "Assets/Textures/palette_10_", 1, GL_TEXTURE_2D_ARRAY);
}

void SuperMarioBros::initSounds()
{
	ptrSoundManager = new SoundManager();
	ptrSoundManager->initBGM(0, "Assets/BGM/01 - Super Mario Bros.mp3");
	ptrSoundManager->initBGM(1, "Assets/BGM/02 - Invincibility Star.mp3");
	ptrSoundManager->initBGM(2, "Assets/BGM/03 - Hurry - Super Mario Bros.mp3");
	ptrSoundManager->initBGM(3, "Assets/BGM/04 - Area Clear.mp3");
	ptrSoundManager->initBGM(4, "Assets/BGM/05 - Warp Pipe.mp3");
	ptrSoundManager->initBGM(5, "Assets/BGM/06 - Underground.mp3");
	ptrSoundManager->initBGM(6, "Assets/BGM/08 - Water World.mp3");
	ptrSoundManager->initBGM(7, "Assets/BGM/09 - Hurry - Water World.mp3");
	ptrSoundManager->initBGM(8, "Assets/BGM/11 - Hurry - Castle.mp3");
	ptrSoundManager->initBGM(9, "Assets/BGM/12 - World Clear.mp3");
	ptrSoundManager->initBGM(10, "Assets/BGM/13 - Ending.mp3");
	ptrSoundManager->initBGM(11, "Assets/BGM/13 - Ending.mp3");
	ptrSoundManager->initSFX(13, "Assets/SFX/Beep.wav");
	ptrSoundManager->initSFX(14, "Assets/SFX/Big Jump.wav");
	ptrSoundManager->initSFX(15, "Assets/SFX/Bowser Die.wav");
	ptrSoundManager->initSFX(16, "Assets/SFX/Break.wav");
	ptrSoundManager->initSFX(17, "Assets/SFX/Bump.wav");
	ptrSoundManager->initSFX(18, "Assets/SFX/Coin.wav");
	ptrSoundManager->initSFX(19, "Assets/SFX/Die.wav");
	ptrSoundManager->initSFX(20, "Assets/SFX/Enemy Fire.wav");
	ptrSoundManager->initSFX(21, "Assets/SFX/Flagpole.wav");
	ptrSoundManager->initSFX(22, "Assets/SFX/Game Over.wav");
	ptrSoundManager->initSFX(23, "Assets/SFX/Item.wav");
	ptrSoundManager->initSFX(24, "Assets/SFX/Jump.wav");
	ptrSoundManager->initSFX(25, "Assets/SFX/Kick.wav");
	ptrSoundManager->initSFX(26, "Assets/SFX/Powerup.wav");
	ptrSoundManager->initSFX(27, "Assets/SFX/Skid.wav");
	ptrSoundManager->initSFX(28, "Assets/SFX/Squish.wav");
	ptrSoundManager->initSFX(29, "Assets/SFX/Thwomp.wav");
	ptrSoundManager->initSFX(30, "Assets/SFX/Vine.wav");
   ptrSoundManager->initSFX(31, "Assets/SFX/Warp.wav");
}

void SuperMarioBros::initUniforms()
{
//   //Init Camera//
//   ptrCamera = new Camera(true, 0, 0.0f, ptrRenderer->viewPort.w, 0.0f, ptrRenderer->viewPort.h);
//   glViewport(0, 0, ptrRenderer->viewPort.w * ptrRenderer->zoomFactor, ptrRenderer->viewPort.h * ptrRenderer->zoomFactor);
//
//
//
//   //Init Samplers//
//	GLint maxTextureUnits = 0;
//	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureUnits);
//
//   int samplers[maxTextureUnits];
//	for (uint i = 0; i < maxTextureUnits; i++)
//      samplers[i] = i;
//
//   glUniform1iv(glGetUniformLocation(ptrRenderer->shaders[0]->programID, "fSamplers"), maxTextureUnits, samplers);
//	glUniform1i(glGetUniformLocation(ptrRenderer->shaders[0]->programID, "fTextures"), maxTextureUnits);
//   glUniformMatrix4fv(glGetUniformLocation(ptrRenderer->shaders[0]->programID, "mProjectionMatrix"), 1, GL_FALSE, &ptrCamera->mProjection[0][0]);
//	glUniformMatrix4fv(glGetUniformLocation(ptrRenderer->shaders[0]->programID, "mViewMatrix"), 1, GL_FALSE, &ptrCamera->mView[0][0]);


   mat4  projection;
   mat4  view;

	projection = mat4(1.0f);
	view = mat4(1.0f);

	//Init Samplers
	int samplers[32];
	for (uint i = 0; i < 32; i++)
		samplers[i] = i;

	glUniform1iv(glGetUniformLocation(ptrRenderer->shaders[0]->programID, "fSamplers"), 32, samplers);

	//Init Matrices to 1
	projection = mat4(1.0f);
	view = mat4(1.0f);

	//Init Projection
	projection = glm::ortho(0.0f, 1.0f * 256.0f, 0.0f, 1.0f * 240.0f, 1000.0f, -1000.0f);

	//Init Camera
	view = glm::lookAt(vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, -1.0f), vec3(0.0f, 1.0f, 0.0f));

	//Init Origin
	view = glm::translate(view, vec3(0.0f, 0.0f, 0.0f));

	glUniformMatrix4fv(glGetUniformLocation(ptrRenderer->shaders[0]->programID, "vProjection"), 1, GL_FALSE, &projection[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(ptrRenderer->shaders[0]->programID, "vView"), 1, GL_FALSE, &view[0][0]);


}

void SuperMarioBros::initBuffers()
{

}

void SuperMarioBros::update()
{
	while(active)
	{
		updateScene();
		updateUniforms();
		updateBuffers();
		updateTextures();
		updateSounds();
		checkEvents();
		ptrRenderer->update();

	}
}

void SuperMarioBros::updateScene()
{
	if (scenes[actualScene] != nullptr)
		scenes[actualScene]->update();



}

void SuperMarioBros::updateUniforms()
{

}

void SuperMarioBros::updateTextures()
{

}

void SuperMarioBros::updateSounds()
{

}

void SuperMarioBros::updateBuffers()
{

}

void SuperMarioBros::checkEvents()
{
	while (SDL_PollEvent(&gameEvents))
	{
		switch (gameEvents.key.type)
		{
		case SDL_KEYDOWN:
		{
			switch (gameEvents.key.keysym.sym)
			{
			case SDLK_a:
				Game::leftButton = true;
					scenes[actualScene]->ptrObjectManager->entitiesArray[0];

				break;

			case SDLK_d:
				Game::rightButton = true;

				break;

			case SDLK_w:
				Game::upButton = true;

				break;

			case SDLK_s:
				Game::downButton = true;


				break;

			case SDLK_x:

				break;

			case SDLK_c:


				break;

			case SDLK_y:
				break;

			case SDLK_k:
				Game::bButton = true;

				break;

			case SDLK_l:
				Game::aButton = true;


				break;

			case SDLK_LEFT:

				break;

			case SDLK_RIGHT:

				break;


			case SDLK_UP:

				break;

			case SDLK_DOWN:

				break;

			case SDLK_RETURN:

				break;

			case SDLK_ESCAPE:
				active = false;
				break;
			}
		}
		break;

		case SDL_KEYUP:
		{
			switch (gameEvents.key.keysym.sym)
			{
			case SDLK_a:
				Game::leftButton = false;

				break;

			case SDLK_d:
				Game::rightButton = false;

				break;

			case SDLK_w:
				Game::upButton = false;

				break;

			case SDLK_s:
				Game::downButton = false;

				break;

			case SDLK_k:
				Game::bButton = false;

				break;

			case SDLK_l:
				Game::aButton = false;

				break;

			case SDLK_LEFT:
				scenes[actualScene]->ptrBackground->speedX = 1.0f;
				scenes[actualScene]->ptrBackground->printVertexArray();
				break;

			case SDLK_RIGHT:
				scenes[actualScene]->ptrBackground->speedX = -1.0f;
				break;


			case SDLK_UP:
				scenes[actualScene]->ptrBackground->speedY = -1.0f;
				break;

			case SDLK_DOWN:
				scenes[actualScene]->ptrBackground->speedY = 1.0f;

			case SDLK_z:

				break;

			case SDLK_x:

				break;

			case SDLK_c:

				break;

			case SDLK_ESCAPE:
				active = false;
				break;
			}
		}
		break;

		default:
			break;
		}
	}
}
