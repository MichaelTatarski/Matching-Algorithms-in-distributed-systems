#include <stdio.h>
#include <stdlib.h>

#include "filterList.h"
#include "../core/filterModel.h"

Node *createnode(Filter filter)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->filter = &filter;
    newNode->next = NULL;
    return newNode;
}

FilterList *make_filterList()
{
    FilterList *filterList = malloc(sizeof(FilterList));
    filterList->head = NULL;
    return filterList;
}

void filter_add(Filter filter, FilterList *filterList)
{
    Node *current = NULL;
    if (filterList->head == NULL)
    {
        filterList->head = createnode(filter);
    }
    else
    {
        current = filterList->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = createnode(filter);
    }
}

void filter_delete(Filter filter, FilterList *filterList)
{
    Node *current = filterList->head;
    Node *previous = current;
    while (current != NULL)
    {
        if (current->filter == &filter)
        {
            previous->next = current->next;
            if (current == filterList->head)
                filterList->head = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
