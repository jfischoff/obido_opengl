#include "BaseShader.h"
//__HEADERS__
#include <memory.h>
#include <assert.h>
//__HEADERS__
void* BaseShader::Constructor()
{
  return new BaseShader();
}
BaseShader::BaseShader()
{
m_SerializableSources = NULL;
m_SerializableSourcesCount = 0;
m_SerializableUniformTypes = NULL;
m_SerializableUniformTypesCount = 0;
//__CUSTOM_INIT__
  m_Name = NULL;
  m_Sources = NULL;
  m_SourcesCount = 0;
  m_UniformTypes = NULL;
  m_UniformTypeCount = 0;
  m_ShaderType = 0;
//__CUSTOM_INIT__

}

BaseShader::BaseShader(const BaseShader& other)
{
  copy(other);
}

BaseShader& BaseShader::operator=(const BaseShader& other)
{
  copy(other);
  return *this;
}

void BaseShader::copy(const BaseShader& other)
{
  m_SerializedName = other.m_SerializedName;
  m_SerializableSources = other.m_SerializableSources;
  m_ShaderType = other.m_ShaderType;
  m_SerializableUniformTypes = other.m_SerializableUniformTypes;
}

BaseShader::~BaseShader()
{
}

BaseShader::BaseShader(string serializedName, string* serializableSources, unsigned int serializableSourcesCount, GLenum shaderType, string* serializableUniformTypes, unsigned int serializableUniformTypesCount)
{
m_SerializedName = serializedName;
m_SerializableSources = serializableSources;
m_ShaderType = shaderType;
m_SerializableUniformTypes = serializableUniformTypes;
}
string BaseShader::getSerializedName()
{
  return m_SerializedName;
}

const string BaseShader::getSerializedName() const
{
  return m_SerializedName;
}

void BaseShader::setSerializedName(string value)
{
  m_SerializedName = value;
}
string* BaseShader::getSerializableSources()
{
  return m_SerializableSources;
}

string const * BaseShader::getSerializableSources() const
{
  return m_SerializableSources;
}

const string BaseShader::getSerializableSourcesElement(unsigned int index) const
{
return m_SerializableSources[index];
}

string BaseShader::getSerializableSourcesElement(unsigned int index)
{
return m_SerializableSources[index];
}

unsigned int BaseShader::getSerializableSourcesCount() const
{
  return m_SerializableSourcesCount;
}
void BaseShader::setSerializableSources(string* array)
{
  m_SerializableSources = array;
}

void BaseShader::setSerializableSourcesElement(unsigned int index, string element)
{
  m_SerializableSources[index] = element;
}

void BaseShader::setSerializableSourcesCount(unsigned int count)
{
  m_SerializableSourcesCount = count;
}

GLenum BaseShader::getShaderType()
{
  return m_ShaderType;
}

const GLenum BaseShader::getShaderType() const
{
  return m_ShaderType;
}

void BaseShader::setShaderType(GLenum value)
{
  m_ShaderType = value;
}
string* BaseShader::getSerializableUniformTypes()
{
  return m_SerializableUniformTypes;
}

string const * BaseShader::getSerializableUniformTypes() const
{
  return m_SerializableUniformTypes;
}

const string BaseShader::getSerializableUniformTypesElement(unsigned int index) const
{
return m_SerializableUniformTypes[index];
}

string BaseShader::getSerializableUniformTypesElement(unsigned int index)
{
return m_SerializableUniformTypes[index];
}

unsigned int BaseShader::getSerializableUniformTypesCount() const
{
  return m_SerializableUniformTypesCount;
}
void BaseShader::setSerializableUniformTypes(string* array)
{
  m_SerializableUniformTypes = array;
}

void BaseShader::setSerializableUniformTypesElement(unsigned int index, string element)
{
  m_SerializableUniformTypes[index] = element;
}

void BaseShader::setSerializableUniformTypesCount(unsigned int count)
{
  m_SerializableUniformTypesCount = count;
}

void BaseShader::merge(const BaseShader& other)
{
    mergeSerializedName(other.m_SerializedName);
    mergeSerializableSources(other.m_SerializableSources);
    mergeShaderType(other.m_ShaderType);
    mergeSerializableUniformTypes(other.m_SerializableUniformTypes);
}

void BaseShader::clear()
{
    clearSerializedName();
    clearSerializableSources();
    clearShaderType();
    clearSerializableUniformTypes();
}
void BaseShader::mergeSerializedName(const string& otherSerializedName)
{
}
void BaseShader::mergeSerializableSources(string* const  otherSerializableSources)
{
}
void BaseShader::mergeShaderType(const GLenum& otherShaderType)
{
}
void BaseShader::mergeSerializableUniformTypes(string* const  otherSerializableUniformTypes)
{
}
void BaseShader::clearSerializedName()
{
}
void BaseShader::clearSerializableSources()
{
}
void BaseShader::clearShaderType()
{
}
void BaseShader::clearSerializableUniformTypes()
{
}
//__CUSTOM_METHODS__
void BaseShader::cache()
{
  m_Name = m_SerializedName.c_str();

  m_SourcesCount = m_SerializableSourcesCount;
  m_Sources = new const char*[m_SourcesCount];
  for(uint index = 0; index < m_SerializableSourcesCount; index++)
    {
      m_Sources[index] = m_SerializableSources[index].c_str();
    }

  m_UniformTypeCount = m_SerializableUniformTypesCount;
  m_UniformTypes = new const char*[m_UniformTypeCount];
  for(uint index = 0; index < m_UniformTypeCount; index++)
    {
      m_UniformTypes[index] = m_SerializableUniformTypes[index].c_str();
    }
}

void BaseShader::uncache()
{

}

bool BaseShader::createShader(string& message)
{
  void* pF = (void*)glCreateShader;
  assert(pF != NULL);
  //GLenum temp0 = GL_VERTEX_SHADER;
  //GLenum temp1 = GL_FRAGMENT_SHADER;
  assert(m_ShaderType == GL_VERTEX_SHADER || 
	 m_ShaderType == GL_FRAGMENT_SHADER); 
  m_ShaderId = glCreateShader(m_ShaderType);
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool BaseShader::compile(string& message)
{
  assert(glCompileShader);
  glCompileShader(m_ShaderId);
  CHECK_ERROR_AND_RETURN(message);
	
  //test for to see if the shader compiled correctly
  GLint compileStatus;
  glGetShaderiv(m_ShaderId, GL_COMPILE_STATUS, &compileStatus);
  if(compileStatus != GL_TRUE)
    {
      //failed to compile query the info log
      GLchar* infoLog = new GLchar[100000];
      GLsizei length;
      glGetShaderInfoLog(m_ShaderId, 100000, &length, infoLog);
		
      message += infoLog;
      m_IsCompiled = false;
      return false;
    }
	
  m_IsCompiled = true;
	
  return true;
}

bool BaseShader::loadShader(string& message)
{
  glShaderSource(m_ShaderId, m_SourcesCount, m_Sources, NULL);
  message += "Failed in loadShader ";
  message +=  m_Name;
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool BaseShader::deleteShader(string& message)
{
  glDeleteShader(m_ShaderId);
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

bool BaseShader::isCompiled() const
{
  return m_IsCompiled;
}

void BaseShader::getSources(const char*** sources, int& count) const
{
  *sources = m_Sources;
  count = m_SourcesCount;
}

void BaseShader::setSources(const char** sources, int count)
{
  m_Sources = sources;
  m_SourcesCount = count;
}


const char* BaseShader::getUniformType(uint index) const
{
  return m_UniformTypes[index];
}

void BaseShader::setUniformType(uint index, const char* uniformType)
{
  m_UniformTypes[index] = uniformType;
}

uint BaseShader::getUniformCount() const
{
  return m_UniformTypeCount;
}

bool BaseShader::setup(string& message)
{
  if(createShader(message) == false) return false;
  if(loadShader(message) == false) return false;
  if(compile(message) == false) return false;
  return true;
}

void BaseShader::deepCopy(const BaseShader* other)
{
  BaseShader* otherBaseShader2 = (BaseShader*)other;

  m_Name = otherBaseShader2->m_Name;
  m_IsCompiled = otherBaseShader2->m_IsCompiled;

  if(m_SourcesCount != otherBaseShader2->m_SourcesCount)
    {
      if(m_SourcesCount != 0)
	{
	  assert(m_Sources != NULL);
	  delete[] m_Sources;
	}
      m_SourcesCount = otherBaseShader2->m_SourcesCount;
      m_Sources = new const char*[m_SourcesCount];
    }

  for(uint index = 0; index < m_SourcesCount; index++)
    {
      m_Sources[index] = otherBaseShader2->m_Sources[index];
    }
  
  m_ShaderId = otherBaseShader2->m_ShaderId;
  m_ShaderType = otherBaseShader2->m_ShaderType;	

  if(m_UniformTypeCount != otherBaseShader2->m_UniformTypeCount)
    {
      if(m_UniformTypeCount != 0)
	{
	  assert(m_UniformTypes != NULL);
	  delete[] m_UniformTypes;
	}
      m_UniformTypeCount = otherBaseShader2->m_UniformTypeCount;
      m_UniformTypes = new const char*[m_UniformTypeCount];
    }

  for(uint index = 0; index < m_UniformTypeCount; index++)
    {
      m_UniformTypes[index] = otherBaseShader2->m_UniformTypes[index];
    }
}

void BaseShader::destroy()
{

}

unsigned int BaseShader::getShaderId()
{
  return m_ShaderId;
}

const unsigned int BaseShader::getShaderId() const
{
  return m_ShaderId;
}

void BaseShader::setShaderId(unsigned int value)
{
  m_ShaderId = value;
}

//__CUSTOM_METHODS__
