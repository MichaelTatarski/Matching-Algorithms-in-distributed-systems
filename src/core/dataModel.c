#include <stdlib.h>
#include "dataModel.h"

DataSet dataSet_Create(int id, int value, int errorcode)
{
    DataSet newDataSet = malloc(sizeof(DataSet));
    newDataSet->lookupArray[ID] = id;
    newDataSet->lookupArray[VALUE] = value;
    newDataSet->lookupArray[ERRORCODE] = errorcode;
    return newDataSet;
}

int *getValue(DataSet dataset, key key)
{
    return dataset->lookupArray[key];
}