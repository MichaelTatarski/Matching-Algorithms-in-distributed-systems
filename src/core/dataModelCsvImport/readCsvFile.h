#ifndef DATAMODELCSVIMPORT_H
#define DATAMODELCSVIMPORT_H

#include <stdlib.h>
#include "../dataModel/dataModel.h"
#include "../filterModel/filterModel.h"


void dataModel_importFromCsv(DataModel *dataModel, char *filePath);
void filterModel_importFromCsv(Filter *filter, char *filePath);

#endif // DATAMODELCSVIMPORT_H
