#ifndef MATCHINGLIST_H
#define MATCHINGLIST_H

#include <stdbool.h>

#include "../core/filterModel.h"

typedef struct Node
{
    Filter *filter;
    bool isMatching;
    struct Node *next;

} Node;

void matchingList_add(Filter filter, bool isMatching, Node *matchingList);

#endif // MATCHINGLIST_H
