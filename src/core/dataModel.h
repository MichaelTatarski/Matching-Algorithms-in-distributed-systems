#ifndef DATAMODEL_H
#define DATAMODEL_H

#define LOOKUPARRAY_SIZE 3

typedef enum
{
    ID,
    VALUE,
    ERRORCODE
} key;

typedef struct
{
    int lookupArray[LOOKUPARRAY_SIZE];
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
int *getValue(DataSet dataset, key key);

#endif // DATAMODEL_H
