#ifndef BRUTEFORCEALGORITHM_H
#define BRUTEFORCEALGORITHM_H

#include "dataModel.h"
#include "../utility/filterList.h"

/**
 * checks each filter if it matches the dataset.
 *
 * @param dataSet corresponding dataset.
 * @param filterListHead List of filters.
 * @return a list of booleans that represent whether or not the filters of the filterlist match the dataset.
 */
MatchingList ismatching(DataSet dataSet, Node filterListHead);

#endif // BRUTEFORCEALGORITHM_H
