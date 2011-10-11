#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <string>
using namespace std;

enum PrimitiveEType
  {
    BOOL,
    CHAR,
    UCHAR,
    BYTE,
    UBYTE,
    SHORT,
    USHORT,
    INT,
    UINT,
    FLOAT,
    DOUBLE,
    LONG,
    ULONG,
    POINTER,
    MAX_ETYPE,
    INVALID_ETYPE
  };

string convertPrimitiveETypeToString(PrimitiveEType eType);
PrimitiveEType convertEnumStringToPrimitiveEType(string primitiveName);
unsigned int getPrimitiveETypeCount();

unsigned int getPrimitiveSize(PrimitiveEType eType);



#endif //PRIMITIVEENUMS_H
