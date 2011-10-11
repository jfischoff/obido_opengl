#ifndef UNIFORM2_H
#define UNIFORM2_H

#include <string>

using namespace std;

class Program;

class IUniform
{
public:		
  virtual bool setup(string& message);

  virtual bool predraw(string& message) = 0;
  
  const char* getName() const;
  void setName(string name);

  const char* getTypeName();

  virtual void deepCopy(const IUniform* other) = 0;
  virtual void destroy() = 0;
  virtual IUniform* clone() = 0;
  
protected:
  bool requestUniformLocation(unsigned int programId, string& message);	

  unsigned int m_UniformLocation;
  string m_Name;
  const char* m_Type;
  Program* m_Program;
	
};


#endif //UNIFORM2_H

