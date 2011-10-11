#ifndef GLENUMS_H
#define GLENUMS_H

#include "OpenGLUtils.h"
#include "Primitive.h"


string convertGLenumToString(GLenum glEnum);
GLenum convertEnumStringToGLenum(string glEnumString);
uint getGLenumCount();

GLenum convertPrimitiveETypeToGLenum(PrimitiveEType primitive);
PrimitiveEType convertGLenumToPrimitiveEType(GLenum primitive);

#endif //GLENUMS_H
