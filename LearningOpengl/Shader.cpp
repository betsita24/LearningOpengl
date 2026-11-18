#include"Shader.h"



 std::string shaderFileReader(const char* path) {
    // 1. retrieve the source code from filePath
    std::string shaderCode;
    std::ifstream shaderFile;
    // ensure ifstream objects can throw exceptions:
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        shaderFile.open(path);
        std::stringstream shaderStream;
        // read file's buffer contents into streams
        shaderStream << shaderFile.rdbuf();
        // close file handlers
        shaderFile.close();
        // convert stream into string
        shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    return shaderCode;
}

 bool CheckErrors(GLuint object_id) {
     int success;
     char infolog[512];
     if (glIsShader(object_id))
     {
         glGetShaderiv(object_id, GL_COMPILE_STATUS, &success);
         if (!success) {
             glGetShaderInfoLog(object_id, 512, NULL, infolog);
             std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                 << infolog << std::endl;
             return true;
         }

     }
     else {
         glGetProgramiv(object_id, GL_LINK_STATUS, &success);
         if (!success) {
             glGetProgramInfoLog(object_id, 512, NULL, infolog);
             std::cout
                 << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                 << infolog << std::endl;
             return true;
         }
     }
     return false;
 }

Shader::Shader(const char* vertex_path, const char* fragment_path){
    std::string vertex_code=shaderFileReader(vertex_path);
    std::string fragment_code = shaderFileReader(fragment_path);
    const char* v_shade_code=vertex_code.c_str();
    const char* f_shader_code=fragment_code.c_str();

    GLuint vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &v_shade_code, NULL);
    glCompileShader(vertex_shader);
    if (CheckErrors(vertex_shader)) {
        glfwTerminate();
    }

    GLuint fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &f_shader_code, NULL);
    glCompileShader(fragment_shader);
    if (CheckErrors(fragment_shader)) {
        glfwTerminate();
    }


    ID=glCreateProgram();
    glAttachShader(ID, vertex_shader);
    glAttachShader(ID, fragment_shader);
    glLinkProgram(ID);
    if (CheckErrors(ID)) {
        glfwTerminate();
    }

//Clearing up
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}
void Shader::use() {
    glUseProgram(ID);
}
void Shader::setBool(const std::string& name, bool value ) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::setFloat(const std::string& name, float value) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()),value);
}
void Shader::setInt(const std::string& name, int value) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()),value);
}