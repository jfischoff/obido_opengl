#ifndef SHADERATTRIBUTE3_H
#define SHADERATTRIBUTE3_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__
//__HEADERS__


class ShaderAttribute
{
  public:
    static void* Constructor();
    ShaderAttribute();
    ShaderAttribute(const ShaderAttribute& other);
    ShaderAttribute& operator=(const ShaderAttribute& other);
    ~ShaderAttribute();
    void copy(const ShaderAttribute& other);
    ShaderAttribute(string name, string attributeType, unsigned int attributeIndex);
//__CUSTOM_METHODS__
//__CUSTOM_METHODS__
    void mergeName(const string& otherName);
    void mergeAttributeType(const string& otherAttributeType);
    void mergeAttributeIndex(const unsigned int& otherAttributeIndex);
    void clearName();
    void clearAttributeType();
    void clearAttributeIndex();
    string getName();
    const string getName() const;

    void setName(string value);

    string getAttributeType();
    const string getAttributeType() const;

    void setAttributeType(string value);

    unsigned int getAttributeIndex();
    const unsigned int getAttributeIndex() const;

    void setAttributeIndex(unsigned int value);

    
    virtual void deepCopy(const ShaderAttribute* copyable);
    virtual void destroy();
    void merge(const ShaderAttribute& other);
    void clear();
private:
    string m_Name;
    string m_AttributeType;
    unsigned int m_AttributeIndex;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
