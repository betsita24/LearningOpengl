#include"Box.h"
std::vector<GLfloat>  Box::generateVertices(){
	std::vector<GLfloat> vertices{
	    //top face
		-0.5,0.5,0.5,	0,0, 
		0.5,0.5,0.5,	1,0,
		0.5,0.5,-0.5,	 1,1,
		-0.5,0.5,-0.5,	0,1,
		//bottom face
		-0.5,-0.5,-0.5,	0,0,
		0.5,-0.5,-0.5,	1,0,
		0.5,-0.5,0.5,	1,1,
		-0.5,-0.5,0.5,	0,1,
		//front face
		-0.5,-0.5,0.5,	0,0,
		0.5,-0.5,0.5,	1,0,
		0.5,0.5,0.5,	1,1,
		- 0.5,0.5,0.5, 0,1,
		//back face
		-0.5,-0.5,-0.5,	0,0,
		0.5,-0.5,-0.5,	1,0,
		0.5,0.5,-0.5,	1,1,
		- 0.5,0.5,-0.5,	0,1,
		
		//left face
		-0.5,-0.5,-0.5,	0,0,
		-0.5,-0.5,0.5,	1,0,
		-0.5,0.5,0.5, 1,1,
		-0.5,0.5,-0.5,	0,1,
		//right face
		0.5,-0.5,0.5,	0,0,
		0.5,-0.5,-0.5,	1,0,
		0.5,0.5,-0.5,	1,1,
		0.5,0.5,0.5,	0,1,
	
	};


	return vertices;
}
std::vector<GLuint> Box::generateIndices(){
	std::vector<GLuint> indices{
		0,1,2,
		0,2,3,
		
		4,5,6,
		4,6,7,

		8,9,10,
		8,10,11,
		
		12, 14, 13,
        12, 15, 14,
		
		16,17,18,
	    16,18,19,
		
		20,21,22,
		20,22,23
	};

	return indices;
}

Box::Box()
	:mesh(generateVertices(), generateIndices(), {V_Attrib::POS,V_Attrib::UV}) { }
void Box::Draw() {
	mesh.Draw();
}