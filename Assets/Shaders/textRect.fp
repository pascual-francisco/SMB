#version 440

uniform in sampler2DArray fSamplers;
in vec4 vColor;
in vec4 vTexture;

out vec4 vFragColor;

void main()
{
   // vFragColor = vec4( texture(fSamplers, vTexture.stp).rbg, vColor.a);
   vFragColor =  vec4(1,0,1, 1);
}


