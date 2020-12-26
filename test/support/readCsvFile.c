#include <stdio.h>
#include <string.h>
#include "libMADS.h"

#define BUFFER_SIZE 1024

typedef struct csvEntry{
    char *attribute;
    char *value;
    char *dataType;
} CsvEntry;

int main() {
    char buf[BUFFER_SIZE];
    FILE *file;

    file = fopen("../../test_data.csv", "r");

    CsvEntry entry;

    DataModel *dataModel =  dataModel_create();

    if (file) {
        while (fgets(buf, sizeof(buf), file) != NULL) { // iterates over every line of a CSV-FILE
            char *tok = strtok(buf, ";");
            entry.attribute = tok;
            tok = strtok(NULL, ";");
            entry.value = tok;
            tok = strtok(NULL, ";");
            entry.dataType = tok;

            if (!strcmp(entry.attribute, "VendorID") || !strcmp(entry.attribute, "SensorID") || !strcmp(entry.attribute, "Timestamp")) {
                dataModel_addAttributeINT64(dataModel, entry.attribute, atoi(entry.value));
            }

            if (!strcmp(entry.attribute, "Unit")) {
                dataModel_addAttributeINT32(dataModel, entry.attribute, atoi(entry.value));
            }

            if (!strcmp(entry.attribute, "Temperature")) {
                dataModel_addAttributeDOUBLE(dataModel, entry.attribute, atof(entry.value));
            }

            if (!strcmp(entry.attribute, "SensorLabel") || !strcmp(entry.attribute, "Building") || !strcmp(entry.attribute, "Floor") || !strcmp(entry.attribute, "Room")) {
                dataModel_addAttributeTEXT32(dataModel, entry.attribute, entry.value);
            }
        }
    }

    char returnString[32];
    dataModel_getValueTEXT32(dataModel, "Floor", returnString);

    printf("%li ", dataModel_getValueINT64(dataModel, "VendorID"));
    printf("%li ", dataModel_getValueINT64(dataModel, "SensorID"));
    printf("%i ", dataModel_getValueINT32(dataModel, "Unit"));
    printf("%s ", returnString);

    return 0;
}
