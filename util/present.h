#ifndef ADVENTOFCODEC_PRESENT_H
#define ADVENTOFCODEC_PRESENT_H

typedef struct  {
    int x;
    int y;
    int z;
} Present;

int getWrappingPaperNeededInSquareFoot(Present present);

int getRibbonNeededInFoot(Present present);

#endif //ADVENTOFCODEC_PRESENT_H