#ifndef UNIFORMMAPPER_H

#include <string>

class IUniform;
class IUniformConverter;

class UniformMapper
{
public:
  UniformMapper();
  UniformMapper(IUniform** uniforms, unsigned int uniformCount,
                IUniformConverter**, unsigned int uniformConverterCount);

  void addConverter(IUniformConverter* converter);
  void addUniform(IUniform* uniform);
  
  bool addMapping(string start, string end, string& message);

  bool map(string& message);

  unsigned int unmappedUniformCount();
    
  void getUnmappedUniforms(IUniform** uniforms, unsigned int uniformCount);

private:
  bool createDefaultMapping(string& message);

  vector<IUniform*> m_Uniforms;
  vector<IUniformConverter*> m_UniformConverters;

  vector< Pair < string, string > > m_Mappings;
};

#endif
