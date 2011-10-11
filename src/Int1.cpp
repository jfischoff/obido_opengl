#include "Int1.h"
//__HEADERS__
#include "OpenGLUtils.h"
//__HEADERS__
void* Int1::Constructor()
{
  return new Int1();
}
Int1::Int1()
{
//__CUSTOM_INIT__
 m_Type = "Int1";
//__CUSTOM_INIT__

}

Int1::Int1(const Int1& other)
{
  copy(other);
}

Int1& Int1::operator=(const Int1& other)
{
  copy(other);
  return *this;
}

void Int1::copy(const Int1& other)
{
  m_Value = other.m_Value;
}

Int1::~Int1()
{
}

Int1::Int1(int value)
{
m_Value = value;
}
int Int1::getValue()
{
  return m_Value;
}

const int Int1::getValue() const
{
  return m_Value;
}

void Int1::setValue(int value)
{
  m_Value = value;
}
void Int1::merge(const Int1& other)
{
    mergeValue(other.m_Value);
}

void Int1::clear()
{
    clearValue();
}
void Int1::mergeValue(const int& otherValue)
{
}
void Int1::clearValue()
{
}
//__CUSTOM_METHODS__
bool Int1::predraw(string& message)
{
  glUniform1i(m_UniformLocation, m_Value);
  CHECK_ERROR_AND_RETURN(message);
  return true;
}

void Int1::deepCopy(const IUniform* other)
{
  Int1* otherFloatMatrix4 = (Int1*)other;
  IUniform::deepCopy(other);
  
  m_Value = otherFloatMatrix4->m_Value;  
}

IUniform* Int1::clone()
{
    Int1* result = new Int1();
    result->deepCopy(this);
    return result;
}

void Int1::destroy()
{
    
}
//__CUSTOM_METHODS__
