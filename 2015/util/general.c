//
// Created by Jonas on 22.12.2015.
//

#include "general.h"

int static END_LENGTH = 6;

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
    size_t pathLength = strlen(programPath);
    int i = 0;
    while (isDigit(programPath[pathLength - END_LENGTH - i - 1])) {
        i++;
    }
    int filenameLength = 3 + i;
    char inputFile[filenameLength + 1]; // day + number + \0
    memcpy(inputFile, &programPath[pathLength - END_LENGTH - filenameLength], filenameLength);
    inputFile[filenameLength] = '\0';
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

bool isDigit(char character) {
    return character > 47 && character < 58;
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