#version 330 core
layout (location=0) in vec3 pos;
layout (location=2) in vec2 in_uv;

out vec2 uv;
void main(){
gl_Position=vec4(pos*2,1.0);
uv=in_uv;
}