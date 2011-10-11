#include "Primitive.h"
#include <assert.h>

string convertPrimitiveETypeToString(PrimitiveEType eType)
{
  switch(eType)
    {
    case BOOL:
      return "bool";
    case CHAR:
      return "char";
    case UCHAR:
      return "uchar";
    case BYTE:
      return "byte";
    case UBYTE:
      return "ubyte";
    case SHORT:
      return "short";
    case USHORT:
      return "ushort";
    case INT:
      return "int";
    case UINT:
      return "unsigned int";
    case FLOAT:
      return "float";
    case DOUBLE:
      return "double";
    case LONG:
      return "long";
    case ULONG:
      return "ulong";
    case POINTER:
      return "pointer";
    default:
      assert(0);
      return "error";
      
    }

}

PrimitiveEType convertEnumStringToPrimitiveEType(string primitiveName)
{
  if(primitiveName == "bool")
    {
      return BOOL;
    }
  else if(primitiveName == "char")
    {
      return CHAR;
    }
 else if(primitiveName == "uchar")
    {
      return UCHAR;
    }  
 else if(primitiveName == "byte")
    {
      return BYTE;
    }
 else if(primitiveName == "ubyte")
    {
      return UBYTE;
    }
 else if(primitiveName == "short")
    {
      return SHORT;
    }
 else if(primitiveName == "ushort")
    {
      return USHORT;
    }
 else if(primitiveName == "int")
    {
      return INT;
    }
 else if(primitiveName == "unsigned int")
    {
      return UINT;
    }
 else if(primitiveName == "float")
    {
      return FLOAT;
    }
 else if(primitiveName == "double")
    {
      return DOUBLE;
    }
 else if(primitiveName == "long")
    {
      return LONG;
    }
 else if(primitiveName == "ulong")
    {
      return ULONG;
    }
 else if(primitiveName == "pointer")
    {
      return POINTER;
    }
  else
    {
      assert(0);
      return INVALID_ETYPE;
    }
}

unsigned int getPrimitiveETypeCount()
{ 
  return (unsigned int)MAX_ETYPE;
}

unsigned int getPrimitiveSize(PrimitiveEType eType)
{
  switch(eType)
    {
    case BOOL:
      return sizeof(bool);
    case BYTE:
      return sizeof(char);
    case UBYTE:
      return sizeof(unsigned char);
    case CHAR:
      return sizeof(char);
    case UCHAR:
      return sizeof(unsigned char);
    case SHORT:
      return sizeof(short);
    case USHORT:
      return sizeof(unsigned short);
    case INT:
      return sizeof(int);
    case UINT:
      return sizeof(unsigned int);
    case FLOAT:
      return sizeof(float);
    case DOUBLE:
      return sizeof(double);
    case LONG:
      return sizeof(long);
    case ULONG:
      return sizeof(unsigned long);
    case POINTER:
      return sizeof(void*);
    default:
      assert(0);
      return -1;
    }
}
