#include "ShaderAttribute.h"
#include <assert.h>
//__HEADERS__
//__HEADERS__
void* ShaderAttribute::Constructor()
{
  return new ShaderAttribute();
}
ShaderAttribute::ShaderAttribute()
{
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

ShaderAttribute::ShaderAttribute(const ShaderAttribute& other)
{
  copy(other);
}

ShaderAttribute& ShaderAttribute::operator=(const ShaderAttribute& other)
{
  copy(other);
  return *this;
}

void ShaderAttribute::copy(const ShaderAttribute& other)
{
  m_Name = other.m_Name;
  m_AttributeType = other.m_AttributeType;
  m_AttributeIndex = other.m_AttributeIndex;
}

ShaderAttribute::~ShaderAttribute()
{
}

ShaderAttribute::ShaderAttribute(string name, string attributeType, unsigned int attributeIndex)
{
m_Name = name;
m_AttributeType = attributeType;
m_AttributeIndex = attributeIndex;
}
string ShaderAttribute::getName()
{
  return m_Name;
}

const string ShaderAttribute::getName() const
{
  return m_Name;
}

void ShaderAttribute::setName(string value)
{
  m_Name = value;
}
string ShaderAttribute::getAttributeType()
{
  return m_AttributeType;
}

const string ShaderAttribute::getAttributeType() const
{
  return m_AttributeType;
}

void ShaderAttribute::setAttributeType(string value)
{
  m_AttributeType = value;
}
unsigned int ShaderAttribute::getAttributeIndex()
{
  return m_AttributeIndex;
}

const unsigned int ShaderAttribute::getAttributeIndex() const
{
  return m_AttributeIndex;
}

void ShaderAttribute::setAttributeIndex(unsigned int value)
{
  m_AttributeIndex = value;
}
void ShaderAttribute::merge(const ShaderAttribute& other)
{
    mergeName(other.m_Name);
    mergeAttributeType(other.m_AttributeType);
    mergeAttributeIndex(other.m_AttributeIndex);
}

void ShaderAttribute::clear()
{
    clearName();
    clearAttributeType();
    clearAttributeIndex();
}
void ShaderAttribute::mergeName(const string& otherName)
{
}
void ShaderAttribute::mergeAttributeType(const string& otherAttributeType)
{
}
void ShaderAttribute::mergeAttributeIndex(const unsigned int& otherAttributeIndex)
{
}
void ShaderAttribute::clearName()
{
}
void ShaderAttribute::clearAttributeType()
{
}
void ShaderAttribute::clearAttributeIndex()
{
}


void ShaderAttribute::deepCopy(const ShaderAttribute* copyable)
{
  ShaderAttribute* otherShaderAttribute = (ShaderAttribute*)copyable;
  m_Name = otherShaderAttribute->m_Name;
  m_AttributeType = otherShaderAttribute->m_AttributeType;
  m_AttributeIndex = otherShaderAttribute->m_AttributeIndex;
}

void ShaderAttribute::destroy()
{
  assert(0);
}
//__CUSTOM_METHODS__
