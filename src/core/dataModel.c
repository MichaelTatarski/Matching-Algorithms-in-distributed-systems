#include <stdlib.h>
#include "dataModel.h"

Attribute *MakeAttributeHashable = NULL;

int getDataType(char name[32])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->type;
}

void dataModel_createAttributeINT64(char name[32], int64_t value)
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
    newAttribute->data.INTEGER64 = value;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

int64_t getValueINT64(char name[32])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->data.INTEGER64;
}

void dataModel_createAttributeINT32(char name[32], int32_t value)
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
    newAttribute->data.INTEGER32 = value;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

int32_t getValueINT32(char name[32])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->data.INTEGER32;
}

void dataModel_createAttributeDOUBLE(char name[32], double value)
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
    newAttribute->data.DOUBLE = value;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

double getValueDOUBLE(char name[32])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->data.DOUBLE;
}

void dataModel_createAttributeTEXT32(char name[32], char *text[32])
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
    strcpy(newAttribute->data.TEXT32, text);
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}
char getValueTEXT32(char name[32])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->data.TEXT32;
}