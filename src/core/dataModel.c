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

int dataSet_getValue(DataSet dataSet, Key key)
{
    return dataSet->lookupArray[key];
}