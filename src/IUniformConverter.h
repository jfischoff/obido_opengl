#ifndef IUNIFORMCONVERTER

class IUniformConverter
{
public:
    virtual bool convert(IUniform* uniform, string& message) = 0;

    const char* getName() const;
    void setName(const char* name);

private:
    string m_Name;

};

#endif
