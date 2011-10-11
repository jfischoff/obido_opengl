#include "Image.h"
#include <Stream.h>
#include <StructSizeDescription.h>
//__HEADERS__
//__HEADERS__
void* Image::Constructor()
{
  return new Image();
}

Image::Image()
{
    m_Pixels = NULL;
    m_StructSizeDescription = NULL;
//__CUSTOM_INIT__
//__CUSTOM_INIT__

}

Image::Image(const Image& other)
{
  copy(other);
}

Image& Image::operator=(const Image& other)
{
  copy(other);
  return *this;
}

void Image::copy(const Image& other)
{
  m_Width = other.m_Width;
  m_Height = other.m_Height;
  m_TextureId = other.m_TextureId;
  m_Pixels = other.m_Pixels;
  m_StructSizeDescription = other.m_StructSizeDescription;
}

Image::~Image()
{
}

Image::Image(unsigned int width, unsigned int height, int textureId, Stream* pixels, StructSizeDescription* structSizeDescription)
{
    m_Width = width;
    m_Height = height;
    m_TextureId = textureId;
    m_Pixels = pixels;
    m_StructSizeDescription = structSizeDescription;
}
unsigned int Image::getWidth()
{
  return m_Width;
}

const unsigned int Image::getWidth() const
{
  return m_Width;
}

void Image::setWidth(unsigned int value)
{
  m_Width = value;
}
unsigned int Image::getHeight()
{
  return m_Height;
}

const unsigned int Image::getHeight() const
{
  return m_Height;
}

void Image::setHeight(unsigned int value)
{
  m_Height = value;
}
int Image::getTextureId()
{
  return m_TextureId;
}

const int Image::getTextureId() const
{
  return m_TextureId;
}

void Image::setTextureId(int value)
{
  m_TextureId = value;
}
Stream* Image::getPixels()
{
  return m_Pixels;
}

const Stream* Image::getPixels() const
{
  return m_Pixels;
}

void Image::setPixels(Stream* value)
{
  m_Pixels = value;
}
StructSizeDescription* Image::getStructSizeDescription()
{
  return m_StructSizeDescription;
}

const StructSizeDescription* Image::getStructSizeDescription() const
{
  return m_StructSizeDescription;
}

void Image::setStructSizeDescription(StructSizeDescription* value)
{
  m_StructSizeDescription = value;
}
void Image::merge(const Image& other)
{
    mergeWidth(other.m_Width);
    mergeHeight(other.m_Height);
    mergeTextureId(other.m_TextureId);
    mergePixels(other.m_Pixels);
    mergeStructSizeDescription(other.m_StructSizeDescription);
}

void Image::clear()
{
    clearWidth();
    clearHeight();
    clearTextureId();
    clearPixels();
    clearStructSizeDescription();
}
void Image::mergeWidth(const unsigned int& otherWidth)
{
}
void Image::mergeHeight(const unsigned int& otherHeight)
{
}
void Image::mergeTextureId(const int& otherTextureId)
{
}
void Image::mergePixels(Stream* const otherPixels)
{
  m_Pixels->merge(*otherPixels);
}
void Image::mergeStructSizeDescription(StructSizeDescription* const otherStructSizeDescription)
{
  m_StructSizeDescription->merge(*otherStructSizeDescription);
}
void Image::clearWidth()
{
}
void Image::clearHeight()
{
}
void Image::clearTextureId()
{
}
void Image::clearPixels()
{
  m_Pixels->clear();
}
void Image::clearStructSizeDescription()
{
  m_StructSizeDescription->clear();
}
//__CUSTOM_METHODS__

const void* Image::getPixel(unsigned int widthIndex, unsigned int heightIndex) const
{
  unsigned int width = getWidth();
  unsigned int height = getHeight();
  unsigned int pixelIndex = (widthIndex * height) + heightIndex;
  return m_Pixels->get(pixelIndex);
}

bool Image::setup(string& message)
{
    glGenTextures(1, &m_TextureId);

    unsigned int componentCount = 4;
    unsigned int width = currentImage->getWidth();
    unsigned int height = currentImage->getHeight();

    void* data = currentImage->getPixels()->getBuffer();

    CHECK_ERROR_AND_RETURN(message);
    glBindTexture(GL_TEXTURE_2D, m_TextureId);
    CHECK_ERROR_AND_RETURN(message);
    glTexImage2D(
		   GL_TEXTURE_2D,
		   0,
		   componentCount, // should get this from the texture
		   width,
		   height,
		   0, //not really sure why I would want to set this
		   GL_RGBA,
		   GL_UNSIGNED_BYTE, // there should be a conversion format for this
		   data);
    CHECK_ERROR_AND_RETURN(message);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	// Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //glGenerateMipmapEXT(GL_TEXTURE_2D);  //Generate mipmaps now!!!

    return true;
}

void Image::deepCopy(const Image* copyable)
{
  Image* otherImage = (Image*)copyable;
  m_Width = otherImage->m_Width;
  m_Height = otherImage->m_Height;
  if(m_Pixels == NULL)
    {
      m_Pixels = new Stream();
    }
  m_Pixels->deepCopy(otherImage->m_Pixels);
  m_StructSizeDescription = otherImage->m_StructSizeDescription;
  m_TextureId = otherImage->m_TextureId;
}

void Image::destroy()
{

}
//__CUSTOM_METHODS__
