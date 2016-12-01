//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/linkedList.h"

int main(int argc, char *argv[]) {
    char *input = "1113222113";

    clock_t t1, t2;

    t1 = clock();

    int i = 0;
    LinkedList *result = createLinkedList();
    while(input[i] != '\0') {
        append(result, (void *) input[i] - 48);
        i++;
    }
    LinkedList *new = createLinkedList();
    LinkedList *swap;
    Element *e;
    Element *n;
    int last, count;
    for (i = 0; i < 40; i++) {
        e = result->firstElement;
        n = new->firstElement;
        if (e != 0) {
            last = (int) e->value; count = 0;
            e = e->next;
            while (e != 0) {
                count++;
                if ((int) e->value != last) {
                    if (n != 0) {
                        n->value = (void *) count;
                        n = n->next;
                    } else {
                        append(new, (void *) count);
                    }
                    if (n != 0) {
                        n->value = (void *) last;
                        n = n->next;
                    } else {
                        append(new, (void *) last);
                    }
                    count = 0;
                }
                last = (int) e->value;
                e = e->next;
            }
            count++;
            if (n != 0) {
                n->value = (void *) count;
                n = n->next;
            } else {
                append(new, (void *) count);
            }
            if (n != 0) {
                n->value = (void *) last;
            } else {
                append(new, (void *) last);
            }
        } else {
            printf("There was a problem");
            return 1;
        }
        swap = result;
        result = new;
        new = swap;
    }

    int resultLength = length(result);

    freeLinkedList(result);
    freeLinkedList(new);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The length of the result is %i.", resultLength);

    free(input);
    return 0;
}

