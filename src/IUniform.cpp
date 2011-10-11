#include "IUniform.h"
#include "OpenGLUtils.h"
#include "Program.h"
#include <assert.h>

bool IUniform::setup(string& message)
{
    unsigned int programId = m_Program->getProgramId();
    return requestUniformLocation(programId, message);
}

bool IUniform::requestUniformLocation(unsigned int programId, string& message)
{
  m_UniformLocation = glGetUniformLocation(programId, m_Name.c_str());
  assert(m_UniformLocation !=  -1u);
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

const char* IUniform::getName() const
{
  return m_Name.c_str();
}

void IUniform::setName(string name)
{
  m_Name = name;
}

const char* IUniform::getTypeName()
{
  return m_Type;
}

void IUniform::deepCopy(const IUniform* other)
{
  m_Name = other->m_Name;
  m_Type = other->m_Type;
}






