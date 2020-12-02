#include <stdio.h>
#include <stdlib.h>

#include "filterList.h"
#include "../core/filterModel.h"

FilterListNode *createnode(Filter filter)
{
    FilterListNode *newNode = malloc(sizeof(FilterListNode));
    newNode->filter = &filter;
    newNode->next = NULL;
    return newNode;
}

void filterList_add(Filter filter, FilterListNode *filterList)
{
    FilterListNode *current = NULL;
    if (filterList == NULL)
    {
        filterList = createnode(filter);
    }
    else
    {
        current = filterList;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = createnode(filter);
    }
}

void filterList_delete(Filter filter, FilterListNode *filterList)
{
    FilterListNode *current = filterList;
    FilterListNode *previous = current;
    while (current != NULL)
    {
        if (current->filter == &filter)
        {
            previous->next = current->next;
            if (current == filterList)
                filterList = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
