#include "Float1Uniform.h"

void* Float1Uniform::Constructor()
{
  return new Float1Uniform();
}

bool Float1Uniform::predraw(string& message)
{
  glUniform1f(m_UniformLocation, m_Value1);
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

void Float1Uniform::deepCopy(const IUniform* other)
{
    m_Value1 = ((Float1Uniform*)other)->m_Value1;
}

void Float1Uniform::destroy()
{

}

IUniform *Float1Uniform::clone()
{
    Float1Uniform* result = new Float1Uniform();
    result->deepCopy(this);
    return result;
}
