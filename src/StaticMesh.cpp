#include "StaticMesh.h"
#include <Stream.h>
#include "GLSemanticInfo.h"
//__HEADERS__
#include <StructSizeDescription.h>
#include <DynamicStruct.h>
#include <assert.h>
//__HEADERS__
void* StaticMesh::Constructor()
{
  return new StaticMesh();
}
StaticMesh::StaticMesh()
{
m_IndicesStream = NULL;
m_Vertices = NULL;
m_GLSemanticInfo.reinit(sizeof(GLSemanticInfo*), 0);
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

StaticMesh::StaticMesh(const StaticMesh& other)
{
  copy(other);
}

StaticMesh& StaticMesh::operator=(const StaticMesh& other)
{
  copy(other);
  return *this;
}

void StaticMesh::copy(const StaticMesh& other)
{
  m_IndicesStream = other.m_IndicesStream;
  m_Vertices = other.m_Vertices;
  m_PolygonCount = other.m_PolygonCount;
  m_ModeType = other.m_ModeType;
  m_IndexType = other.m_IndexType;
  m_GLSemanticInfo = other.m_GLSemanticInfo;
}

StaticMesh::~StaticMesh()
{
}

StaticMesh::StaticMesh(Stream* indicesStream, Stream* vertices, int polygonCount, GLenum modeType, GLenum indexType, DynamicArray* gLSemanticInfo)
{
    m_IndicesStream = indicesStream;
    m_Vertices = vertices;
    m_PolygonCount = polygonCount;
    m_ModeType = modeType;
    m_IndexType = indexType;
    if(gLSemanticInfo != NULL){m_GLSemanticInfo.deepCopy(gLSemanticInfo);}
}
Stream* StaticMesh::getIndicesStream()
{
  return m_IndicesStream;
}

const Stream* StaticMesh::getIndicesStream() const
{
  return m_IndicesStream;
}

void StaticMesh::setIndicesStream(Stream* value)
{
  m_IndicesStream = value;
}
Stream* StaticMesh::getVertices()
{
  return m_Vertices;
}

const Stream* StaticMesh::getVertices() const
{
  return m_Vertices;
}

void StaticMesh::setVertices(Stream* value)
{
  m_Vertices = value;
}
int StaticMesh::getPolygonCount()
{
  return m_PolygonCount;
}

const int StaticMesh::getPolygonCount() const
{
  return m_PolygonCount;
}

void StaticMesh::setPolygonCount(int value)
{
  m_PolygonCount = value;
}
GLenum StaticMesh::getModeType()
{
  return m_ModeType;
}

const GLenum StaticMesh::getModeType() const
{
  return m_ModeType;
}

void StaticMesh::setModeType(GLenum value)
{
  m_ModeType = value;
}
GLenum StaticMesh::getIndexType()
{
  return m_IndexType;
}

const GLenum StaticMesh::getIndexType() const
{
  return m_IndexType;
}

void StaticMesh::setIndexType(GLenum value)
{
  m_IndexType = value;
}
DynamicArray& StaticMesh::getGLSemanticInfo()
{
  return m_GLSemanticInfo;
}

const DynamicArray& StaticMesh::getGLSemanticInfo() const
{
  return m_GLSemanticInfo;
}

const GLSemanticInfo* StaticMesh::getGLSemanticInfoElement(unsigned int index) const
{
return *(GLSemanticInfo**)m_GLSemanticInfo.get(index);
}

GLSemanticInfo* StaticMesh::getGLSemanticInfoElement(unsigned int index)
{
return *(GLSemanticInfo**)m_GLSemanticInfo.get(index);
}

unsigned int StaticMesh::getGLSemanticInfoCount() const
{
  return m_GLSemanticInfo.getCount();
}
void StaticMesh::setGLSemanticInfo(const DynamicArray& array)
{
  m_GLSemanticInfo.deepCopy(&array);
}

void StaticMesh::setGLSemanticInfoElement(unsigned int index, GLSemanticInfo* element)
{
  m_GLSemanticInfo.safeSet(index, &element);
}
void StaticMesh::appendGLSemanticInfo(GLSemanticInfo* element)
{
  m_GLSemanticInfo.append(&element);
}
void StaticMesh::merge(const StaticMesh& other)
{
    mergeIndicesStream(other.m_IndicesStream);
    mergeVertices(other.m_Vertices);
    mergePolygonCount(other.m_PolygonCount);
    mergeModeType(other.m_ModeType);
    mergeIndexType(other.m_IndexType);
    mergeGLSemanticInfo(other.m_GLSemanticInfo);
}

void StaticMesh::clear()
{
    clearIndicesStream();
    clearVertices();
    clearPolygonCount();
    clearModeType();
    clearIndexType();
    clearGLSemanticInfo();
}
void StaticMesh::mergeIndicesStream(Stream* const otherIndicesStream)
{
  m_IndicesStream->merge(*otherIndicesStream);
}
void StaticMesh::mergeVertices(Stream* const otherVertices)
{
  m_Vertices->merge(*otherVertices);
}
void StaticMesh::mergePolygonCount(const int& otherPolygonCount)
{
}
void StaticMesh::mergeModeType(const GLenum& otherModeType)
{
}
void StaticMesh::mergeIndexType(const GLenum& otherIndexType)
{
}
void StaticMesh::mergeGLSemanticInfo(const DynamicArray& otherGLSemanticInfo)
{
  m_GLSemanticInfo.merge(otherGLSemanticInfo);
}
void StaticMesh::clearIndicesStream()
{
  m_IndicesStream->clear();
}
void StaticMesh::clearVertices()
{
  m_Vertices->clear();
}
void StaticMesh::clearPolygonCount()
{
}
void StaticMesh::clearModeType()
{
}
void StaticMesh::clearIndexType()
{
}
void StaticMesh::clearGLSemanticInfo()
{
  m_GLSemanticInfo.clearData();
}
//__CUSTOM_METHODS__
void StaticMesh::cache()
{
  //convert the struct size description into
  m_Stride = m_Vertices->getStructSizeDescription()->getSize();
  
}

void StaticMesh::uncache()
{
  //assert(0);
}

const char* StaticMesh::getVertexData() const
{
  return m_Vertices->getBuffer();
}

char* StaticMesh::getVertexData()
{
  return m_Vertices->getBuffer();
}

const char* StaticMesh::getIndices() const
{
  return m_IndicesStream->getBuffer();  
}

char* StaticMesh::getIndices()
{
  return m_IndicesStream->getBuffer();  
}

unsigned int StaticMesh::getIndexCount() const
{
  return m_IndicesStream->getCount();
}

bool StaticMesh::getNormalize(unsigned int streamIndex) const
{
  return getGLSemanticInfoElement(streamIndex)->getNormalize();
}

unsigned int StaticMesh::getStreamOffset(unsigned int streamIndex) const
{
  return getGLSemanticInfoElement(streamIndex)->getOffset();
}

const char* StaticMesh::getStreamTypeName(unsigned int streamIndex) const
{
  return getGLSemanticInfoElement(streamIndex)->getName().c_str();
}

unsigned int StaticMesh::getElementCount(unsigned int streamIndex) const
{
  return getGLSemanticInfoElement(streamIndex)->getChildCount();
}

GLenum StaticMesh::getElementType(unsigned int streamIndex) const
{
  return getGLSemanticInfoElement(streamIndex)->getElementType();
}

unsigned int StaticMesh::getStreamCount() const
{
  return getGLSemanticInfoCount();
}

unsigned int StaticMesh::getStride() const
{
  return m_Stride;
}

void StaticMesh::deepCopy(const StaticMesh* copyable)
{
  StaticMesh* otherFixedMeshTest = (StaticMesh*)copyable;
  if(m_IndicesStream == NULL)
    {
      m_IndicesStream = new Stream();
    }
  m_IndicesStream->deepCopy(otherFixedMeshTest->m_IndicesStream);

  if(m_Vertices == NULL)
    {
      m_Vertices = new Stream();
    }
  m_Vertices->deepCopy(otherFixedMeshTest->m_Vertices);

  m_PolygonCount = otherFixedMeshTest->m_PolygonCount;
  m_ModeType = otherFixedMeshTest->m_ModeType;
  m_IndexType = otherFixedMeshTest->m_IndexType;
  
  m_GLSemanticInfo.deepCopy(&otherFixedMeshTest->m_GLSemanticInfo);

  m_Stride = otherFixedMeshTest->m_Stride;
}

void StaticMesh::destroy()
{
  assert(0);
}

unsigned int StaticMesh::getVertexCount() const
{
  return m_Vertices->getCount();
}

const DynamicStruct* 
      StaticMesh::getVertexAsDynamicStruct(unsigned int index, DynamicStruct* dynStruct) const
{
  StructSizeDescription*  verticesSSD = 
    (StructSizeDescription*)m_Vertices->getStructSizeDescription();
  dynStruct->setStructSizeDescription(verticesSSD);

  char* data = (char*)m_Vertices->get(index);
  dynStruct->setRawData(data);
  return dynStruct;
}


unsigned int StaticMesh::getIndexAtAsUInt(unsigned int index) const
{
  PrimitiveEType primitiveType = 
    m_IndicesStream->getStructSizeDescription()->getPrimitiveType();

  unsigned int returnValue = -1;

  switch(primitiveType)
    {
    case UCHAR:
      returnValue = *(unsigned char*)m_IndicesStream->get(index);
      break;
    case USHORT:
      returnValue = *(unsigned short*)m_IndicesStream->get(index);
      break;
    case UINT:
      returnValue = *(unsigned int*)m_IndicesStream->get(index);
      break;
    default:
      assert(0);
    }

  return returnValue;

}

void* StaticMesh::Create()
{
  StructSizeDescription* indexSSD = new StructSizeDescription();
  Stream* indicesStream = new Stream(indexSSD);
  
  StructSizeDescription* verticesSSD = new StructSizeDescription();
  Stream* vertices = new Stream(verticesSSD);
  int polygonCount = 0;
  GLenum modeType = GL_TRIANGLES;
  GLenum indexType = GL_UNSIGNED_INT;
  
  DynamicArray* gLSemanticInfo = new DynamicArray();
  gLSemanticInfo->reinit(sizeof(GLSemanticInfo*), 0);

  StaticMesh* fixedMeshTest = new StaticMesh(indicesStream, vertices, polygonCount, 
			      modeType, indexType, gLSemanticInfo);
  return fixedMeshTest;

}
//__CUSTOM_METHODS__
