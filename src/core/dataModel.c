#include "dataModel.h"

Attribute *makeAttribute(char name[TEXT256])
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
}

Attribute *findAttribute(DataModel *dataModel, char name[TEXT256])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(dataModel->DataModelHead, name, returnAttribute);
    return returnAttribute;
}

DataModel *dataModel_create()
{
    DataModel *newDataModel = malloc(sizeof(DataModel));
    newDataModel->DataModelHead = NULL;
    return newDataModel;
}

DataType dataModel_getDataType(DataModel *dataModel, char name[32])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    return returnAttribute->type;
}

void dataModel_addAttributeINT64(DataModel *dataModel, char name[TEXT256], int64_t value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.INTEGER64 = value;
    newAttribute->type = INTEGER64;
    HASH_ADD_STR(dataModel->DataModelHead, Name, newAttribute);
}

int64_t getValueINT64(DataModel *dataModel, char name[TEXT256])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    return returnAttribute->data.INTEGER64;
}

void dataModel_addAttributeINT32(DataModel *dataModel, char name[TEXT256], int32_t value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.INTEGER32 = value;
    newAttribute->type = INTEGER32;
    HASH_ADD_STR(dataModel->DataModelHead, Name, newAttribute);
}

int32_t getValueINT32(DataModel *dataModel, char name[TEXT256])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    return returnAttribute->data.INTEGER32;
}

void dataModel_addAttributeDOUBLE(DataModel *dataModel, char name[TEXT256], double value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.DOUBLE = value;
    newAttribute->type = DOUBLE;
    HASH_ADD_STR(dataModel->DataModelHead, Name, newAttribute);
}

double getValueDOUBLE(DataModel *dataModel, char name[TEXT256])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    return returnAttribute->data.DOUBLE;
}

void dataModel_addAttributeTEXT32(DataModel *dataModel, char name[TEXT256], char text[TEXT32])
{
    Attribute *newAttribute = makeAttribute(name);
    strcpy(newAttribute->data.TEXT, text);
    newAttribute->type = TEXT;
    HASH_ADD_STR(dataModel->DataModelHead, Name, newAttribute);
}
void getValueTEXT32(DataModel *dataModel, char name[TEXT256], char returnString[TEXT32])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    strcpy(returnString, returnAttribute->data.TEXT);
}