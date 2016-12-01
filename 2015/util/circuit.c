//
// Created by Jonas on 25.12.2015.
//

#include <windef.h>
#include <stdlib.h>
#include "circuit.h"

int findWire(Circuit *circuit, char *name, int nameLength, Wire **wire) {
    Element *i = circuit->wires->firstElement;
    int n;
    while(i != 0) {
        if (nameLength == ((Wire *)i->value)->nameLength) {
            for (n = 0; n < nameLength; n++) {
                if (((Wire *)i->value)->name[n] == name[n]) {
                    if (n == nameLength - 1) {
                        *wire = ((Wire *)i->value);
                        return 1;
                    }
                } else {
                    break;
                }
            }
        }
        i = i->next;
    }
    return 0;
}

Wire *addWire(Circuit *circuit, char *name, int nameLength) {
    Wire *newWire = malloc(sizeof(Wire));
    newWire->name = malloc(5 * sizeof(char *));
    newWire->output = -1;
    add(circuit->wires, newWire);
    memmove(newWire->name, name, nameLength * sizeof(char));
    newWire->nameLength = nameLength;
    return newWire;
}

Circuit *createCircuit() {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->wires = createLinkedList();
    circuit->constants = createLinkedList();
    return circuit;
}

int *getWireOutput(Circuit *circuit, char *name, int nameLength) {
    Wire **wire = malloc(sizeof(Wire *));
    if (findWire(circuit, name, nameLength, wire)) {
        int *output = &((*wire)->output);
        free(wire);
        return output;
    }
    free(wire);
    Wire *newWire = addWire(circuit, name, nameLength);
    return &(newWire->output);
}

int *getConstant(Circuit *circuit, int constant) {
    Element *i = circuit->wires->firstElement;
    while(i != 0) {
        if (*((int *)i->value) == constant) {
            return i->value;
        }
        i = i->next;
    }
    add(circuit->constants, malloc(sizeof(int)));
    *(int *)circuit->constants->firstElement->value = constant;
    return circuit->constants->firstElement->value;
}

void addOrSetWire(Circuit *circuit, char *name, int nameLength, int *input1, OPERATOR operator, int *input2) {
    Wire **wire = malloc(sizeof(Wire *));
    if (!findWire(circuit, name, nameLength, wire)) {
        *wire = addWire(circuit, name, nameLength);
    }
    (*wire)->input1 = input1;
    (*wire)->operator = operator;
    (*wire)->input2 = input2;
    free(wire);
}

int resolve(Circuit *circuit, char *wireName, int nameLength) {
    Wire **wire = malloc(sizeof(Wire *));
    if (!findWire(circuit, wireName, nameLength, wire)) {
        return -1;
    }
    if ((*wire)->operator != NOT && *((*wire)->input1) == -1) {
        resolve(circuit, ((Wire *)(*wire)->input1)->name, ((Wire *)(*wire)->input1)->nameLength);
    }
    if ((*wire)->operator != CONSTANT && (*wire)->operator != FORWARD && *((*wire)->input2) == -1) {
        resolve(circuit, ((Wire *)(*wire)->input2)->name, ((Wire *)(*wire)->input2)->nameLength);
    }
    switch ((*wire)->operator) {
        case CONSTANT:
            (*wire)->output = *((*wire)->input1);
            break;
        case AND:
            (*wire)->output = *((*wire)->input1) & *((*wire)->input2);
            break;
        case LSHIFT:
            (*wire)->output = *((*wire)->input1) << *((*wire)->input2);
            break;
        case NOT:
            (*wire)->output = ~*((*wire)->input2);
            break;
        case RSHIFT:
            (*wire)->output = *((*wire)->input1) >> *((*wire)->input2);
            break;
        case OR:
            (*wire)->output = *((*wire)->input1) | *((*wire)->input2);
            break;
        case FORWARD:
            (*wire)->output = *((*wire)->input1);
            break;
    }
    (*wire)->output &= 65535;
    return (*wire)->output;
}

void freeCircuit(Circuit *circuit) {
    Element *i = circuit->wires->firstElement;
    while(i != 0) {
        free(((Wire *)i->value)->name);
        free(((Wire *)i->value));
        i = i->next;
    }
    freeLinkedList(circuit->wires);
    free(circuit->constants);
}
