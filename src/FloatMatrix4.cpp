#include "FloatMatrix4.h"
//__HEADERS__
#include "OpenGLUtils.h"
//__HEADERS__
void* FloatMatrix4::Constructor()
{
  return new FloatMatrix4();
}
FloatMatrix4::FloatMatrix4()
{
m_Value = NULL;
m_ValueCount = 0;
//__CUSTOM_INIT__
 m_Type = "FloatMatrix4";
//__CUSTOM_INIT__

}

FloatMatrix4::FloatMatrix4(const FloatMatrix4& other)
{
  copy(other);
}

FloatMatrix4& FloatMatrix4::operator=(const FloatMatrix4& other)
{
  copy(other);
  return *this;
}

void FloatMatrix4::copy(const FloatMatrix4& other)
{
  m_ElementCount = other.m_ElementCount;
  m_Transpose = other.m_Transpose;
  m_Value = other.m_Value;
}

FloatMatrix4::~FloatMatrix4()
{
}

FloatMatrix4::FloatMatrix4(unsigned int elementCount, bool transpose, float* value, unsigned int valueCount)
{
m_ElementCount = elementCount;
m_Transpose = transpose;
m_Value = value;
}
unsigned int FloatMatrix4::getElementCount()
{
  return m_ElementCount;
}

const unsigned int FloatMatrix4::getElementCount() const
{
  return m_ElementCount;
}

void FloatMatrix4::setElementCount(unsigned int value)
{
  m_ElementCount = value;
}
bool FloatMatrix4::getTranspose()
{
  return m_Transpose;
}

const bool FloatMatrix4::getTranspose() const
{
  return m_Transpose;
}

void FloatMatrix4::setTranspose(bool value)
{
  m_Transpose = value;
}
float* FloatMatrix4::getValue()
{
  return m_Value;
}

float const * FloatMatrix4::getValue() const
{
  return m_Value;
}

const float FloatMatrix4::getValueElement(unsigned int index) const
{
return m_Value[index];
}

float FloatMatrix4::getValueElement(unsigned int index)
{
return m_Value[index];
}

unsigned int FloatMatrix4::getValueCount() const
{
  return m_ValueCount;
}
void FloatMatrix4::setValue(float* array)
{
  m_Value = array;
}

void FloatMatrix4::setValueElement(unsigned int index, float element)
{
  m_Value[index] = element;
}

void FloatMatrix4::setValueCount(unsigned int count)
{
  m_ValueCount = count;
}

void FloatMatrix4::merge(const FloatMatrix4& other)
{
    mergeElementCount(other.m_ElementCount);
    mergeTranspose(other.m_Transpose);
    mergeValue(other.m_Value);
}

void FloatMatrix4::clear()
{
    clearElementCount();
    clearTranspose();
    clearValue();
}
void FloatMatrix4::mergeElementCount(const unsigned int& otherElementCount)
{
}
void FloatMatrix4::mergeTranspose(const bool& otherTranspose)
{
}
void FloatMatrix4::mergeValue(float* const  otherValue)
{
}
void FloatMatrix4::clearElementCount()
{
}
void FloatMatrix4::clearTranspose()
{
}
void FloatMatrix4::clearValue()
{
}
//__CUSTOM_METHODS__
bool FloatMatrix4::predraw(string& message)
{
  glUniformMatrix4fv(m_UniformLocation, 1, 
		     true, m_Value);
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

void FloatMatrix4::deepCopy(const IUniform* other)
{
  FloatMatrix4* otherFloatMatrix4 = (FloatMatrix4*)other;
  IUniform::deepCopy(other);
  
  m_ElementCount = otherFloatMatrix4->m_ElementCount;
  m_Transpose = otherFloatMatrix4->m_Transpose;
  m_Value = otherFloatMatrix4->m_Value;
  m_ValueCount = otherFloatMatrix4->m_ValueCount;
}

void FloatMatrix4::destroy()
{

}

IUniform* FloatMatrix4::clone()
{
    FloatMatrix4* result = new FloatMatrix4();
    
    result->deepCopy(this);

    return result;
}

//__CUSTOM_METHODS__
