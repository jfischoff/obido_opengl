#ifndef COLOR_H
#define COLOR_H

#include <iostream>
using namespace std;

class Color
{
 public:
  static void* Constructor();
  Color();
  Color(double value);
  Color(double red, double green, double blue, double alpha);
  Color(const Color& other);

  double getRed() const;
  void setRed(double red);

  double getGreen() const;
  void setGreen(double green);

  double getBlue() const;
  void setBlue(double blue);

  double getAlpha() const;
  void setAlpha(double alpha);

  friend bool operator==(const Color& left, const Color& right);

 private:
  double m_Red;
  double m_Green;
  double m_Blue;
  double m_Alpha;

};


#endif //COLOR_H
