#ifndef IUNIFORMMAPPER_H

#include <string>

class IUniform;
class IUniformConverter;

class IUniformMapper
{
public:

  virtual void addConverter(IUniformConverter* converter) = 0;
  virtual void addUniform(IUniform* uniform) = 0;
  
  virtual bool addMapping(string start, string end, string& message) = 0;

  virtual bool map(string& message) = 0;

  virtual unsigned int unmappedUniformCount() = 0;
    
  virtual void getUnmappedUniforms(IUniform** uniforms, unsigned int uniformCount) = 0;

};

#endif
