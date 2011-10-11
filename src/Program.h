#ifndef PROGRAM3_H
#define PROGRAM3_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__
//__HEADERS__

class VertexShader;
class FragmentShader;

class Program
{
  public:
    static void* Constructor();
    Program();
    Program(const Program& other);
    Program& operator=(const Program& other);
    ~Program();
    void copy(const Program& other);
    Program(VertexShader* vertexShader, FragmentShader* fragmentShader);
//__CUSTOM_METHODS__
    bool create(string& message);
    bool predraw(string& message);
	
    bool attachVertexShader(string& message);
    bool detachVertexShader(string& message);
    bool attachFragmentShader(string& message);
    bool detachFragmentShader(string& message);	
	
    bool link(string& message);
    bool deleteProgram(string& message);
	
    bool isLinked() const;
	
    unsigned int getProgramId() const;
	
    bool getAttributeIndex(const char* attributeName, unsigned int& attributeIndex, 
			   string& message) const;

    bool setup(string& message);
    static void* Create();

    IUniform** getUniforms();
    IUniform* const * getUniforms() const;

    const IUniform* getUniformsElement(unsigned int index) const;
    IUniform* getUniformsElement(unsigned int index);
    unsigned int getUniformsCount() const;

    IUniform* getUniformsElementByName(const char* name);

//__CUSTOM_METHODS__
    void mergeVertexShader(VertexShader* const otherVertexShader);
    void mergeFragmentShader(FragmentShader* const otherFragmentShader);
    void clearVertexShader();
    void clearFragmentShader();
    VertexShader* getVertexShader();
    const VertexShader* getVertexShader() const;

    void setVertexShader(VertexShader* value);

    FragmentShader* getFragmentShader();
    const FragmentShader* getFragmentShader() const;

    void setFragmentShader(FragmentShader* value);

    
    void deepCopy(const Program* copyable);
    void destroy();
    void merge(const Program& other);
    void clear();
private:
    VertexShader* m_VertexShader;
    FragmentShader* m_FragmentShader;
//__CUSTOM_MEMBERS__
    bool m_IsLinked;
    bool m_VertexShaderIsAttached;
    bool m_FragmentShaderIsAttached;
    unsigned int m_ProgramId;
    
    IUniform** m_Uniforms;
    unsigned int m_UniformsCount;

//__CUSTOM_MEMBERS__
};
#endif
