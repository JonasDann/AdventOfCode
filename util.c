//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <string.h>
#include "util.h"

int PROGRAM_NAME_LENGTH = 10;

char *getInput(char *programPath) {
    char inputFile[8];
    memcpy(inputFile, &programPath[strlen(programPath) - PROGRAM_NAME_LENGTH], 4);
    inputFile[4] = '\0';
    strcat(inputFile, ".txt");
    FILE *fp = fopen(inputFile, "r");

    fseek(fp, 0L, SEEK_END);
    int fileSize = ftell(fp);
    char input[fileSize + 1];

    fseek(fp, 0L, SEEK_SET);
    fread(input, fileSize, 1, fp);
    input[fileSize] = '\0';

    fclose(fp);
    return input;
}
