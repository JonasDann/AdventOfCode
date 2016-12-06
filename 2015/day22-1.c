//
// Created by Jonas on 06.12.2016.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mem.h>
#include <limits.h>
#include "util/gameState.h"

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

int leastManaSpent;

void applyEffectsPlayer(GameState *state) {
    int i = 0;
    for (i; i < 3; i++) {
        Effect *effect = &(state->prev->effects[i]);
        effect->effect(state, effect->remainingTurns);
        if (effect->remainingTurns > 0) {
            state->effects[i].remainingTurns = effect->remainingTurns - 1;
        }
    }
}

void applyEffectsBoss(GameState *state) {
    int i = 0;
    for (i; i < 3; i++) {
        Effect *effect = &(state->effects[i]);
        effect->effect(state, effect->remainingTurns);
        if (effect->remainingTurns > 0) {
            effect->remainingTurns--;
        }
    }
}

int winLoseRestore(GameState **state) {
    int result = 0;

    if ((*state)->bossHealth <= 0 && (*state)->spentMana < leastManaSpent) {
        leastManaSpent = (*state)->spentMana;
    }
    if ((*state)->prev != NULL && (*state)->prev->lastSpell == NONE) {
        GameState *oldState = *state;
        *state = (*state)->prev;
        free(oldState);
        oldState = *state;
        *state = (*state)->prev;
        free(oldState);
        result = -1;
    } else if ((*state)->bossHealth <= 0 || (*state)->playerHealth <= 0 || (*state)->spentMana >= leastManaSpent) {
        GameState *oldState = *state;
        *state = (*state)->prev;
        free(oldState);
        result = -1;
    }
    while((*state) != NULL && (*state)->lastSpell == RECHARGE) {
        GameState *oldState = *state;
        *state = (*state)->prev;
        free(oldState);
        result = -1;
    }
    return result;
}

int playerTurn(GameState **state) {
    GameState *nextState = malloc(sizeof(GameState));
    memcpy(nextState, *state, sizeof(GameState));
    nextState->prev = *state;
    nextState->lastSpell = NONE;

    applyEffectsPlayer(nextState);

    (*state)->lastSpell++;
    switch((*state)->lastSpell) {
        case MAGIC_MISSILE:
            if (nextState->playerMana < 53) {
                (*state)->lastSpell = NONE;
                break;
            }
            nextState->playerMana -= 53;
            nextState->spentMana += 53;
            nextState->bossHealth -= 4;
            break;
        case DRAIN:
            if (nextState->playerMana < 73) {
                (*state)->lastSpell = NONE;
                break;
            }
            nextState->playerMana -= 73;
            nextState->spentMana += 73;
            nextState->bossHealth -= 2;
            nextState->playerHealth += 2;
            break;
        case SHIELD:
            if (nextState->playerMana < 113) {
                (*state)->lastSpell = NONE;
                break;
            }
            if (nextState->effects[0].remainingTurns == 0) {
                nextState->playerMana -= 113;
                nextState->spentMana += 113;
                nextState->effects[0].remainingTurns = 6;
                break;
            }
            (*state)->lastSpell++;
        case POISON:
            if (nextState->playerMana < 173) {
                (*state)->lastSpell = NONE;
                break;
            }
            if (nextState->effects[1].remainingTurns == 0) {
                nextState->playerMana -= 173;
                nextState->spentMana += 173;
                nextState->effects[1].remainingTurns = 6;
                break;
            }
            (*state)->lastSpell++;
        case RECHARGE:
            if (nextState->playerMana < 229) {
                (*state)->lastSpell = NONE;
                break;
            }
            if (nextState->effects[2].remainingTurns == 0) {
                nextState->playerMana -= 229;
                nextState->spentMana += 229;
                nextState->effects[2].remainingTurns = 5;
                break;
            }
        default:
            (*state)->lastSpell = NONE;
            break;
    }

    *state = nextState;
    return winLoseRestore(state);
}

void bossTurn(GameState **state) {
    applyEffectsBoss(*state);
    (*state)->playerHealth -= max((*state)->bossDamage - (*state)->playerArmor, 1);
    winLoseRestore(state);
}

void getLeastAmountOfMana(int bossHealth, int bossDamage) {
    GameState *state = malloc(sizeof(GameState));
    state->bossHealth =  bossHealth;
    state->bossDamage =  bossDamage;
    state->playerHealth = 50;
    state->playerArmor = 0;
    state->playerMana = 500;
    state->effects[0].effect = applyShield;
    state->effects[0].remainingTurns = 0;
    state->effects[1].effect = applyPoison;
    state->effects[1].remainingTurns = 0;
    state->effects[2].effect = applyRecharge;
    state->effects[2].remainingTurns = 0;
    state->prev = NULL;
    state->lastSpell = NONE;
    state->spentMana = 0;
    leastManaSpent = INT_MAX;

    while(state != NULL) {
        int result = playerTurn(&state);
        if (state == NULL) {
            break;
        } else if (result == -1) {
            continue;
        }
        bossTurn(&state);
    }
}

int main(int argc, char *argv[]) {
    clock_t t1, t2;

    t1 = clock();

    getLeastAmountOfMana(58, 9);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The least amount of mana is %i.", leastManaSpent);

    return 0;
}

