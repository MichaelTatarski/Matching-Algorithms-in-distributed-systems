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

void startMatching(Attribute *attribute, NameList *nameList);
NameList *setUpPredicateCounting(FilterList *subscribtions);
BoolList *predicateCounting(FilterList *subscribtions, NameList *nameList, DataModel *notification);

NameList *createNameListElement(char name[TEXT32]);
OperatorList *createOperatorListElement(Operator usedOperator);
ValueList *createValueListElement(Data value, DataType type);

NameList *doesNameReferenceExist(char name[TEXT32], NameList *nameList);
OperatorList *doesOperatorReferenceExist(Operator usedOperator, OperatorList *operatorList);
ValueList *doesValueReferenceExist(Data usedValue, ValueList *valueList, DataType type);

ValueList *lookForPredicate(Filter *filter, NameList *nameList);
ValueList *getReferenceForPredicate(Filter *filter, NameList *nameList);
ValueList *insertPredicate(Filter *filter, NameList *nameList);

#endif // PREDICATECOUNTINGALGORITHM_H