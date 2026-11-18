#pragma once
#include"GL/glew.h"
#include"GLFW/glfw3.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
	int ID;
	Shader(const char* vertex_path, const char* fragment_path);

	void use();

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
};