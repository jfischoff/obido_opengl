#ifndef GLSEMANTICINFO3_H
#define GLSEMANTICINFO3_H

#include "GLenum.h"
#include <string>
#include <map>
using namespace std;
//__HEADERS__
class StructSizeDescription;
//__HEADERS__


class GLSemanticInfo
{
  public:
    static void* Constructor();
    GLSemanticInfo();
    GLSemanticInfo(const GLSemanticInfo& other);
    GLSemanticInfo& operator=(const GLSemanticInfo& other);
    ~GLSemanticInfo();
    void copy(const GLSemanticInfo& other);
    GLSemanticInfo(string name, unsigned int offset, GLenum elementType, unsigned int childCount, bool normalize);
//__CUSTOM_METHODS__
    static bool ConvertSSDToGLSI(bool normalize, const StructSizeDescription* ssd, 
			       GLSemanticInfo* glsi);
    static bool ConvertGLSIToSSD(const GLSemanticInfo* glsi, 
				 StructSizeDescription* ssd, bool& normalize);
//__CUSTOM_METHODS__
    void mergeName(const string& otherName);
    void mergeOffset(const unsigned int& otherOffset);
    void mergeElementType(const GLenum& otherElementType);
    void mergeChildCount(const unsigned int& otherChildCount);
    void mergeNormalize(const bool& otherNormalize);
    void clearName();
    void clearOffset();
    void clearElementType();
    void clearChildCount();
    void clearNormalize();
    string getName();
    const string getName() const;

    void setName(string value);

    unsigned int getOffset();
    const unsigned int getOffset() const;

    void setOffset(unsigned int value);

    GLenum getElementType();
    const GLenum getElementType() const;

    void setElementType(GLenum value);

    unsigned int getChildCount();
    const unsigned int getChildCount() const;

    void setChildCount(unsigned int value);

    bool getNormalize();
    const bool getNormalize() const;

    void setNormalize(bool value);

    
    virtual void deepCopy(const GLSemanticInfo* copyable);
    virtual void destroy();
    void merge(const GLSemanticInfo& other);
    void clear();
private:
    string m_Name;
    unsigned int m_Offset;
    GLenum m_ElementType;
    unsigned int m_ChildCount;
    bool m_Normalize;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
