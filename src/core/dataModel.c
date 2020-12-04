#include "dataModel.h"

Attribute *MakeAttributeHashable = NULL;

Attribute *makeAttribute(char name[TEXT256])
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
}

Attribute *findAttribute(char name[TEXT256])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(MakeAttributeHashable, name, returnAttribute);
    return returnAttribute;
}

DataModel *dataModel_create()
{
    DataModel *newDataModel = malloc(sizeof(DataModel));
    newDataModel->DataModelHead = NULL;
    return newDataModel;
}

DataType getDataType(char name[32])
{
    Attribute *returnAttribute = findAttribute(name);
    return returnAttribute->type;
}

void dataModel_addAttributeINT64(char name[TEXT256], int64_t value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.INTEGER64 = value;
    newAttribute->type = INTEGER64;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

int64_t getValueINT64(char name[TEXT256])
{
    Attribute *returnAttribute = findAttribute(name);
    return returnAttribute->data.INTEGER64;
}

void dataModel_addAttributeINT32(char name[TEXT256], int32_t value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.INTEGER32 = value;
    newAttribute->type = INTEGER32;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

int32_t getValueINT32(char name[TEXT256])
{
    Attribute *returnAttribute = findAttribute(name);
    return returnAttribute->data.INTEGER32;
}

void dataModel_addAttributeDOUBLE(char name[TEXT256], double value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.DOUBLE = value;
    newAttribute->type = DOUBLE;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}

double getValueDOUBLE(char name[TEXT256])
{
    Attribute *returnAttribute = findAttribute(name);
    return returnAttribute->data.DOUBLE;
}

void dataModel_addAttributeTEXT32(char name[TEXT256], char text[TEXT32])
{
    Attribute *newAttribute = makeAttribute(name);
    strcpy(newAttribute->data.TEXT, text);
    newAttribute->type = TEXT;
    HASH_ADD_STR(MakeAttributeHashable, Name, newAttribute);
}
void getValueTEXT32(char name[TEXT256], char returnString[TEXT32])
{
    Attribute *returnAttribute = findAttribute(name);
    strcpy(returnString, returnAttribute->data.TEXT);
}