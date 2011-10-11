

#include "OpenGLUtils.h"
#include <assert.h>

bool OpenGLUtils::checkIfError(string& message)
{
	bool returnValue = true;
	GLenum err = glGetError();
	switch (err) {
		case GL_OUT_OF_MEMORY:
		  assert(0);
			returnValue = false;
			message = "GL_OUT_OF_MEMORY";
			break;
		case GL_INVALID_ENUM:
		  assert(0);
			returnValue = false;
			message = "GL_INVALID_ENUM";
			break;
		case GL_INVALID_VALUE:
		  assert(0);
			returnValue = false;
			message = "GL_INVALID_VALUE";
			break;
		case GL_INVALID_OPERATION:
		  assert(0);
			returnValue = false;
			message = "GL_INVALID_OPERATION";
			break;
			
		default:
			break;
	}
	assert(err == GL_NO_ERROR);
	return returnValue;
}
