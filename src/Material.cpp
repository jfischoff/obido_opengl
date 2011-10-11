#include "Material.h"
#include "Program.h"
#include "IUniform.h"
#include "Image.h"
//__HEADERS__
#include <string.h>
#include "OpenGLUtils.h"
#include "Stream.h"
#include "Int1.h"
#include "Program.h"
#include <assert.h>
#include "ShaderValue.h"
//__HEADERS__
void* Material::Constructor()
{
  return new Material();
}
Material::Material()
{
m_Program = NULL;
m_Uniforms = NULL;
m_UniformsCount = 0;
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

Material::Material(const Material& other)
{
  copy(other);
}

Material& Material::operator=(const Material& other)
{
  copy(other);
  return *this;
}

void Material::copy(const Material& other)
{
  m_Program = other.m_Program;
  m_Uniforms = other.m_Uniforms;
  m_Images = other.m_Images;
}

Material::~Material()
{
}

Material::Material(Program* program, IUniform** uniforms, unsigned int uniformsCount, map< string, Image* >  images)
{
m_Program = program;
m_Uniforms = uniforms;
m_Images = images;
}
Program* Material::getProgram()
{
  return m_Program;
}

const Program* Material::getProgram() const
{
  return m_Program;
}

void Material::setProgram(Program* value)
{
  m_Program = value;
}
IUniform** Material::getUniforms()
{
  return m_Uniforms;
}

IUniform* const * Material::getUniforms() const
{
  return m_Uniforms;
}

const IUniform* Material::getUniformsElement(unsigned int index) const
{
return m_Uniforms[index];
}

IUniform* Material::getUniformsElement(unsigned int index)
{
return m_Uniforms[index];
}

unsigned int Material::getUniformsCount() const
{
  return m_UniformsCount;
}
void Material::setUniforms(IUniform** array)
{
  m_Uniforms = array;
}

void Material::setUniformsElement(unsigned int index, IUniform* element)
{
  m_Uniforms[index] = element;
}

void Material::setUniformsCount(unsigned int count)
{
  m_UniformsCount = count;
}

Image* Material::getImagesElement(string key)
{
  return m_Images[key];
}

pair<string, Image*> Material::getImagesMember(unsigned int index)
{
  unsigned int currentIndex = 0;
  for(map< string, Image* > ::iterator iter = m_Images.begin();
    iter != m_Images.end(); iter++, currentIndex++)
  if(currentIndex == index)
  {
    return *iter;
  }
  return *m_Images.end();
}

map< string, Image* > ::iterator Material::getImagesStartIter()
{
  return m_Images.begin();
}
map< string, Image* > ::iterator Material::getImagesEndIter()
{
  return m_Images.end();
}
void Material::setImagesElement(string key, Image* value)
{
  m_Images[key] = value;
}
void Material::merge(const Material& other)
{
    mergeProgram(other.m_Program);
    mergeUniforms(other.m_Uniforms);
    mergeImages(other.m_Images);
}

void Material::clear()
{
    clearProgram();
    clearUniforms();
    clearImages();
}
void Material::mergeProgram(Program* const otherProgram)
{
  m_Program->merge(*otherProgram);
}
void Material::mergeUniforms(IUniform** const  otherUniforms)
{
}
void Material::mergeImages(const map< string, Image* > & otherImages)
{
  for(map< string, Image* > ::const_iterator iter = otherImages.begin(); iter != otherImages.end(); iter++)
  {
     m_Images.insert(*iter);
  }
}
void Material::clearProgram()ShaderValue
{
  m_Program->clear();
}
void Material::clearUniforms()
{
}
void Material::clearImages()
{
}
//__CUSTOM_METHODS__


bool Material::predraw(string& message)
{
  //I need to set the program to current
  if(m_Program->predraw(message) == false) return false;
  
  for(map<string, ShaderValue*>::iterator iter = m_ShaderValues.begin(); 
      iter != m_ShaderValues.end(); iter++)
    {
      ShaderValue* currentShaderValue = iter->second;

      if(currentImage->predraw(message) == false) 
        return false;
    }

  return true;	
}

bool Material::postdraw(string& message)
{

  for(map<string, ShaderValue*>::iterator iter = m_ShaderValues.begin(); 
      iter != m_ShaderValues.end(); iter++)
    {
      ShaderValue* currentShaderValue = iter->second;

      if(currentImage->postdraw(message) == false) 
        return false;
    }

  return true;
}

bool Material::getAttributeIndex(const char* attributeName, 
				 unsigned int& attributeIndex, string& message)
{
  return m_Program->getAttributeIndex(attributeName, attributeIndex, message);
}

bool Material::setup(string& message)
{
  if(m_Program->setup(message) == false) 
    return false;

  for(map<string, ShaderValue*>::iterator iter = m_ShaderValues.begin(); 
      iter != m_ShaderValues.end(); iter++, index++)
    {

      string shaderValue = iter->first;
      ShaderValue* currentShaderValue = iter->second;

      if(currentImage->setup(message) == false) 
        return false;

      m_UniformMapper.addConverter(currentShaderValue);

    }

    unsigned int uniformCount = m_Program->getUniformsCount();

    for(unsigned int i = 0; i < uniformCount; i++)
    {  
        IUniform* currentUniform = m_Program->getUniformsElement(i);
        
        m_UniformMapper.addUniform(currentUniform);
    }

    m_UniformMapper.map();

  return true;
}

unsigned int Material::unmappedUniformCount()
{
    return m_UniformMapper.unmappedUniformCount();
}
    
void Material::getUnmappedUniforms(IUniform** uniforms, unsigned int uniformCount)
{
    return m_UniformMapper.getUnmappedUniforms(uniforms, uniformCount);
}

void Material::deepCopy(const Material* copyable)
{
  bool realloc = false;
  Material* otherMaterial = (Material*)copyable;

  if(otherMaterial == this) return;

  if(m_Program == NULL)
    {
      m_Program = new Program();
    }

  m_Program->deepCopy(otherMaterial->m_Program);

  for(map<string, ShaderValue*>::iterator iter = otherMaterial->m_ShaderValues.begin(); 
      iter != otherMaterial->m_ShaderValues.end(); iter++)
    {

      string imageName = iter->first;
      ShaderValue* currentImage = iter->second;

      if(m_ShaderValues[imageName] == NULL)
	{
	  m_ShaderValues[imageName] = new ShaderValues();
	}
            
      m_ShaderValues[imageName]->deepCopy(currentImage);      
    }
}

void Material::destroy()
{

}

IUniform* Material::getUniformsElementByName(const char* name)
{
    return m_Program->getUniformsElementByName(name);
}

void* Material::Create()
{
  Material* returnValue = new Material();  
  Program* program = (Program*)Program::Create();
  returnValue->setProgram(program);
  returnValue->setUniformsCount(0);  

  return returnValue;
}
//__CUSTOM_METHODS__
