#ifndef MATERIAL3_H
#define MATERIAL3_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__
#include <DynamicArray.h>
#include "UniformMapper.h"
#include "IUniformMapper.h"
//__HEADERS__

class Program;
class IUniform;
class ShaderValue


class Material : public IUniformMapper
{
  public:
    static void* Constructor();
    Material();
    Material(const Material& other);
    Material& operator=(const Material& other);
    ~Material();
    void copy(const Material& other);
    Material(Program* program, map< string, Image* >  images);
//__CUSTOM_METHODS__
    bool setup(string& message);
    bool predraw(string& message);
    bool postdraw(string& message);
    bool getAttributeIndex(const char* attributeName, 
			 unsigned int& attributeIndex, string& message);

    IUniform* getUniformsElementByName(const char* name);

    static void* Create();

    unsigned int unmappedUniformCount();
    
    void getUnmappedUniforms(IUniform** uniforms, unsigned int uniformCount);
    
//__CUSTOM_METHODS__
    void mergeImages(const map< string, Image* > & otherImages);
    void clearImages();

    Program* getProgram();
    const Program* getProgram() const;
    void setProgram(Program* value);

    ShaderValue* getShaderValueElement(string key);
    pair<string, ShaderValue*> getShaderValueMember(unsigned int index);
    map< string, ShaderValue* > ::iterator getShaderValueStartIter();
    map< string, ShaderValue* > ::iterator getShaderValueEndIter();
    void setImagesElement(string key, ShaderValue* value);
    
    void deepCopy(const Material* copyable);
    void destroy();
    void merge(const Material& other);
    void clear();
private:
    Program* m_Program;
    map< string, ShaderValue* >  m_ShaderValues;
    UniformMapper m_UniformMapper;
    
//__CUSTOM_MEMBERS__

//__CUSTOM_MEMBERS__
};
#endif
