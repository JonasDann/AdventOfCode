//
// Created by Jonas on 25.12.2015.
//

#include <windef.h>
#include <stdlib.h>
#include "circuit.h"

Circuit *createCircuit() {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->wiresSize = 5;
    circuit->wires = malloc(circuit->wiresSize * sizeof(Wire));
    int i;
    for (i = 0; i < circuit->wiresSize; i++) {
        circuit->wires[i].name = malloc(5 * sizeof(char *));
        circuit->wires[i].output = -1;
    }
    circuit->constantsSize = 5;
    circuit->constants = malloc(circuit->constantsSize * sizeof(int));
    return circuit;
}

int *getWireOutput(Circuit *circuit, char *name, int nameLength) {
    return NULL;
}

int *getConstant(Circuit *circuit, int constant) {
    return NULL;
}

void addOrSetWire(Circuit *circuit, char *name, int nameLength, int *input1, OPERATOR operator, int *input2) {

}

int resolve(Circuit *circuit) {
    return 0;
}

void freeCircuit(Circuit *circuit) {
    int i;
    for (i = 0; i < circuit->wiresSize; i++) {
        free(circuit->wires[i].name);
    }
    free(circuit->wires);
    free(circuit->constants);
}
