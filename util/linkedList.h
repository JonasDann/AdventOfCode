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
} LinkedList;

LinkedList * createLinkedList();
void add(LinkedList *list, void *value);
void freeLinkedList(LinkedList *list);

#endif //ADVENTOFCODEC_LINKEDLIST_H
