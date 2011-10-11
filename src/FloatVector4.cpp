#include "FloatVector4.h"
//__HEADERS__
#include "OpenGLUtils.h"
//__HEADERS__
void* FloatVector4::Constructor()
{
  return new FloatVector4();
}
FloatVector4::FloatVector4()
{
m_Value = NULL;
m_ValueCount = 0;
//__CUSTOM_INIT__
 m_Type = "FloatVector4";
//__CUSTOM_INIT__

}

FloatVector4::FloatVector4(const FloatVector4& other)
{
  copy(other);
}

FloatVector4& FloatVector4::operator=(const FloatVector4& other)
{
  copy(other);
  return *this;
}

void FloatVector4::copy(const FloatVector4& other)
{
  m_ElementCount = other.m_ElementCount;
  m_Value = other.m_Value;
}

FloatVector4::~FloatVector4()
{
}

FloatVector4::FloatVector4(unsigned int elementCount, float* value, unsigned int valueCount)
{
m_ElementCount = elementCount;
m_Value = value;
}
unsigned int FloatVector4::getElementCount()
{
  return m_ElementCount;
}

const unsigned int FloatVector4::getElementCount() const
{
  return m_ElementCount;
}

void FloatVector4::setElementCount(unsigned int value)
{
  m_ElementCount = value;
}
float* FloatVector4::getValue()
{
  return m_Value;
}

float const * FloatVector4::getValue() const
{
  return m_Value;
}

const float FloatVector4::getValueElement(unsigned int index) const
{
return m_Value[index];
}

float FloatVector4::getValueElement(unsigned int index)
{
return m_Value[index];
}

unsigned int FloatVector4::getValueCount() const
{
  return m_ValueCount;
}
void FloatVector4::setValue(float* array)
{
  m_Value = array;
}

void FloatVector4::setValueElement(unsigned int index, float element)
{
  m_Value[index] = element;
}

void FloatVector4::setValueCount(unsigned int count)
{
  m_ValueCount = count;
}

void FloatVector4::merge(const FloatVector4& other)
{
    mergeElementCount(other.m_ElementCount);
    mergeValue(other.m_Value);
}

void FloatVector4::clear()
{
    clearElementCount();
    clearValue();
}
void FloatVector4::mergeElementCount(const unsigned int& otherElementCount)
{
}
void FloatVector4::mergeValue(float* const  otherValue)
{
}
void FloatVector4::clearElementCount()
{
}
void FloatVector4::clearValue()
{
}
//__CUSTOM_METHODS__
bool FloatVector4::predraw(string& message)
{  
  glUniform4fv(m_UniformLocation, m_ElementCount, m_Value);
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

void FloatVector4::deepCopy(const IUniform* other)
{
  FloatVector4* otherFloatMatrix4 = (FloatVector4*)other;
  IUniform::deepCopy(other);
  
  m_ElementCount = otherFloatMatrix4->m_ElementCount;
  m_Value = otherFloatMatrix4->m_Value;
  m_ValueCount = otherFloatMatrix4->m_ValueCount;
}

void FloatVector4::destroy()
{

}

IUniform* FloatVector4::clone()
{
    FloatVector4* result = new FloatVector4();
    
    result->deepCopy(this);

    return result;
}


//__CUSTOM_METHODS__
