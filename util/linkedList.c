//
// Created by Jonas on 04.01.2016.
//

#include <windef.h>
#include <stdlib.h>
#include "linkedList.h"

void add(LinkedList *list, void *value) {
    Element *element = malloc(sizeof(Element));
    element->value = value;
    element->next = list->firstElement;
    list->firstElement = element;
}

LinkedList *createLinkedList() {
    LinkedList *result = malloc(sizeof(LinkedList));
    result->firstElement = 0;
    return result;
}

void freeLinkedList(LinkedList *list) {
    Element *element = list->firstElement;
    while(element != 0) {
        free(element);
        element = element->next;
    }
    free(list);
}
