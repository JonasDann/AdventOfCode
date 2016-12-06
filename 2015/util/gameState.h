#ifndef ADVENTOFCODEC_GAME_STATE_H
#define ADVENTOFCODEC_GAME_STATE_H

typedef enum {
    NONE,
    MAGIC_MISSILE,
    DRAIN,
    SHIELD,
    POISON,
    RECHARGE
} Spells;

struct GameState;

typedef struct Effect {
    void (*effect)(struct GameState *, int);
    int remainingTurns;
} Effect;

typedef struct GameState {
    int bossHealth;
    int bossDamage;
    int playerHealth;
    int playerArmor;
    int playerMana;
    Effect effects[3];
    struct GameState *prev;
    Spells lastSpell;
    int spentMana;
} GameState;

void applyShield(GameState *state, int remainingTurns);
void applyPoison(GameState *state, int remainingTurns);
void applyRecharge(GameState *state, int remainingTurns);

#endif //ADVENTOFCODEC_GAME_STATE_H