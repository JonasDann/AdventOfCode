#include "gameState.h"

void applyShield(GameState *state, int remainingTurns) {
    if (remainingTurns == 6) {
        state->playerArmor = 7;
    } else if (remainingTurns == 0) {
        state->playerArmor = 0;
    }
}

void applyPoison(GameState *state, int remainingTurns) {
    if (remainingTurns > 0) {
        state->bossHealth -= 3;
    }
}

void applyRecharge(GameState *state, int remainingTurns) {
    if (remainingTurns > 0) {
        state->playerMana += 101;
    }
}