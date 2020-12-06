#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <stdlib.h>

#include "../utility/uthash.h"
#include "../utility/dataType.h"

// necessary to make struct hashable (please read https://troydhanson.github.io/uthash/ for reference)

typedef struct Attribute
{

    char Name[TEXT256];
    Data data;
    DataType type;
    UT_hash_handle hh;

} Attribute;

typedef struct DataModel
{
    Attribute *DataModelHead;

} DataModel;

DataModel *dataModel_create(void);

DataType attribute_getDataType(DataModel *dataModel, char name[TEXT256]);

void dataModel_addAttributeINT64(DataModel *dataModel, char name[TEXT256], int64_t value);
int64_t attribute_getValueINT64(DataModel *dataModel, char name[TEXT256]);

void dataModel_addAttributeINT32(DataModel *dataModel, char name[TEXT256], int32_t value);
int32_t attribute_getValueINT32(DataModel *dataModel, char name[TEXT256]);

void dataModel_addAttributeDOUBLE(DataModel *dataModel, char name[TEXT256], double value);
double attribute_getValueDOUBLE(DataModel *dataModel, char name[TEXT256]);

void dataModel_addAttributeTEXT32(DataModel *dataModel, char name[TEXT256], char text[TEXT32]);
void attribute_getValueTEXT32(DataModel *dataModel, char name[TEXT256], char returnString[TEXT32]);

#endif // DATAMODEL_H
