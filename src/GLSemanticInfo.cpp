#include "GLSemanticInfo.h"
//__HEADERS__
#include "StructSizeDescription.h"
#include <sstream>
using namespace std;
//__HEADERS__
void* GLSemanticInfo::Constructor()
{
  return new GLSemanticInfo();
}
GLSemanticInfo::GLSemanticInfo()
{
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

GLSemanticInfo::GLSemanticInfo(const GLSemanticInfo& other)
{
  copy(other);
}

GLSemanticInfo& GLSemanticInfo::operator=(const GLSemanticInfo& other)
{
  copy(other);
  return *this;
}

void GLSemanticInfo::copy(const GLSemanticInfo& other)
{
  m_Name = other.m_Name;
  m_Offset = other.m_Offset;
  m_ElementType = other.m_ElementType;
  m_ChildCount = other.m_ChildCount;
  m_Normalize = other.m_Normalize;
}

GLSemanticInfo::~GLSemanticInfo()
{
}

GLSemanticInfo::GLSemanticInfo(string name, unsigned int offset, GLenum elementType, unsigned int childCount, bool normalize)
{
m_Name = name;
m_Offset = offset;
m_ElementType = elementType;
m_ChildCount = childCount;
m_Normalize = normalize;
}
string GLSemanticInfo::getName()
{
  return m_Name;
}

const string GLSemanticInfo::getName() const
{
  return m_Name;
}

void GLSemanticInfo::setName(string value)
{
  m_Name = value;
}
unsigned int GLSemanticInfo::getOffset()
{
  return m_Offset;
}

const unsigned int GLSemanticInfo::getOffset() const
{
  return m_Offset;
}

void GLSemanticInfo::setOffset(unsigned int value)
{
  m_Offset = value;
}
GLenum GLSemanticInfo::getElementType()
{
  return m_ElementType;
}

const GLenum GLSemanticInfo::getElementType() const
{
  return m_ElementType;
}

void GLSemanticInfo::setElementType(GLenum value)
{
  m_ElementType = value;
}
unsigned int GLSemanticInfo::getChildCount()
{
  return m_ChildCount;
}

const unsigned int GLSemanticInfo::getChildCount() const
{
  return m_ChildCount;
}

void GLSemanticInfo::setChildCount(unsigned int value)
{
  m_ChildCount = value;
}
bool GLSemanticInfo::getNormalize()
{
  return m_Normalize;
}

const bool GLSemanticInfo::getNormalize() const
{
  return m_Normalize;
}

void GLSemanticInfo::setNormalize(bool value)
{
  m_Normalize = value;
}
void GLSemanticInfo::merge(const GLSemanticInfo& other)
{
    mergeName(other.m_Name);
    mergeOffset(other.m_Offset);
    mergeElementType(other.m_ElementType);
    mergeChildCount(other.m_ChildCount);
    mergeNormalize(other.m_Normalize);
}

void GLSemanticInfo::clear()
{
    clearName();
    clearOffset();
    clearElementType();
    clearChildCount();
    clearNormalize();
}
void GLSemanticInfo::mergeName(const string& otherName)
{
}
void GLSemanticInfo::mergeOffset(const unsigned int& otherOffset)
{
}
void GLSemanticInfo::mergeElementType(const GLenum& otherElementType)
{
}
void GLSemanticInfo::mergeChildCount(const unsigned int& otherChildCount)
{
}
void GLSemanticInfo::mergeNormalize(const bool& otherNormalize)
{
}
void GLSemanticInfo::clearName()
{
}
void GLSemanticInfo::clearOffset()
{
}
void GLSemanticInfo::clearElementType()
{
}
void GLSemanticInfo::clearChildCount()
{
}
void GLSemanticInfo::clearNormalize()
{
}
//__CUSTOM_METHODS__
void GLSemanticInfo::deepCopy(const GLSemanticInfo* copyable)
{
  GLSemanticInfo* otherGLSemanticInfo3 = (GLSemanticInfo*)copyable;
  
  m_Name = otherGLSemanticInfo3->m_Name;
  m_Offset = otherGLSemanticInfo3->m_Offset;
  m_ElementType = otherGLSemanticInfo3->m_ElementType;
  m_ChildCount = otherGLSemanticInfo3->m_ChildCount;
  m_Normalize = otherGLSemanticInfo3->m_Normalize;
}

void GLSemanticInfo::destroy()
{

}

bool GLSemanticInfo::ConvertSSDToGLSI(bool normalize,
					      const StructSizeDescription* ssd, 
					      GLSemanticInfo* glsi)
{
  glsi->setName(ssd->getName());
  glsi->setNormalize(normalize);
 
  glsi->setOffset(ssd->getOffset());
  const StructSizeDescription* child = ssd->getChildrenElement(0);
  glsi->setElementType(convertPrimitiveETypeToGLenum(child->getPrimitiveType()));
  glsi->setChildCount(ssd->getChildrenCount());    
  
  return true;
}

bool GLSemanticInfo::ConvertGLSIToSSD(const GLSemanticInfo* glsi, 
				       StructSizeDescription* ssd, bool& normalize)
{
  ssd->setIsPrimitive(false);
  ssd->setName(glsi->getName());
  normalize = glsi->getNormalize();

  for(uint index = 0; index < glsi->getChildCount(); index++)
    {
      stringstream ss;
      ss << index;
      string componentName = ss.str();

      PrimitiveEType primitiveType = convertGLenumToPrimitiveEType(glsi->getElementType());
      StructSizeDescription* child = new StructSizeDescription(true, false, primitiveType,
								 componentName, NULL);
      ssd->appendChildren(child);
    }

  return true;
}
//__CUSTOM_METHODS__
