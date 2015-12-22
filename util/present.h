#ifndef ADVENTOFCODEC_PRESENT_H
#define ADVENTOFCODEC_PRESENT_H

struct Present {
    int x;
    int y;
    int z;
};

int getWrappingPaperNeededInSquareFoot(struct Present present);

int getRibbonNeededInFoot(struct Present present);

#endif //ADVENTOFCODEC_PRESENT_H