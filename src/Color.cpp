#include "Color.h"

void* Color::Constructor()
{
  return new Color();
}

Color::Color()
{

}

Color::Color(double value)
{
  //Color(value, value, value, 255);
}


Color::Color(double red, double green, double blue, double alpha)
{
  m_Red = red;
  m_Green = green;
  m_Blue = blue;
  m_Alpha = alpha;
}

Color::Color(const Color& other)
{
  m_Red = other.m_Red;
  m_Green = other.m_Green;
  m_Blue = other.m_Blue;
  m_Alpha = other.m_Alpha;
}

double Color::getRed() const
{
  return m_Red;
}

void Color::setRed(double red)
{
  m_Red = red;
}

double Color::getGreen() const
{
  return m_Green;
}

void Color::setGreen(double green)
{
  m_Green = green;
}

double Color::getBlue() const
{
  return m_Blue;
}

void Color::setBlue(double blue)
{
  m_Blue = blue;
}

double Color::getAlpha() const
{
  return m_Alpha;
}

void Color::setAlpha(double alpha)
{
  m_Alpha = alpha;
}

bool operator==(const Color& left, const Color& right)
{
  if(left.m_Red == right.m_Red &&
     left.m_Green == right.m_Green &&
     left.m_Blue == right.m_Blue &&
     left.m_Alpha == right.m_Alpha)
    {
      return true;
    }
  else
    {
      return false;
    }
}

