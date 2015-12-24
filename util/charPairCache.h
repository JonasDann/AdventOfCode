//
// Created by Jonas on 24.12.2015.
//

#ifndef ADVENTOFCODEC_CHARPAIRCACHE_H
#define ADVENTOFCODEC_CHARPAIRCACHE_H

#include <stddef.h>

typedef struct {
    char **charPairs;
    size_t size;
    int used;
} CharPairCache;

void addCharPair(CharPairCache *cache, char *charPair);

int hasCharPairNotOverlapping(CharPairCache *cache, char *charPair);

void freeCache(CharPairCache *cache);

#endif //ADVENTOFCODEC_CHARPAIRCACHE_H
