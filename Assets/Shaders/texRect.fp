#version 450

uniform int fTextures;
uniform sampler2DArray fSamplers[32];

in vec4 vColor;
in vec4 vTexture;

out vec4 vFragColor;

void main()
{
   vFragColor = vec4(texture(fSamplers[int(vTexture.q)], vTexture.stp).rgb, vColor.a);
  // vFragColor = vec4(1,0,0,1);
}


