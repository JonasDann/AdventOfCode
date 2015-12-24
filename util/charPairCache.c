//
// Created by Jonas on 24.12.2015.
//

#include <stdlib.h>
#include <string.h>
#include "charPairCache.h"

void addCharPair(CharPairCache *cache, char *charPair) {
    if (cache->size == 0) {
        cache->size = 5;
        cache->charPairs = malloc(cache->size * sizeof(char *));

        int i;
        for (i = 0; i < 5; i++) {
            cache->charPairs[i] = malloc(2 * sizeof(char));
        }
    } else if (cache->size <= cache->used) {
        cache->size += 5;
        cache->charPairs = realloc(cache->charPairs, cache->size * sizeof(char *));
        int i;
        for (i = cache->size - 5; i < cache->size; i++) {
            cache->charPairs[i] = malloc(2 * sizeof(char));
        }
    }
    cache->charPairs[cache->used][0] = charPair[0];
    cache->charPairs[cache->used][1] = charPair[1];
    cache->used++;
}

int hasCharPairNotOverlapping(CharPairCache *cache, char *charPair) {
    int i;
    for (i = 0; i < cache->used - 1; i++) {
        if (cache->charPairs[i][0] == charPair[0] && cache->charPairs[i][1] == charPair[1]) {
            return 1;
        }
    }
    return 0;
}

void freeCache(CharPairCache *cache) {
    int i;
    for (i = 0; i < cache->size; i++) {
        free(cache->charPairs[i]);
    }
    free(cache->charPairs);
}
