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
        addLast(result, (void *) input[i] - 48);
        i++;
    }
    LinkedList *new;
    int last, count;
    for (i = 0; i < 50; i++) {
        new = createLinkedList();

        Element *e = result->firstElement;
        if (e != 0) {
            last = (int) e->value; count = 0;
            e = e->next;
            while (e != 0) {
                count++;
                if ((int) e->value != last) {
                    addLast(new, (void *) count);
                    addLast(new, (void *) last);
                    count = 0;
                }
                last = (int) e->value;
                e = e->next;
            }
            count++;
            addLast(new, (void *) count);
            addLast(new, (void *) last);
        } else {
            printf("There was a problem");
            return 1;
        }
        freeLinkedList(result);
        result = new;
    }

    int resultLength = length(result);

    freeLinkedList(result);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The length of the result is %i.", resultLength);

    free(input);
    return 0;
}

