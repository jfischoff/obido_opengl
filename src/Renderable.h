#ifndef RENDERABLE3_H
#define RENDERABLE3_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__
//__HEADERS__

class Material;
class StaticMesh;

class Renderable
{
  public:
    static void* Constructor();
    Renderable();
    Renderable(const Renderable& other);
    Renderable& operator=(const Renderable& other);
    ~Renderable();
    void copy(const Renderable& other);
    Renderable(Material* material, StaticMesh** fixedMeshes, unsigned int fixedMeshesCount);
//__CUSTOM_METHODS__
    bool setup(string& message); 
    bool render(double time, string& message);	
    bool predraw(double time, string& message);
    bool postdraw(double time, string& message);
    bool draw(double time, string& message);
    bool checkIfError(string& message) const;
//__CUSTOM_METHODS__
    void mergeMaterial(Material* const otherMaterial);
    void mergeFixedMeshes(StaticMesh** const otherFixedMeshes);
    void clearMaterial();
    void clearFixedMeshes();
    Material* getMaterial();
    const Material* getMaterial() const;

    void setMaterial(Material* value);

    StaticMesh** getFixedMeshes();
    StaticMesh* const * getFixedMeshes() const;

    const StaticMesh* getFixedMeshesElement(unsigned int index) const;
    StaticMesh* getFixedMeshesElement(unsigned int index);
    unsigned int getFixedMeshesCount() const;

    void setFixedMeshes(StaticMesh** array);
    void setFixedMeshesElement(unsigned int index, StaticMesh* element);
    void setFixedMeshesCount(unsigned int count);

    void cache();
    void uncache();
    virtual void deepCopy(const Renderable* copyable);
    virtual void destroy();
    void merge(const Renderable& other);
    void clear();
private:
    Material* m_Material;
    StaticMesh** m_FixedMeshes;
    unsigned int m_FixedMeshesCount;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
