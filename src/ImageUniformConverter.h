#ifndef IMAGEUNIFORMCONVERTER

#include "IUniformConverter.h"
#include <string>
class Image;

class ImageUniformConverter : public IUniformConverter
{
public:
    ImageUniformConverter();
    ImageUniformConverter(Image* image);
    ImageUniformConverter(const ImageUniformConverter& other);
    ImageUniformConverter& operator=(const ImageUniformConverter& other);
    void copy(const ImageUniformConverter& other);

    virtual bool convert(IUniform* uniform, string& message);

private:
    Image* m_Image;
};

#endif
