#include "Renderable.h"
#include "Material.h"
#include "StaticMesh.h"
#include <assert.h>
//__HEADERS__
//__HEADERS__
void* Renderable::Constructor()
{
  return new Renderable();
}
Renderable::Renderable()
{
m_Material = NULL;
m_FixedMeshes = NULL;
m_FixedMeshesCount = 0;
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

Renderable::Renderable(const Renderable& other)
{
  copy(other);
}

Renderable& Renderable::operator=(const Renderable& other)
{
  copy(other);
  return *this;
}

void Renderable::copy(const Renderable& other)
{
  m_Material = other.m_Material;
  m_FixedMeshes = other.m_FixedMeshes;
}

Renderable::~Renderable()
{
}

Renderable::Renderable(Material* material, StaticMesh** fixedMeshes, unsigned int fixedMeshesCount)
{
m_Material = material;
m_FixedMeshes = fixedMeshes;
}
Material* Renderable::getMaterial()
{
  return m_Material;
}

const Material* Renderable::getMaterial() const
{
  return m_Material;
}

void Renderable::setMaterial(Material* value)
{
  m_Material = value;
}
StaticMesh** Renderable::getFixedMeshes()
{
  return m_FixedMeshes;
}

StaticMesh* const * Renderable::getFixedMeshes() const
{
  return m_FixedMeshes;
}

const StaticMesh* Renderable::getFixedMeshesElement(unsigned int index) const
{
return m_FixedMeshes[index];
}

StaticMesh* Renderable::getFixedMeshesElement(unsigned int index)
{
return m_FixedMeshes[index];
}

unsigned int Renderable::getFixedMeshesCount() const
{
  return m_FixedMeshesCount;
}
void Renderable::setFixedMeshes(StaticMesh** array)
{
  m_FixedMeshes = array;
}

void Renderable::setFixedMeshesElement(unsigned int index, StaticMesh* element)
{
  m_FixedMeshes[index] = element;
}

void Renderable::setFixedMeshesCount(unsigned int count)
{
  m_FixedMeshesCount = count;
}

void Renderable::merge(const Renderable& other)
{
    mergeMaterial(other.m_Material);
    mergeFixedMeshes(other.m_FixedMeshes);
}

void Renderable::clear()
{
    clearMaterial();
    clearFixedMeshes();
}
void Renderable::mergeMaterial(Material* const otherMaterial)
{
  m_Material->merge(*otherMaterial);
}
void Renderable::mergeFixedMeshes(StaticMesh** const  otherFixedMeshes)
{
}
void Renderable::clearMaterial()
{
  m_Material->clear();
}
void Renderable::clearFixedMeshes()
{
}
//__CUSTOM_METHODS__
void Renderable::cache()
{
  //  assert(0);
}

void Renderable::uncache()
{
  //assert(0);
}


bool Renderable::render(double time, string& message)
{
  if(predraw(time, message) == false) return false;
  if(draw(time, message) == false) return false;
  if(postdraw(time, message) == false) return false;
  return true;
}

bool Renderable::predraw(double time, string& message)
{
  bool returnValue = m_Material->predraw(message);
  return returnValue;
}

bool Renderable::postdraw(double time, string& message)
{
  return m_Material->postdraw(message);	
}


//TODO Make a protected method that takes in the meshes and the material
//Make a function for drawing a single mesh that is referencial transparent
//They should be static functions
bool Renderable::draw(double time, string& message)
{
  for(uint fixedMeshIndex = 0; fixedMeshIndex < 
	m_FixedMeshesCount; fixedMeshIndex++)
    {
      //string name = mesh->getName();
      StaticMesh* mesh = m_FixedMeshes[fixedMeshIndex];
		
      char* vertices = mesh->getVertexData();
      char* indices = mesh->getIndices();
      int indexCount = mesh->getIndexCount();
		
      int streamCount = mesh->getStreamCount();
		
      for (int streamIndex = 0; streamIndex < streamCount; streamIndex++) 
	{
	  //get the attribute index
	  const char* streamName = mesh->getStreamTypeName(streamIndex);			
	  uint attributeIndex;
	  if(m_Material->getAttributeIndex(streamName, attributeIndex, 
					   message) == false){assert(0); return false;}
	  //get the attribute type
	  uint elementCount = mesh->getElementCount(streamIndex);
	  //translate to opengl enums
	  GLenum elementType = 
	    mesh->getElementType(streamIndex);
	  //get the stride
	  uint stride = mesh->getStride();
	  //get the normalize bool
	  bool normalize = mesh->getNormalize(streamIndex);
	  //adjust the start by offset
	  uint offset = mesh->getStreamOffset(streamIndex);

	  glEnableVertexAttribArray(attributeIndex);
	  if(OpenGLUtils::checkIfError(message) == false){assert(0); return false;}
	

	  glVertexAttribPointer(attributeIndex, elementCount, elementType, 
				    normalize, stride, &vertices[offset]);
	  if(OpenGLUtils::checkIfError(message) == false){assert(0); return false;}
	    
	}

      //get the type of stuff
      //get the type of the indices
      
      GLenum drawMode = mesh->getModeType();
      //glPointSize(10.5);
      //GLenum drawMode = GL_POINTS;
      GLenum indexType = mesh->getIndexType();
		
      glDrawElements(drawMode, indexCount, indexType, indices);
      if(OpenGLUtils::checkIfError(message) == false){assert(0); return false;}
		
      //disable the attributes
      for (int streamIndex = 0; streamIndex < streamCount; streamIndex++) {
	StaticMesh* mesh = m_FixedMeshes[fixedMeshIndex];
	const char* streamName = mesh->getStreamTypeName(fixedMeshIndex);			
	uint attributeIndex;
	if(m_Material->getAttributeIndex(streamName, attributeIndex, 
					 message) == false){assert(0); return false;}
			
	glDisableVertexAttribArray(attributeIndex);
	if(OpenGLUtils::checkIfError(message) == false){assert(0); return false;}
      }
		
    }
	
  return true;
}

bool Renderable::setup(string& message)
{
  return m_Material->setup(message);
}

void Renderable::deepCopy(const Renderable* copyable)
{
  Renderable* otherRenderable = (Renderable*)copyable;
  
  if(m_Material == NULL)
    {
      m_Material = new Material();
    }
  
  m_Material->deepCopy(otherRenderable->m_Material);

  
  if(m_FixedMeshesCount != otherRenderable->m_FixedMeshesCount)
    {
      if(m_FixedMeshesCount != 0)
	{
	  assert(m_FixedMeshes != NULL);
	  delete[] m_FixedMeshes;
	}
      m_FixedMeshesCount = otherRenderable->m_FixedMeshesCount;
      m_FixedMeshes = new StaticMesh*[otherRenderable->m_FixedMeshesCount];
    }

  for(uint index = 0; index < m_FixedMeshesCount; index++)
    {
      StaticMesh* currentOtherFixedMesh = otherRenderable->m_FixedMeshes[index];

      m_FixedMeshes[index] = new StaticMesh();

      m_FixedMeshes[index]->deepCopy(currentOtherFixedMesh);      
    }
}

void Renderable::destroy()
{

}
//__CUSTOM_METHODS__
