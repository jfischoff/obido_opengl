#ifndef OPENGLUTILS_H
#define OPENGLUTILS_H

//#define GL_GLEXT_PROTOTYPES

#include <GL/glew.h>


#include <GL/gl.h>
#include <GL/freeglut.h>
//#include <GL/glext.h>
//#include <GL/glxext.h>




#include <string>
using namespace std;

#define CHECK_ERROR_AND_RETURN(message) 	if(OpenGLUtils::checkIfError(message) == false) return false;

class OpenGLUtils
{
public:
	static bool checkIfError(string& message);
private:
	
};

#endif //OPENGLUTILS_H
