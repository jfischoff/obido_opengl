#include "ImageShaderValue.h"

void ImageShaderValue::init()
{
    m_ImageUniformConverter.setImage(&m_Image);
}

virtual bool ImageShaderValue::setup(string& message)
{
    return m_Image->setup(message);
}

virtual bool ImageShaderValue::predraw(string& message)
{
    return m_Image->predraw(message);
}

virtual bool ImageShaderValue::convert(IUniform* uniform, string& message)
{
    return m_ImageUniformConverter.convert(uniform, string);
}
