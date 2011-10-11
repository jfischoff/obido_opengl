#include "Program.h"
#include "VertexShader.h"
#include "FragmentShader.h"
//__HEADERS__
#include <iostream>
#include <assert.h>
//__HEADERS__
void* Program::Constructor()
{
  return new Program();
}
Program::Program()
{
m_VertexShader = NULL;
m_FragmentShader = NULL;
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

Program::Program(const Program& other)
{
  copy(other);
}

Program& Program::operator=(const Program& other)
{
  copy(other);
  return *this;
}

void Program::copy(const Program& other)
{
  m_VertexShader = other.m_VertexShader;
  m_FragmentShader = other.m_FragmentShader;
}

Program::~Program()
{
}

Program::Program(VertexShader* vertexShader, FragmentShader* fragmentShader)
{
m_VertexShader = vertexShader;
m_FragmentShader = fragmentShader;
}
VertexShader* Program::getVertexShader()
{
  return m_VertexShader;
}

const VertexShader* Program::getVertexShader() const
{
  return m_VertexShader;
}

void Program::setVertexShader(VertexShader* value)
{
  m_VertexShader = value;
}
FragmentShader* Program::getFragmentShader()
{
  return m_FragmentShader;
}

const FragmentShader* Program::getFragmentShader() const
{
  return m_FragmentShader;
}

void Program::setFragmentShader(FragmentShader* value)
{
  m_FragmentShader = value;
}
void Program::merge(const Program& other)
{
    mergeVertexShader(other.m_VertexShader);
    mergeFragmentShader(other.m_FragmentShader);
}

void Program::clear()
{
    clearVertexShader();
    clearFragmentShader();
}
void Program::mergeVertexShader(VertexShader* const otherVertexShader)
{
  m_VertexShader->merge(*otherVertexShader);
}
void Program::mergeFragmentShader(FragmentShader* const otherFragmentShader)
{
  m_FragmentShader->merge(*otherFragmentShader);
}
void Program::clearVertexShader()
{
  m_VertexShader->clear();
}
void Program::clearFragmentShader()
{
  m_FragmentShader->clear();
}
//__CUSTOM_METHODS__
void Program::deepCopy(const Program* copyable)
{
  Program* otherProgram3 = (Program*)copyable;

  if(m_VertexShader == NULL)
    {
      m_VertexShader = new VertexShader();
    }
  m_VertexShader->deepCopy(otherProgram3->m_VertexShader);

  if(m_FragmentShader == NULL)
    {
      m_FragmentShader = new FragmentShader();
    }

  m_FragmentShader->deepCopy(otherProgram3->m_FragmentShader);

  if(m_UniformsCount != otherMaterial->m_UniformsCount)
    {
      if(m_UniformsCount != 0)
	{
	  assert(m_Uniforms != NULL);
	  delete[] m_Uniforms;
	}
      m_UniformsCount = otherMaterial->m_UniformsCount;
      m_Uniforms = new IUniform*[otherMaterial->m_UniformsCount];
    }

  for(unsigned int index = 0; index < m_UniformsCount; index++)
    {
      IUniform* currentOtherIUniform = otherMaterial->m_Uniforms[index];

	  m_Uniforms[index] = currentOtherIUniform->clone();
    }
}

IUniform* Program::getUniformsElementByName(const char* name)
{
    for(unsigned int index = 0; index < m_UniformsCount; index++)
    {
      IUniform* currentIUniform = m_Uniforms[index];

      const char* currentName = currentIUniform->getName();

      if(strncmp(currentName, name, 255) == 0)
	{
	  return currentIUniform;
	}
    }
    
    assert(0);
    return NULL;
}

void Program::destroy()
{

}

bool Program::create(string& message)
{
  m_ProgramId = glCreateProgram();
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool Program::predraw(string& message)
{
  //I need to make the program current
  //I think that is all the program has to do
  glUseProgram(m_ProgramId);
  CHECK_ERROR_AND_RETURN(message);

  for(unsigned int index = 0; index < getUniformsCount(); index++)
    {
      IUniform* uniform = getUniformsElement(index);
      
      if(uniform->predraw(message) == false) return false;
    }
	
  return true;
}

bool Program::attachVertexShader(string& message)
{
  glAttachShader(m_ProgramId, m_VertexShader->getShaderId());
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool Program::detachVertexShader(string& message)
{
  glDetachShader(m_ProgramId, m_VertexShader->getShaderId());
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool Program::attachFragmentShader(string& message)
{
  unsigned int fragId = m_FragmentShader->getShaderId();
  glAttachShader(m_ProgramId, m_FragmentShader->getShaderId());
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool Program::detachFragmentShader(string& message)
{
  glDetachShader(m_ProgramId, m_FragmentShader->getShaderId());
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool Program::link(string& message)
{
  //
  glLinkProgram(m_ProgramId);
  CHECK_ERROR_AND_RETURN(message);
	
  //I need to check the info log
  GLint status;
  glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &status);
  if(status == GL_FALSE)
    {
      GLchar* infoLog = new GLchar[100000];
      GLsizei length;
      glGetShaderInfoLog(m_ProgramId, 100000, &length, infoLog);
      message += infoLog;
      m_IsLinked = false;
      return false;
    }
	
  m_IsLinked = true;
  return true;
}

bool Program::deleteProgram(string& message)
{
  glDeleteProgram(m_ProgramId);
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool Program::isLinked() const
{
  return m_IsLinked;	
}

unsigned int Program::getProgramId() const
{
  return m_ProgramId;
}

bool Program::getAttributeIndex(const char* attributeName, unsigned int& attributeIndex, 
				 string& message) const
{
  GLint aIndex = glGetAttribLocation(getProgramId(), attributeName);
  if(aIndex == -1)
    {
      string sAttName = attributeName;
      message += sAttName + " attribute not found";
      cout << message;
      assert(!"attribute not found");
    }
  attributeIndex = aIndex;
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool Program::setup(string& message)
{

  if(m_VertexShader->setup(message) == false) {assert(0); return false;}
  if(m_FragmentShader->setup(message) == false) {assert(0); return false;}

  if(create(message) == false) {assert(0); return false;}
  if(attachVertexShader(message) == false) {assert(0); return false;}
  if(attachFragmentShader(message) == false) {assert(0); return false;}
  if(link(message) == false) {assert(0); return false;}

  for(unsigned int index = 0; index < getUniformsCount(); index++)
  {
    IUniform* uniform = getUniformsElement(index);
    if(uniform->setup(message) == false) {return false;}
  }

  return true;
}

void* Program::Create()
{
  Program* returnValue = new Program();
  VertexShader* vShader =(VertexShader*)VertexShader::Create();
  returnValue->setVertexShader(vShader);

  FragmentShader* fShader = (FragmentShader*)FragmentShader::Create();
  returnValue->setFragmentShader(fShader);

  return returnValue;
}
//__CUSTOM_METHODS__
