#version 330 core
in vec2 uv;
out vec4 FragColor;

void main(){

	vec2 sq=floor(uv*8.0);
    
    if (mod((sq.x + sq.y) , 2 )== 0)
        FragColor = vec4(0.0, 0.0, 1.0, 1.0);
    else
        FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}