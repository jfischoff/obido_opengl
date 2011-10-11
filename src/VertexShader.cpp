#include "VertexShader.h"
#include "ShaderAttribute.h"
#include <assert.h>
//__HEADERS__

//__HEADERS__
void* VertexShader::Constructor()
{
  return new VertexShader();
}
VertexShader::VertexShader()
{
m_Attributes = NULL;
m_AttributesCount = 0;
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

VertexShader::VertexShader(const VertexShader& other)
{
  copy(other);
}

VertexShader& VertexShader::operator=(const VertexShader& other)
{
  copy(other);
  return *this;
}

void VertexShader::copy(const VertexShader& other)
{
  m_Attributes = other.m_Attributes;
}

VertexShader::~VertexShader()
{
}

VertexShader::VertexShader(ShaderAttribute** attributes, unsigned int attributesCount)
{
m_Attributes = attributes;
}
ShaderAttribute** VertexShader::getAttributes()
{
  return m_Attributes;
}

ShaderAttribute* const * VertexShader::getAttributes() const
{
  return m_Attributes;
}

const ShaderAttribute* VertexShader::getAttributesElement(unsigned int index) const
{
return m_Attributes[index];
}

ShaderAttribute* VertexShader::getAttributesElement(unsigned int index)
{
return m_Attributes[index];
}

unsigned int VertexShader::getAttributesCount() const
{
  return m_AttributesCount;
}
void VertexShader::setAttributes(ShaderAttribute** array)
{
  m_Attributes = array;
}

void VertexShader::setAttributesElement(unsigned int index, ShaderAttribute* element)
{
  m_Attributes[index] = element;
}

void VertexShader::setAttributesCount(unsigned int count)
{
  m_AttributesCount = count;
}

void VertexShader::merge(const VertexShader& other)
{
    mergeAttributes(other.m_Attributes);
}

void VertexShader::clear()
{
    clearAttributes();
}
void VertexShader::mergeAttributes(ShaderAttribute** const  otherAttributes)
{
}
void VertexShader::clearAttributes()
{
}
//__CUSTOM_METHODS__

bool VertexShader::getAttributeIndex(string attributeName, unsigned int& index, 
				     string& message) const
{
  //find the name
  //TODO
  for(unsigned int attributeIndex = 0; attributeIndex < m_AttributesCount;
      attributeIndex++)
    {
      const ShaderAttribute* attribute = getAttributesElement(attributeIndex);
      string currentAttributeName = attribute->getName();
      if(currentAttributeName == attributeName)
	{
	  index = attribute->getAttributeIndex();
	  return true;
	}
    }
	
  message += attributeName;
  message += " not found";
  return false;
}

void VertexShader::cache()
{
  BaseShader::cache();
}

void VertexShader::uncache()
{
  BaseShader::uncache();
}

void VertexShader::deepCopy(const BaseShader* copyable)
{
  BaseShader::deepCopy(copyable);
  VertexShader* otherVertexShader = (VertexShader*)copyable;
  
     if(m_AttributesCount != otherVertexShader->m_AttributesCount)
    {
      if(m_AttributesCount != 0)
	{
	  assert(m_Attributes != NULL);
	  delete[] m_Attributes;
	}

      m_AttributesCount = otherVertexShader->m_AttributesCount;
      m_Attributes = new ShaderAttribute*[otherVertexShader->m_AttributesCount];
    }

  for(unsigned int index = 0; index < m_AttributesCount; index++)
    {
      
      ShaderAttribute* currentAttribute = 
	otherVertexShader->m_Attributes[index];

      m_Attributes[index] = new ShaderAttribute();
      m_Attributes[index]->deepCopy(currentAttribute);
      
    }
}

void* VertexShader::Create()
{
  VertexShader* returnValue = new VertexShader();
  returnValue->setAttributesCount(0);
  
  return returnValue;
}
//__CUSTOM_METHODS__
