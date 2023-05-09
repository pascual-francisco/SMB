#include "stdafx.h"

SuperMarioBros	*superMarioBros = nullptr;

int main(int argc, char *argv[])
{

    superMarioBros = new SuperMarioBros(true, "Assets/Shaders/",3, 0, 0, 256, 240);
    return 0;
}

