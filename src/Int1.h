#ifndef INT1_H
#define INT1_H

#include "IUniform.h"
#include <string>
#include <map>
using namespace std;
//__HEADERS__
//__HEADERS__


class Int1: public IUniform
{
  public:
    static void* Constructor();
    Int1();
    Int1(const Int1& other);
    Int1& operator=(const Int1& other);
    ~Int1();
    void copy(const Int1& other);
    Int1(int value);
//__CUSTOM_METHODS__
    bool predraw(string& message);
    virtual void deepCopy(const IUniform* other);
    virtual IUniform* clone();
    virtual void destroy();
//__CUSTOM_METHODS__
    void mergeValue(const int& otherValue);
    void clearValue();
    int getValue();
    const int getValue() const;

    void setValue(int value);

    
    void merge(const Int1& other);
    void clear();

    
private:
    int m_Value;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
