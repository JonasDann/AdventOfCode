//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"
#include "util/circuit.h"

void readWireName(char *name, int *length, char *input, int *i) {
    *length = 0;
    while(input[*i] != ' ' && input[*i] != '\n') {
        name[*length] = input[*i];
        (*i)++; (*length)++;
    }
}

int readConstant(char *input, int *i) {
    int constant = 0;
    while (input[*i] != ' ') {
        constant *= 10;
        constant += input[*i] - 48;
        (*i)++;
    }
    return constant;
}

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);
    input = "123 -> x\n456 -> y\nx AND y -> d\nx OR y -> e\nx LSHIFT 2 -> f\ny RSHIFT 2 -> g\nNOT x -> h\nNOT y -> i\n\0";

    clock_t t1, t2;

    t1 = clock();

    int i = 0, n;
    Circuit *circuit = createCircuit();
    int *input1;
    OPERATOR operator;
    int *input2;
    char wire[5];

    while (input[i] != '\0') {
        if (input[i] == 'N') {
            operator = NOT;
            i += 4;
        } else if (input[i] > 47 && input[i] < 58) { //input[i] is digit
            operator = CONSTANT;
            input1 = getConstant(circuit, readConstant(input, &i));
        } else {
            readWireName(wire, &n, input, &i);
            input1 = getWireOutput(circuit, wire, n);
            i++;
            switch(input[i]) {
                case 'A':
                    operator = AND;
                    i += 4;
                    break;
                case 'R':
                    operator = RSHIFT;
                    i += 7;
                    break;
                case 'L':
                    operator = LSHIFT;
                    i += 7;
                    break;
                case 'O':
                    operator = OR;
                    i += 3;
                    break;
                default:
                    printf("Illegal first operator character");
                    return 1;
            }
        }
        if (operator != CONSTANT) {
            if (input[i] > 47 && input[i] < 58) { //input[i] is digit
                input2 = getConstant(circuit, readConstant(input, &i));
            } else {
                readWireName(wire, &n, input, &i);
                input2 = getWireOutput(circuit, wire, n);
            }
        }
        i += 4;
        readWireName(wire, &n, input, &i);
        i++;
        addOrSetWire(circuit, wire, n, input1, operator, input2);
    }

    int a = resolve(circuit, "d", 1);
    int b = resolve(circuit, "e", 1);
    int c = resolve(circuit, "f", 1);
    freeCircuit(circuit);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The value of wire a is %i.", a);
    printf("The value of wire a is %i.", b);
    printf("The value of wire a is %i.", c);

    free(input);
    return 0;
}

