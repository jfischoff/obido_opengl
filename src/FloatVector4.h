#ifndef FLOATVECTOR4_H
#define FLOATVECTOR4_H

#include "IUniform.h"
#include <string>
#include <map>
using namespace std;
//__HEADERS__
//__HEADERS__


class FloatVector4: public IUniform
{
  public:
    static void* Constructor();
    FloatVector4();
    FloatVector4(const FloatVector4& other);
    FloatVector4& operator=(const FloatVector4& other);
    ~FloatVector4();
    void copy(const FloatVector4& other);
    FloatVector4(unsigned int elementCount, float* value, unsigned int valueCount);
//__CUSTOM_METHODS__
    bool predraw(string& message);
    virtual void deepCopy(const IUniform* other);
    virtual void destroy();
    virtual IUniform* clone();
//__CUSTOM_METHODS__
    void mergeElementCount(const unsigned int& otherElementCount);
    void mergeValue(float* const otherValue);
    void clearElementCount();
    void clearValue();
    unsigned int getElementCount();
    const unsigned int getElementCount() const;

    void setElementCount(unsigned int value);

    float* getValue();
    float const * getValue() const;

    const float getValueElement(unsigned int index) const;
    float getValueElement(unsigned int index);
    unsigned int getValueCount() const;

    void setValue(float* array);
    void setValueElement(unsigned int index, float element);
    void setValueCount(unsigned int count);

    
    void merge(const FloatVector4& other);
    void clear();
private:
    unsigned int m_ElementCount;
    float* m_Value;
    unsigned int m_ValueCount;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
