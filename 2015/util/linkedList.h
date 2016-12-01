//
// Created by Jonas on 04.01.2016.
//

#ifndef ADVENTOFCODEC_LINKEDLIST_H
#define ADVENTOFCODEC_LINKEDLIST_H

typedef struct Element {
    void *value;
    struct Element *next;
} Element;

typedef struct {
    Element *firstElement;
    Element *lastElement;
} LinkedList;

LinkedList *createLinkedList();
LinkedList *duplicateLinkedList(LinkedList *list);
void add(LinkedList *list, void *value);
void append(LinkedList *list, void *value);
int length(LinkedList *list);
void freeLinkedList(LinkedList *list);

#endif //ADVENTOFCODEC_LINKEDLIST_H
