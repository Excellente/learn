#version 330 core

in vec2 texcoord;
out vec4 color;
 
uniform sampler2D tex;
uniform vec4 c;
 
 
void main()
{
  color = vec4(1, 1, 1, texture2D(tex, texcoord).a) * c;
}