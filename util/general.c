//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "general.h"

int static PROGRAM_NAME_LENGTH = 10;

int getLength(FILE *fp) {
    char ch;
    int length = 0;
    while(fgetc(fp) != EOF) {
        length++;
    }
    fseek(fp, 0L, SEEK_SET);
    return length;
}

char *getInput(char *programPath) {
    char inputFile[8];
    memcpy(inputFile, &programPath[strlen(programPath) - PROGRAM_NAME_LENGTH], 4);
    inputFile[4] = '\0';
    strcat(inputFile, ".txt");
    FILE *fp = fopen(inputFile, "r");

    int fileSize = getLength(fp);
    char *input = malloc((fileSize + 1) * sizeof(char));

    fread(input, (size_t)fileSize, 1, fp);
    input[fileSize] = '\0';

    fclose(fp);
    return input;
}

char *readString(char *input, int *i, char end) {
    char *string = malloc(sizeof(char));
    int length = 0;
    while (input[*i] != end) {
        length++;
        string = realloc(string, (length + 1) * sizeof(char));
        string[length - 1] = input[*i];
        (*i)++;
    }
    string[length] = 0;
    return string;
}

int readInteger(char *input, int *i) {
    int integer = 0;
    while (input[*i] > 47 && input[*i] < 58) {
        integer *= 10;
        integer += input[*i] - 48;
        (*i)++;
    }
    return integer;
}
