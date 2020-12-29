// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "dataModel.h"

Attribute *makeAttribute(char name[TEXT32])
{
    Attribute *newAttribute = malloc(sizeof(Attribute));
    strcpy(newAttribute->Name, name);
}

Attribute *findAttribute(DataModel *dataModel, char name[TEXT32])
{
    Attribute *returnAttribute;
    HASH_FIND_STR(dataModel->DataModelHead, name, returnAttribute);
    return returnAttribute;
}

DataModel *dataModel_create(void)
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

void dataModel_addAttributeINT64(DataModel *dataModel, char name[TEXT32], int64_t value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.INTEGER64 = value;
    newAttribute->type = INTEGER64;
    HASH_ADD_STR(dataModel->DataModelHead, Name, newAttribute);
}

int64_t dataModel_getValueINT64(DataModel *dataModel, char name[TEXT32])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    return returnAttribute->data.INTEGER64;
}

void dataModel_addAttributeINT32(DataModel *dataModel, char name[TEXT32], int32_t value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.INTEGER32 = value;
    newAttribute->type = INTEGER32;
    HASH_ADD_STR(dataModel->DataModelHead, Name, newAttribute);
}

int32_t dataModel_getValueINT32(DataModel *dataModel, char name[TEXT32])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    return returnAttribute->data.INTEGER32;
}

void dataModel_addAttributeDOUBLE(DataModel *dataModel, char name[TEXT32], double value)
{
    Attribute *newAttribute = makeAttribute(name);
    newAttribute->data.DOUBLE = value;
    newAttribute->type = DOUBLE;
    HASH_ADD_STR(dataModel->DataModelHead, Name, newAttribute);
}

double dataModel_getValueDOUBLE(DataModel *dataModel, char name[TEXT32])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    return returnAttribute->data.DOUBLE;
}

void dataModel_addAttributeTEXT32(DataModel *dataModel, char name[TEXT32], char text[TEXT32])
{
    Attribute *newAttribute = makeAttribute(name);
    strcpy(newAttribute->data.TEXT, text);
    newAttribute->type = TEXT;
    HASH_ADD_STR(dataModel->DataModelHead, Name, newAttribute);
}
void dataModel_getValueTEXT32(DataModel *dataModel, char name[TEXT32], char returnString[TEXT32])
{
    Attribute *returnAttribute = findAttribute(dataModel, name);
    strcpy(returnString, returnAttribute->data.TEXT);
}