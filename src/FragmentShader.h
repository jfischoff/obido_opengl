#ifndef FRAGMENTSHADER2_H
#define FRAGMENTSHADER2_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__
#include "BaseShader.h"
//__HEADERS__


class FragmentShader: public BaseShader
{
  public:
    static void* Constructor();
    FragmentShader();
    FragmentShader(const FragmentShader& other);
    FragmentShader& operator=(const FragmentShader& other);
    ~FragmentShader();
    void copy(const FragmentShader& other);
//__CUSTOM_METHODS__
    static void* Create();
//__CUSTOM_METHODS__
    void cache();
    void uncache();
    void merge(const FragmentShader& other);
    void clear();
private:
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
