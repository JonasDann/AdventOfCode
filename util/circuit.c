//
// Created by Jonas on 25.12.2015.
//

#include <windef.h>
#include <stdlib.h>
#include "circuit.h"

int findWire(Circuit *circuit, char *name, int nameLength, Wire **wire) {
    int i, n;
    for (i = 0; i < circuit->wiresUsed; i++) {
        if (nameLength == circuit->wires[i].nameLength) {
            for (n = 0; n < nameLength; n++) {
                if (circuit->wires[i].name[n] == name[n]) {
                    if (n == nameLength - 1) {
                        *wire = &circuit->wires[i];
                        return 1;
                    }
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}

void mallocWires(Circuit *circuit) {
    int i;
    for (i = circuit->wiresUsed; i < circuit->wiresSize; i++) {
        circuit->wires[i].name = malloc(5 * sizeof(char *));
        circuit->wires[i].output = -1;
    }
}

void resizeWireArray(Circuit *circuit) {
    if (circuit->wiresSize <= circuit->wiresUsed) {
        circuit->wiresSize += 5;
        circuit->wires = realloc(circuit->wires, circuit->wiresSize * sizeof(Wire));
        mallocWires(circuit);
    }
}

Circuit *createCircuit() {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->wiresSize = 5;
    circuit->wires = malloc(circuit->wiresSize * sizeof(Wire));
    circuit->wiresUsed = 0;
    mallocWires(circuit);
    circuit->constantsSize = 5;
    circuit->constantsUsed = 0;
    circuit->constants = malloc(circuit->constantsSize * sizeof(int));
    return circuit;
}

int *getWireOutput(Circuit *circuit, char *name, int nameLength) {
    Wire **wire = malloc(sizeof(Wire *));
    if (findWire(circuit, name, nameLength, wire)) {
        int *output = &((*wire)->output);
        free(wire);
        return output;
    }
    resizeWireArray(circuit);
    memmove(circuit->wires[circuit->wiresUsed].name, name, nameLength * sizeof(char));
    circuit->wires[circuit->wiresUsed].nameLength = nameLength;
    circuit->wiresUsed++;
    return &(circuit->wires[circuit->wiresUsed - 1].output);
}

int *getConstant(Circuit *circuit, int constant) {
    int i;
    for (i = 0; i < circuit->constantsUsed; i++) {
        if (circuit->constants[i] == constant) {
            return &circuit->constants[i];
        }
    }
    if (circuit->constantsSize <= circuit->constantsUsed) {
        circuit->constantsSize += 5;
        circuit->constants = realloc(circuit->constants, circuit->constantsSize * sizeof(int));
    }
    circuit->constants[circuit->constantsUsed] = constant;
    circuit->constantsUsed++;
    return &circuit->constants[circuit->constantsUsed - 1];
}

void addOrSetWire(Circuit *circuit, char *name, int nameLength, int *input1, OPERATOR operator, int *input2) {
    Wire *wire;
    if (!findWire(circuit, name, nameLength, wire)) {
        resizeWireArray(circuit);
        memmove(circuit->wires[circuit->wiresUsed].name, name, nameLength * sizeof(char));
        circuit->wires[circuit->wiresUsed].nameLength = nameLength;
        wire = &circuit->wires[circuit->wiresUsed];
        circuit->wiresUsed++;
    }
    wire->input1 = input1;
    wire->operator = operator;
    wire->input2 = input2;
}

int resolve(Circuit *circuit, char *wireName, int nameLength) {
    Wire **wire = malloc(sizeof(Wire *));
    if (!findWire(circuit, wireName, nameLength, wire)) {
        return -1;
    }
    if (*((*wire)->input1) == -1) {
        resolve(circuit, ((Wire *)(*wire)->input1)->name, ((Wire *)(*wire)->input1)->nameLength);
    }
    if (*((*wire)->input2) == -1) {
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
            (*wire)->output = !*((*wire)->input2);
            break;
        case RSHIFT:
            (*wire)->output = *((*wire)->input1) >> *((*wire)->input2);
            break;
        case OR:
            (*wire)->output = *((*wire)->input1) | *((*wire)->input2);
            break;
    }
    return (*wire)->output;
}

void freeCircuit(Circuit *circuit) {
    int i;
    for (i = 0; i < circuit->wiresSize; i++) {
        free(circuit->wires[i].name);
    }
    free(circuit->wires);
    free(circuit->constants);
}
