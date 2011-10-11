#ifndef UNIFORMMAPPERNODE_H
#define UNIFORMMAPPERNODE_H

#include "IUniformMapper.h"
#include "UniformMapper.h"


//This collects all the unmapped parts of its children
//and adds it to its own uniform mapper

//you can also access the children

class UniformMapperNode : public IUniformMapper
{
public:
    
private:
    vector<IUniformMapper*> m_Children;
    UniformMapper* m_UniformMapper;
};

#endif UNIFORMMAPPERNODE_H
