//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util/general.h"
#include <openssl/md5.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    unsigned char output[MD5_DIGEST_LENGTH];

    MD5((unsigned char *)input, strlen(input), output);
    printf("%x\n", output[0]);
    printf("%x\n", output[1]);
    printf("%x\n", output[2]);
    printf("%x\n", output[3]);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    //printf("Santa and RoboSanta visited %i houses", totalHouses);

    free(input);
    return 0;
}

