//
// Created by Jonas on 22.12.2015.
//

#include "present.h"

int getWrappingPaperNeededInSquareFoot(struct Present present) {
    int side1 = present.x * present.y;
    int side2 = present.y * present.z;
    int side3 = present.z * present.x;
    return 2 * side1 + 2 * side2 + 2 * side3 + (side1 < side2 ? side1 < side3 ? side1 : side3 : side2 < side3 ? side2 : side3);
}

int getRibbonNeededInFoot(struct Present present) {
    return (present.x < present.y ? present.y < present.z ? 2 * present.x + 2 * present.y : 2 * present.x + 2 * present.z : present.x < present.z ? 2 * present.x + 2 * present.y : 2 * present.y + 2 * present.z) + present.x * present.y * present.z;
}
