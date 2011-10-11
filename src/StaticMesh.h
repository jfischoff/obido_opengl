#ifndef FIXEDMESHTEST_H
#define FIXEDMESHTEST_H

#include "GLenum.h"
#include <string>
#include <map>
using namespace std;
//__HEADERS__
#include "OpenGLUtils.h"
#include <DynamicArray.h>
class DynamicStruct;
//__HEADERS__

class Stream;
class GLSemanticInfo;

class StaticMesh
{
  public:
    static void* Constructor();
    StaticMesh();
    StaticMesh(const StaticMesh& other);
    StaticMesh& operator=(const StaticMesh& other);
    ~StaticMesh();
    void copy(const StaticMesh& other);
    StaticMesh(Stream* indicesStream, Stream* vertices, int polygonCount, GLenum modeType, GLenum indexType, DynamicArray* gLSemanticInfo);
//__CUSTOM_METHODS__
    static void* Create();
    const char* getVertexData() const;
    char* getVertexData();

    const char* getIndices() const;
    char* getIndices();

    unsigned int getIndexAtAsUInt(unsigned int index) const;

    unsigned int getIndexCount() const;
    unsigned int getVertexCount() const;
    unsigned int getStreamCount() const;
    const char* getStreamTypeName(unsigned int streamIndex) const;
    unsigned int getElementCount(unsigned int streamIndex) const;
    GLenum getElementType(unsigned int streamIndex) const;
    bool getNormalize(unsigned int streamIndex) const;
    unsigned int getStreamOffset(unsigned int streamIndex) const;
    unsigned int getStride() const;

    const DynamicStruct* 
      getVertexAsDynamicStruct(unsigned int index, DynamicStruct* dynStruct) const; 
//__CUSTOM_METHODS__
    void mergeIndicesStream(Stream* const otherIndicesStream);
    void mergeVertices(Stream* const otherVertices);
    void mergePolygonCount(const int& otherPolygonCount);
    void mergeModeType(const GLenum& otherModeType);
    void mergeIndexType(const GLenum& otherIndexType);
    void mergeGLSemanticInfo(const DynamicArray& otherGLSemanticInfo);
    void clearIndicesStream();
    void clearVertices();
    void clearPolygonCount();
    void clearModeType();
    void clearIndexType();
    void clearGLSemanticInfo();
    Stream* getIndicesStream();
    const Stream* getIndicesStream() const;

    void setIndicesStream(Stream* value);

    Stream* getVertices();
    const Stream* getVertices() const;

    void setVertices(Stream* value);

    int getPolygonCount();
    const int getPolygonCount() const;

    void setPolygonCount(int value);

    GLenum getModeType();
    const GLenum getModeType() const;

    void setModeType(GLenum value);

    GLenum getIndexType();
    const GLenum getIndexType() const;

    void setIndexType(GLenum value);

    DynamicArray& getGLSemanticInfo();
    const DynamicArray& getGLSemanticInfo() const;

    const GLSemanticInfo* getGLSemanticInfoElement(unsigned int index) const;
    GLSemanticInfo* getGLSemanticInfoElement(unsigned int index);
    unsigned int getGLSemanticInfoCount() const;

    void setGLSemanticInfo(const DynamicArray& array);
    void setGLSemanticInfoElement(unsigned int index, GLSemanticInfo* element);
    void appendGLSemanticInfo(GLSemanticInfo* element);
    void cache();
    void uncache();
    virtual void deepCopy(const StaticMesh* copyable);
    virtual void destroy();
    void merge(const StaticMesh& other);
    void clear();
private:
    Stream* m_IndicesStream;
    Stream* m_Vertices;
    int m_PolygonCount;
    GLenum m_ModeType;
    GLenum m_IndexType;
    DynamicArray m_GLSemanticInfo;
//__CUSTOM_MEMBERS__
    //char* m_VertexData;
    //char* m_Indices;
    unsigned int m_Stride;
//__CUSTOM_MEMBERS__
};
#endif
