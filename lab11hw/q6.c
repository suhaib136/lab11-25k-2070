#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

struct Student {
    struct Person person;
    int creditHours;
    int perCreditFee;
};

int computeFee(int subjects[], int n, struct Student s) {
    if (n == 0)
        return 0;

    return computeFee(subjects, n - 1, s) + (subjects[n - 1] * s.perCreditFee);
}

int main() {
    struct Student s;

    printf("Enter student name: ");
    scanf("%s", s.person.name);

    printf("Enter age: ");
    scanf("%d", &s.person.age);

    printf("Enter per credit fee: ");
    scanf("%d", &s.perCreditFee);

    int n;
    printf("Enter number of subjects: ");
    scanf("%d", &n);

    int subjects[n];
    printf("Enter credit hours of each subject: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &subjects[i]);

    int totalFee = computeFee(subjects, n, s);

    printf("Total Semester Fee: %d\n", totalFee);

    return 0;
}

