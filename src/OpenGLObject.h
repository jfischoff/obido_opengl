#ifndef IOPENGLOBJECT_H
#define IOPENGLOBJECT_H

#include <string>

class OpenGLObject
{
    virtual bool setup(string& message);
    virtual bool teardown(string& message);

    virtual bool predraw(string& message);
    virtual bool draw(string& message);
    virtual bool postdraw(string& message);
};

#endif //IOPENGLOBJECT_H
