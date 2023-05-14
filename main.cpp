#include "stdafx.h"

SuperMarioBros	*superMarioBros = nullptr;

int main(int argc, char *argv[])
{
    superMarioBros = new SuperMarioBros(true, "Assets/Shaders/", 0, 0, 256, 224);
    return 0;
}

