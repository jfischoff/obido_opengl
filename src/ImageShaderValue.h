#ifndef IMAGESHADERVALUE_H
#define IMAGESHADERVALUE_H

#include "ShaderValue.h"
#include "ImageUniformConverter.h"
#include "Image.h"

class ImageShaderValue : public ShaderValue
{
public:
    void init();
    ImageShaderValue();

    virtual bool setup(string& message);

    virtual bool predraw(string& message);

    virtual bool convert(IUniform* uniform, string& message);
private:
    Image* m_Image;
    ImageUniformConverter m_ImageUniformConverter;
};

#endif
