#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int ID;
    int initialHeight;
    double growthRate;
} Building;

int computeHeightAndUpdate(Building *b, int day) {
    if (day == 0) {
        return b->initialHeight;
    }

    int prevHeight = computeHeightAndUpdate(b, day - 1);

    double rawIncrease = prevHeight * b->growthRate;
    int increase = (int) floor(rawIncrease);

    int newHeight = prevHeight + increase;

    b->initialHeight = newHeight;

    return newHeight;
}

int main(void) {
    Building myBuilding;
    myBuilding.ID = 1;
    myBuilding.initialHeight = 100;
    myBuilding.growthRate = 0.05;

    int day;
    printf("Enter the day number (n >= 0): ");
    if (scanf("%d", &day) != 1 || day < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int heightOnDayN = computeHeightAndUpdate(&myBuilding, day);

    printf("Height on day %d: %d\n", day, heightOnDayN);
    printf("Building struct now stores initialHeight = %d\n", myBuilding.initialHeight);

    return 0;
}
