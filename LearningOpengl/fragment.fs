#version 330
out vec4 FragColor;

uniform float color;
void main(){
FragColor=vec4(0.0f,color,0.0f,1.0f);
}