#include "FragmentShader.h"
//__HEADERS__
//__HEADERS__
void* FragmentShader::Constructor()
{
  return new FragmentShader();
}
FragmentShader::FragmentShader()
{
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

FragmentShader::FragmentShader(const FragmentShader& other)
{
  copy(other);
}

FragmentShader& FragmentShader::operator=(const FragmentShader& other)
{
  copy(other);
  return *this;
}

void FragmentShader::copy(const FragmentShader& other)
{
}

FragmentShader::~FragmentShader()
{
}

void FragmentShader::merge(const FragmentShader& other)
{
}

void FragmentShader::clear()
{
}
//__CUSTOM_METHODS__
void FragmentShader::cache()
{
  BaseShader::cache();
}

void FragmentShader::uncache()
{
  BaseShader::uncache();
}

void* FragmentShader::Create()
{
  return new FragmentShader();
}
//__CUSTOM_METHODS__
