#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "../utility/uthash.h"
#include "../utility/dataType.h"

// necessary to make struct hashable (please read https://troydhanson.github.io/uthash/ for reference)

typedef struct Attribute
{

    char *Name[32];
    Data data;
    DataType type;
    UT_hash_handle hh;

} Attribute;

int getDataType(char name[32]);

void dataModel_createAttributeINT64(char name[32], int64_t value);
int64_t getValueINT64(char name[32]);

void dataModel_createAttributeINT32(char name[32], int32_t value);
int32_t getValueINT32(char name[32]);

void dataModel_createAttributeDOUBLE(char name[32], double value);
double getValueDOUBLE(char name[32]);

void dataModel_createAttributeTEXT32(char name[32], char *text[32]);
char getValueTEXT32(char name[32]);

#endif // DATAMODEL_H
