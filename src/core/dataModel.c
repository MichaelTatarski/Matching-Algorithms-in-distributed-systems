#include "dataModel.h"

Attribute *MakeAttributeHashable = NULL;

int getDataType(char name[32])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->type;
}

void dataModel_addAttributeINT64(char name[TEXT256], int64_t value)
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
    newAttribute->data.INTEGER64 = value;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

int64_t getValueINT64(char name[TEXT256])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->data.INTEGER64;
}

void dataModel_addAttributeINT32(char name[TEXT256], int32_t value)
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
    newAttribute->data.INTEGER32 = value;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

int32_t getValueINT32(char name[TEXT256])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->data.INTEGER32;
}

void dataModel_addAttributeDOUBLE(char name[TEXT256], double value)
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
    newAttribute->data.DOUBLE = value;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

double getValueDOUBLE(char name[TEXT256])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute->data.DOUBLE;
}

void dataModel_addAttributeTEXT32(char name[TEXT256], char text[TEXT32])
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
    strcpy(newAttribute->data.TEXT, text);
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}
void getValueTEXT32(char name[TEXT256], char *returnString[TEXT32])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    strcpy(returnString, returnAttribute->data.TEXT);
}