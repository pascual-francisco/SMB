#include "stdafx.h"

SuperMarioBros	*superMarioBros = nullptr;

int main(int argc, char *argv[])
{
    superMarioBros = new SuperMarioBros("Super Mario Bros", true, "Assets/Shaders/", 256, 224);
    return 0;
}

