#include <stdio.h>
#include <math.h>

struct File {
    char fileName[50];
    float originalSize;
    float reductionRate;
};

float compressSize(int k, float prevSize, struct File f) {
    if (k == 0)
        return prevSize;

    float reduced = prevSize - ceil(prevSize * f.reductionRate);
    printf("After round %d: %.2f MB\n", k, reduced);

    return compressSize(k - 1, reduced, f);
}

int main() {
    struct File f;

    printf("Enter file name: ");
    scanf("%s", f.fileName);

    printf("Enter original file size (MB): ");
    scanf("%f", &f.originalSize);

    printf("Enter reduction rate (0 to 1): ");
    scanf("%f", &f.reductionRate);

    int rounds;
    printf("Enter number of compression rounds: ");
    scanf("%d", &rounds);

    printf("\n--- Compression for %s ---\n", f.fileName);

    compressSize(rounds, f.originalSize, f);

    return 0;
}
