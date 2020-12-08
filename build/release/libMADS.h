#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <stdint.h>

#define TEXT32 32

typedef union Data
{
    int64_t INTEGER64;
    int32_t INTEGER32;
    double DOUBLE;
    char TEXT[TEXT32];
} Data;

typedef enum DataType
{
    INTEGER64,
    INTEGER32,
    DOUBLE,
    TEXT
} DataType;

#endif //DATA_TYPE_H
#ifndef LOGIC_EXPRESSIONS_H
#define LOGIC_EXPRESSIONS_H

typedef enum Operator
{
    GREATER_THAN,
    GREATER_EQUAL,
    SMALLER_THAN,
    SMALLER_EQUAL,
    EQUALS

} Operator;

#endif // LOGIC_EXPRESSIONS_H
#ifndef DATAMODEL_H
#define DATAMODEL_H

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
#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <stdlib.h>
#include <string.h>

typedef struct Filter Filter;

Filter *filter_create(void);
void filter_addSubFilterINT64(Filter *filter, char name[TEXT32], Operator constraintOperator, int64_t constraintValue);
void filter_addSubFilterINT32(Filter *filter, char name[TEXT32], Operator constraintOperator, int32_t constraintValue);
void filter_addSubFilterDOUBLE(Filter *filter, char name[TEXT32], Operator constraintOperator, double constraintValue);
void filter_addSubFilterTEXT32(Filter *filter, char name[TEXT32], Operator constraintOperator, char constraintValue[32]);

#endif // FILTERMODEL_H
#ifndef FILTERLIST_H
#define FILTERLIST_H

#include <stdlib.h>

typedef struct FilterList FilterList;

FilterList *filterList_create(void);
void filterList_addFilter(FilterList *filterList, Filter *filter);

#endif // FILTERLIST_H
