#include "GLenum.h"
#include <assert.h>

string convertGLenumToString(GLenum glEnum)
{
  switch(glEnum)
    {
    case GL_FALSE:
      return "GL_FALSE";
    case GL_TRUE:
      return "GL_TRUE";
    case GL_BYTE:
      return "GL_BYTE";
    case GL_UNSIGNED_BYTE:
      return "GL_UNSIGNED_BYTE";
    case GL_SHORT:
      return "GL_SHORT";
    case GL_UNSIGNED_SHORT:
      return "GL_UNSIGNED_SHORT";
    case GL_INT:
      return "GL_INT";
    case GL_UNSIGNED_INT:
      return "GL_UNSIGNED_INT";
    case GL_FLOAT:
      return "GL_FLOAT";
    case GL_DOUBLE:
      return "GL_DOUBLE";
    case GL_TRIANGLES:
      return "GL_TRIANGLES";
    case GL_QUADS:
      return "GL_QUADS";
    case GL_VERTEX_SHADER:
      return "GL_VERTEX_SHADER";
    case GL_FRAGMENT_SHADER:
      return "GL_FRAGMENT_SHADER";
    default:
      assert(0);
      return "";
    }


}

GLenum convertEnumStringToGLenum(string glEnumString)
{

  if(glEnumString == "GL_BYTE")
    {
      return GL_BYTE;
    }
  else if(glEnumString == "GL_UNSIGNED_BYTE")
    {
      return GL_UNSIGNED_BYTE;
    }
  else if(glEnumString == "GL_SHORT")
    {
      return GL_SHORT;
    }
  else if(glEnumString == "GL_UNSIGNED_SHORT")
    {
      return GL_UNSIGNED_SHORT;
    }
  else if(glEnumString == "GL_INT")
    {
      return GL_INT;
    }
  else if(glEnumString == "GL_UNSIGNED_INT")
    {
      return GL_UNSIGNED_INT;
    }
  else if(glEnumString == "GL_FLOAT")
    {
      return GL_FLOAT;
    }
  else if(glEnumString == "GL_DOUBLE")
    {
      return GL_DOUBLE;
    }
  else if(glEnumString == "GL_TRIANGLES")
    {
      return GL_TRIANGLES;
    }  
  else if(glEnumString == "GL_QUADS")
    {
      return GL_QUADS;
    }
  else if(glEnumString == "GL_VERTEX_SHADER")
    {
      return GL_VERTEX_SHADER;
    }
  else if(glEnumString == "GL_FRAGMENT_SHADER")
    {
      return GL_FRAGMENT_SHADER;
    }
  else
    {
      assert(0);
      return (GLenum)-1;

    }
}

uint getGLenumCount()
{
  return 1;
}


GLenum convertPrimitiveETypeToGLenum(PrimitiveEType primitive)
{
    switch(primitive)
    {    
    case CHAR:
    case BYTE:
      return GL_BYTE;
    case BOOL:
    case UBYTE:
    case UCHAR:
      return GL_UNSIGNED_BYTE;
    case USHORT:
      return GL_UNSIGNED_SHORT;
    case SHORT:
      return GL_SHORT;
    case INT:
      return GL_INT;
    case UINT:
      return GL_UNSIGNED_INT;
    case FLOAT:
      return GL_FLOAT;
    case DOUBLE:
      return GL_DOUBLE;
    default:
      assert(0);
      return -1u;
    }
}

PrimitiveEType convertGLenumToPrimitiveEType(GLenum glEnum)
{
  switch(glEnum)
    {
    case GL_UNSIGNED_BYTE:
      return UCHAR;
    case GL_BYTE:
      return CHAR;
    case GL_UNSIGNED_SHORT:
      return USHORT;
    case GL_SHORT:
      return SHORT;
    case GL_INT:
      return INT;
    case GL_UNSIGNED_INT:
      return UINT;
    case GL_FLOAT:
      return FLOAT;
    case GL_DOUBLE:
      return DOUBLE;
    default:
      assert(0);
      return INVALID_ETYPE;
    }
}
