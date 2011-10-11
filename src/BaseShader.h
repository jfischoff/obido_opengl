#ifndef BASESHADER2_H
#define BASESHADER2_H

#include "GLenum.h"
#include <string>
#include <map>
using namespace std;
//__HEADERS__
#include "OpenGLUtils.h"
//__HEADERS__


class BaseShader
{
  public:
    static void* Constructor();
    BaseShader();
    BaseShader(const BaseShader& other);
    BaseShader& operator=(const BaseShader& other);
    ~BaseShader();
    void copy(const BaseShader& other);
    BaseShader(string serializedName, string* serializableSources, unsigned int serializableSourcesCount, GLenum shaderType, string* serializableUniformTypes, unsigned int serializableUniformTypesCount);
//__CUSTOM_METHODS__
  bool createShader(string& message);
  bool loadShader(string& message);
  bool compile(string& message);
  bool deleteShader(string& message);
	
  bool isCompiled() const;
	
  void getSources(const char*** sources, int& count) const;
  void setSources(const char** sources, int count);
	
  GLenum convertToShaderType(string shaderTypeName);
  string convertToShaderTypeName(GLenum shaderType);
	
  //stream methods
  const char* getUniformType(unsigned int index) const;
  void setUniformType(unsigned int index, const char* uniformType);
	
  unsigned int getUniformCount() const;

  bool setup(string& message);

  unsigned int getShaderId();
  const unsigned int getShaderId() const;

  void setShaderId(unsigned int value);

//__CUSTOM_METHODS__
    void mergeSerializedName(const string& otherSerializedName);
    void mergeSerializableSources(string* const otherSerializableSources);
    void mergeShaderType(const GLenum& otherShaderType);
    void mergeSerializableUniformTypes(string* const otherSerializableUniformTypes);
    void clearSerializedName();
    void clearSerializableSources();
    void clearShaderType();
    void clearSerializableUniformTypes();
    string getSerializedName();
    const string getSerializedName() const;

    void setSerializedName(string value);

    string* getSerializableSources();
    string const * getSerializableSources() const;

    const string getSerializableSourcesElement(unsigned int index) const;
    string getSerializableSourcesElement(unsigned int index);
    unsigned int getSerializableSourcesCount() const;

    void setSerializableSources(string* array);
    void setSerializableSourcesElement(unsigned int index, string element);
    void setSerializableSourcesCount(unsigned int count);

    GLenum getShaderType();
    const GLenum getShaderType() const;

    void setShaderType(GLenum value);

    string* getSerializableUniformTypes();
    string const * getSerializableUniformTypes() const;

    const string getSerializableUniformTypesElement(unsigned int index) const;
    string getSerializableUniformTypesElement(unsigned int index);
    unsigned int getSerializableUniformTypesCount() const;

    void setSerializableUniformTypes(string* array);
    void setSerializableUniformTypesElement(unsigned int index, string element);
    void setSerializableUniformTypesCount(unsigned int count);

    void cache();
    void uncache();
    virtual void deepCopy(const BaseShader* copyable);
    virtual void destroy();
    void merge(const BaseShader& other);
    void clear();
private:
    string m_SerializedName;
    string* m_SerializableSources;
    unsigned int m_SerializableSourcesCount;
    GLenum m_ShaderType;
    string* m_SerializableUniformTypes;
    unsigned int m_SerializableUniformTypesCount;
//__CUSTOM_MEMBERS__
  const char* m_Name;
  const char** m_Sources;
  unsigned int m_SourcesCount;
  const char** m_UniformTypes;
  unsigned int m_UniformTypeCount;
  bool m_IsCompiled;
  unsigned int m_ShaderId;
//__CUSTOM_MEMBERS__
};
#endif
