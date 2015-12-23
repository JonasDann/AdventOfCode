//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <string.h>
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
    char input[fileSize + 1];

    fread(input, (size_t)fileSize, 1, fp);
    input[fileSize] = '\0';

    fclose(fp);
    return input;
}
