#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__
//__HEADERS__

class Stream;
class StructSizeDescription;

class Image
{
  public:
    static void* Constructor();
    Image();
    Image(const Image& other);
    Image& operator=(const Image& other);
    ~Image();
    void copy(const Image& other);
    Image(unsigned int width, unsigned int height, int textureId, Stream* pixels, StructSizeDescription* structSizeDescription);
//__CUSTOM_METHODS__
    const void* getPixel(unsigned int widthIndex, unsigned int heightIndex) const;
    bool setup(string& message);
    
//__CUSTOM_METHODS__
    void mergeWidth(const unsigned int& otherWidth);
    void mergeHeight(const unsigned int& otherHeight);
    void mergeTextureId(const int& otherTextureId);
    void mergePixels(Stream* const otherPixels);
    void mergeStructSizeDescription(StructSizeDescription* const otherStructSizeDescription);
    void clearWidth();
    void clearHeight();
    void clearTextureId();
    void clearPixels();
    void clearStructSizeDescription();
    unsigned int getWidth();
    const unsigned int getWidth() const;

    void setWidth(unsigned int value);

    unsigned int getHeight();
    const unsigned int getHeight() const;

    void setHeight(unsigned int value);

    int getTextureId();
    const int getTextureId() const;

    void setTextureId(int value);

    Stream* getPixels();
    const Stream* getPixels() const;

    void setPixels(Stream* value);

    StructSizeDescription* getStructSizeDescription();
    const StructSizeDescription* getStructSizeDescription() const;

    void setStructSizeDescription(StructSizeDescription* value);

    virtual void deepCopy(const Image* copyable);
    virtual void destroy();
    void merge(const Image& other);
    void clear();
private:
    unsigned int m_Width;
    unsigned int m_Height;
    int m_TextureId;
    Stream* m_Pixels;
    StructSizeDescription* m_StructSizeDescription;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
