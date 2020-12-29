#include <stdio.h>
#include <string.h>
#include "../dataModel/dataModel.h"
#include "../filterModel/filterModel.h"

#define BUFFER_SIZE 1024

typedef struct dataModel_csvEntry{
    char *attribute;
    char *value;
    char *dataType;
} dataModel_csvEntry;

typedef struct filterModel_csvEntry{
    char *attribute;
    char *operator;
    char *value;
} filterModel_csvEntry;

void dataModel_importFromCsv(DataModel *dataModel, char *filePath) {
    char buf[BUFFER_SIZE];
    FILE *file;
    file = fopen(filePath, "r");

    dataModel_csvEntry entry;

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
}

void filterModel_importFromCsv(Filter *filter, char *filePath) {
    char buf[BUFFER_SIZE];
    FILE *file;
    file = fopen(filePath, "r");

    filterModel_csvEntry entry;

    if (file) {
        while (fgets(buf, sizeof(buf), file) != NULL) { // iterates over every line of a CSV-FILE
            char *tok = strtok(buf, ";");
            Operator anOperator = EQUALS;
            entry.attribute = tok;
            tok = strtok(NULL, ";");
            entry.operator = tok;
            tok = strtok(NULL, ";");
            entry.value = tok;

            if (!strcmp(entry.operator, "<")) {
                anOperator = SMALLER_THAN;
            }

            if (!strcmp(entry.operator, "<=")) {
                anOperator = SMALLER_EQUAL;
            }

            if (!strcmp(entry.operator, ">=")) {
                anOperator = GREATER_EQUAL;
            }

            if (!strcmp(entry.operator, ">")) {
                anOperator = GREATER_THAN;
            }

            if (!strcmp(entry.attribute, "VendorID") || !strcmp(entry.attribute, "SensorID") || !strcmp(entry.attribute, "Timestamp")) {
                filter_addSubFilterINT64(filter, entry.attribute, anOperator, atoi(entry.value));
            }

            if (!strcmp(entry.attribute, "Unit")) {
                filter_addSubFilterINT32(filter, entry.attribute, anOperator, atoi(entry.value));
            }

            if (!strcmp(entry.attribute, "Temperature")) {
                filter_addSubFilterDOUBLE(filter, entry.attribute, anOperator, atof(entry.value));
            }

            if (!strcmp(entry.attribute, "SensorLabel") || !strcmp(entry.attribute, "Building") || !strcmp(entry.attribute, "Floor") || !strcmp(entry.attribute, "Room")) {
                filter_addSubFilterTEXT32(filter, entry.attribute, EQUALS, entry.value);
            }
        }
    }
}
