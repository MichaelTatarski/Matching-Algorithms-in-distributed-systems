#ifndef PREDICATECOUNTINGALGORITHM_H
#define PREDICATECOUNTINGALGORITHM_H

#include <stdlib.h>
#include <string.h>

#include "../dataModel/dataModel.h"
#include "../../lib/utlist.h"
#include "../../utility/dataType.h"
#include "../../utility/logicalExpressions.h"
#include "predicateCountingDataStructure.h"
#include "../filterModel/filterModel.h"
#include "../filterModel/filterList.h"

NameList *setUpPredicateCounting(FilterList *subscribtions);
BoolList *predicateCounting(FilterList *subscribtions, NameList *nameList, DataModel *notification);

#endif // PREDICATECOUNTINGALGORITHM_H