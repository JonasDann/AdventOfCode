//
// Created by Jonas on 04.01.2016.
//

#include <windef.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList *createLinkedList() {
    LinkedList *result = malloc(sizeof(LinkedList));
    result->firstElement = 0;
    result->lastElement = 0;
    return result;
}

LinkedList *duplicateLinkedList(LinkedList *list) {
    LinkedList *result = createLinkedList();
    Element *e = list->firstElement;
    while(e != 0) {
        append(result, e->value);
        e = e->next;
    }
    return result;
}

void add(LinkedList *list, void *value) {
    Element *element = malloc(sizeof(Element));
    element->value = value;
    element->next = list->firstElement;
    list->firstElement = element;
    if (list->lastElement == 0) {
        list->lastElement = element;
    }
}

void append(LinkedList *list, void *value) {
    Element *element = malloc(sizeof(Element));
    element->value = value;
    element->next = 0;
    if (list->firstElement == 0) {
        list->firstElement = element;
    } else {
        list->lastElement->next = element;
    }
    list->lastElement = element;
}

int length(LinkedList *list) {
    int length = 0;
    Element *e = list->firstElement;
    while(e != 0) {
        length++;
        e = e->next;
    }
    return length;
}

void freeLinkedList(LinkedList *list) {
    Element *element = list->firstElement;
    while(element != 0) {
        Element *next = element->next;
        free(element);
        element = next;
    }
    free(list);
}