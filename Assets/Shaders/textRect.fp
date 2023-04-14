#version 410

//fSamplers

uniform sampler2DArray fSamplers;
in vec4 vColor;
in vec4 vTexture;

out vec4 vFragColor;

void main()
{
    //vFragColor = texture(fSamplers, vTexture.stp) * vColor;
    vFragColor = (1.0,0.0,0.0,1.0);
}


