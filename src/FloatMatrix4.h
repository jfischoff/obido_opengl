#ifndef FLOATMATRIX4_H
#define FLOATMATRIX4_H

#include "IUniform.h"
#include <string>
#include <map>
using namespace std;
//__HEADERS__
//__HEADERS__


class FloatMatrix4: public IUniform
{
  public:
    static void* Constructor();
    FloatMatrix4();
    FloatMatrix4(const FloatMatrix4& other);
    FloatMatrix4& operator=(const FloatMatrix4& other);
    ~FloatMatrix4();
    void copy(const FloatMatrix4& other);
    FloatMatrix4(unsigned int elementCount, bool transpose, float* value, unsigned int valueCount);
//__CUSTOM_METHODS__
    bool predraw(string& message);
    virtual void deepCopy(const IUniform* other);
    virtual void destroy();
    virtual IUniform* clone();
//__CUSTOM_METHODS__
    void mergeElementCount(const unsigned int& otherElementCount);
    void mergeTranspose(const bool& otherTranspose);
    void mergeValue(float* const otherValue);
    void clearElementCount();
    void clearTranspose();
    void clearValue();
    unsigned int getElementCount();
    const unsigned int getElementCount() const;

    void setElementCount(unsigned int value);

    bool getTranspose();
    const bool getTranspose() const;

    void setTranspose(bool value);

    float* getValue();
    float const * getValue() const;

    const float getValueElement(unsigned int index) const;
    float getValueElement(unsigned int index);
    unsigned int getValueCount() const;

    void setValue(float* array);
    void setValueElement(unsigned int index, float element);
    void setValueCount(unsigned int count);

    
    void merge(const FloatMatrix4& other);
    void clear();
private:
    unsigned int m_ElementCount;
    bool m_Transpose;
    float* m_Value;
    unsigned int m_ValueCount;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
