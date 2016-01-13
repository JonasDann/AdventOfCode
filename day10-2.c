//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "util/linkedList.h"

const int ARRAY_LENGTH = 50000;

int main(int argc, char *argv[]) {
    char *input = "1113222113";

    clock_t t1, t2;

    t1 = clock();

    int i = 0;
    LinkedList *result = createLinkedList();
    append(result, malloc(ARRAY_LENGTH * sizeof(int8_t)));
    Element *e = result->firstElement;
    int f = 0;
    while(input[i] != '\0') {
        ((int8_t *)e->value)[f] = (int8_t) (input[i] - 48);
        i++; f++;
    }
    ((int8_t *)e->value)[f] = 0;
    LinkedList *new = createLinkedList();
    append(new, malloc(ARRAY_LENGTH * sizeof(int8_t)));
    LinkedList *swap;
    Element *n;
    int m;
    int8_t last, count;
    for (i = 0; i < 50; i++) {
        e = result->firstElement;
        f = 0;
        n = new->firstElement;
        m = 0;
        if (e != 0) {
            last = ((int8_t *)e->value)[f]; count = 0;
            f++;
            while (e != 0 && ((int8_t *)e->value)[f] != 0) {
                count++;
                if (((int8_t *)e->value)[f] != last) {
                    if (m >= ARRAY_LENGTH) {
                        n = n->next;
                        if (n == 0) {
                            append(new, malloc(ARRAY_LENGTH * sizeof(int8_t)));
                            n = new->lastElement;
                        }
                        m = 0;
                    }
                    ((int8_t *)n->value)[m] = count;
                    m++;
                    if (m >= ARRAY_LENGTH) {
                        n = n->next;
                        if (n == 0) {
                            append(new, malloc(ARRAY_LENGTH * sizeof(int8_t)));
                            n = new->lastElement;
                        }
                        m = 0;
                    }
                    ((int8_t *)n->value)[m] = last;
                    m++;
                    count = 0;
                    last = ((int8_t *) e->value)[f];
                }
                f = ++f < ARRAY_LENGTH ? f : 0;
                if (f == 0) {
                    e = e->next;
                }
            }
            count++;
            if (m >= ARRAY_LENGTH) {
                n = n->next;
                if (n == 0) {
                    append(new, malloc(ARRAY_LENGTH * sizeof(int8_t)));
                    n = new->lastElement;
                }
                m = 0;
            }
            ((int8_t *)n->value)[m] = count;
            m++;
            if (m >= ARRAY_LENGTH) {
                n = n->next;
                if (n == 0) {
                    append(new, malloc(ARRAY_LENGTH * sizeof(int8_t)));
                    n = new->lastElement;
                }
                m = 0;
            }
            ((int8_t *)n->value)[m] = last;
            m++;
            if (m >= ARRAY_LENGTH) {
                n = n->next;
                if (n == 0) {
                    append(new, malloc(ARRAY_LENGTH * sizeof(int8_t)));
                    n = new->lastElement;
                }
                m = 0;
            }
            ((int8_t *)n->value)[m] = 0;
        } else {
            printf("There was a problem");
            return 1;
        }
        swap = result;
        result = new;
        new = swap;
    }

    int resultLength = (length(result) - 1) * ARRAY_LENGTH + m;

    e = result->firstElement;
    while(e != 0) {
        free(e->value);
        e = e->next;
    }
    freeLinkedList(result);
    n = new->firstElement;
    while(n != 0) {
        free(n->value);
        n = n->next;
    }
    freeLinkedList(new);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The length of the result is %i.", resultLength);

    free(input);
    return 0;
}

