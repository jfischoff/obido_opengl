#ifndef FLOAT1UNIFORM_H
#define Float1Uniform_H

#include "IUniform.h"
#include "OpenGLUtils.h"

class Float1Uniform : public IUniform
{
  public:
  static void* Constructor();

    void setValue1(float value){m_Value1 = value;}

    float getValue1(){return m_Value1;}

    bool predraw(string& message);

    virtual void deepCopy(const IUniform* other);
    virtual void destroy();
    virtual IUniform* clone();
  private:
    float m_Value1;
};
#endif //FLOAT1UNIFORM_H
