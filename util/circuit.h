//
// Created by Jonas on 25.12.2015.
//

#ifndef ADVENTOFCODEC_CIRCUIT_H
#define ADVENTOFCODEC_CIRCUIT_H

typedef enum {
    CONSTANT,
    AND,
    LSHIFT,
    NOT,
    RSHIFT,
    OR
} OPERATOR;

typedef struct {
    int output;
    char *name;
    int *input1;
    OPERATOR operator;
    int *input2;
} Wire;

typedef struct {
    Wire *wires;
    int wiresSize;
    int *constants;
    int constantsSize;
} Circuit;

Circuit *createCircuit();

int *getWireOutput(Circuit *circuit, char *name, int nameLength);
int *getConstant(Circuit *circuit, int constant);
void addOrSetWire(Circuit *circuit, char *name, int nameLength, int *input1, OPERATOR operator, int *input2);

int resolve(Circuit *circuit);
void freeCircuit(Circuit *circuit);

#endif //ADVENTOFCODEC_CIRCUIT_H
