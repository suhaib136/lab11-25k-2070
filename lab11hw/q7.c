#include <stdio.h>

int maxTip(int tips[], int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return tips[0];

    int take = tips[n-1] + maxTip(tips, n-2);
    int skip = maxTip(tips, n-1);

    return take > skip ? take : skip;
}

int main() {
    int n;
    printf("Enter number of delivery stops: ");
    scanf("%d", &n);

    int tips[n];
    printf("Enter tip amounts: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &tips[i]);

    int result = maxTip(tips, n);
    printf("Maximum tip possible: %d\n", result);

    return 0;
}
