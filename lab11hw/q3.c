#include <stdio.h>

struct Patient {
    char name[50];
    int age;
    int healthScore;
};

struct DailyReport {
    int day;
    int scoreChange;
};

int computeHealth(struct Patient *p, struct DailyReport reports[], int index, int totalDays)
{
    if (index == totalDays)
        return p->healthScore;

    p->healthScore += reports[index].scoreChange;

    return computeHealth(p, reports, index + 1, totalDays);
}

int main()
{
    struct Patient p = {"Ali", 30, 70};

    struct DailyReport reports[3] = {
        {1, 5},
        {2, -3},
        {3, 8}
    };

    int finalScore = computeHealth(&p, reports, 0, 3);

    printf("Final Health Score: %d\n", finalScore);

    return 0;
}
