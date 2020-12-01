#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "keys.h"

/**equals the number of possible keys (counted manually, keep these in sync).*/
#define KEY_NUMBER 3

typedef struct DataSet
{
    int lookupArray[KEY_NUMBER];

} * DataSet;

/**
 * Create a new dataset.
 *
 * @param id ID of the new dataset.
 * @param value Value of the new dataset.
 * @param errorcode ERRORCODE of the new dataset.
 * @return new dataset.
 */
DataSet dataSet_Create(int id, int value, int errorcode);

/**
 * Access the value for a given key in the lookuparray of a dataset.
 *
 * @param dataset dataset in which the value should be accessed.
 * @param key key to which the value should be returned.
 * @return value of the given key.
 */
int dataSet_getValue(DataSet dataSet, Key key);

#endif // DATAMODEL_H
