#ifndef VERTEXSHADER2_H
#define VERTEXSHADER2_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__

#include "BaseShader.h"
//__HEADERS__

class ShaderAttribute;

class VertexShader: public BaseShader
{
  public:
    static void* Constructor();
    VertexShader();
    VertexShader(const VertexShader& other);
    VertexShader& operator=(const VertexShader& other);
    ~VertexShader();
    void copy(const VertexShader& other);
    VertexShader(ShaderAttribute** attributes, unsigned int attributesCount);
//__CUSTOM_METHODS__
    bool getAttributeIndex(string attributeName, unsigned int& attributeIndex, 
			   string& message) const;
    virtual void deepCopy(const BaseShader* copyable);
    static void* Create();
//__CUSTOM_METHODS__
    void mergeAttributes(ShaderAttribute** const otherAttributes);
    void clearAttributes();
    ShaderAttribute** getAttributes();
    ShaderAttribute* const * getAttributes() const;

    const ShaderAttribute* getAttributesElement(unsigned int index) const;
    ShaderAttribute* getAttributesElement(unsigned int index);
    unsigned int getAttributesCount() const;

    void setAttributes(ShaderAttribute** array);
    void setAttributesElement(unsigned int index, ShaderAttribute* element);
    void setAttributesCount(unsigned int count);

    void cache();
    void uncache();
    void merge(const VertexShader& other);
    void clear();
private:
    ShaderAttribute** m_Attributes;
    unsigned int m_AttributesCount;
//__CUSTOM_MEMBERS__


//__CUSTOM_MEMBERS__
};
#endif
