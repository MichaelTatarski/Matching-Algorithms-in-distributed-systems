#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <stdlib.h>

#include "../../lib/uthash.h"
#include "../../utility/dataType.h"

typedef struct Attribute Attribute;
typedef struct DataModel DataModel;

DataModel *dataModel_create(void);
void dataModel_addAttributeTEXT32(DataModel *dataModel, char name[TEXT32], char text[TEXT32]);
void dataModel_addAttributeINT64(DataModel *dataModel, char name[TEXT32], int64_t value);
void dataModel_addAttributeINT32(DataModel *dataModel, char name[TEXT32], int32_t value);
void dataModel_addAttributeDOUBLE(DataModel *dataModel, char name[TEXT32], double value);

DataType dataModel_getDataType(DataModel *dataModel, char name[TEXT32]);
int64_t dataModel_getValueINT64(DataModel *dataModel, char name[TEXT32]);
int32_t dataModel_getValueINT32(DataModel *dataModel, char name[TEXT32]);
double dataModel_getValueDOUBLE(DataModel *dataModel, char name[TEXT32]);
void dataModel_getValueTEXT32(DataModel *dataModel, char name[TEXT32], char returnString[TEXT32]);

#endif // DATAMODEL_H
