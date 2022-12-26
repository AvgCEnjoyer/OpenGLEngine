#include "Shader.h"


unsigned int compileShader(unsigned int type, const std::string& source) {

	unsigned int id = glCreateShader(type);
	const char* src = source.c_str(); //�quivalent : &source[0]
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	//Error handling
	int res;
	glGetShaderiv(id, GL_COMPILE_STATUS, &res);
	if (res == GL_FALSE) {
		int len;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
		char* msg = (char*)alloca(len * sizeof(char)); //Umgehung, damit msg auf dem Stack liegt (Repliziert char msg[len]). Keyword new f�r heap
		glGetShaderInfoLog(id, len, &len, msg);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << std::endl;
		std::cout << msg << std::endl;
		glDeleteShader(id);

		return 0;
	}
	//--------------

	return id;
}


unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader) {

	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDetachShader(program, vs);
	glDetachShader(program, fs);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

std::string getFileShader(std::string filePath) {

	return loadFile(filePath);
}