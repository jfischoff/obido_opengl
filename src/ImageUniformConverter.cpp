#include "ImageUniformConverter.h"

bool ImageUniformConverter::convert(IUniform* uniform, string& message)
{
    //check if it is an int
      string uniformTypeName = uniform->getTypeName();
      if(uniformTypeName != "Int1")
      {
        message += "ImageUniformConverter::convert uniform is type " + uniformTypeName + 
                   " but should be type Int1";
        return false;
      }

      GLuint textureId = m_Image->getTextureId();

      ((Int1*)uniform)->setValue(textureId);

    return true;
}
