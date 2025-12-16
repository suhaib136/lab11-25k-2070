#include <stdio.h>
#include <string.h>

typedef struct {
    char customerName[50];
    double loanAmount;
    double interestRate;
    int months;
} Loan;

void simulateRepayment(Loan *L, double monthlyInstallment, int currentMonth) {
    if (L->loanAmount <= 0 || currentMonth > L->months) {
        return;
    }

    double interest = L->loanAmount * L->interestRate;
    L->loanAmount = L->loanAmount - monthlyInstallment + interest;

    printf("Month %d: Remaining Loan = %.2f\n", currentMonth, L->loanAmount);

    simulateRepayment(L, monthlyInstallment, currentMonth + 1);
}

int main() {
    Loan L;
    strcpy(L.customerName, "Ali");
    L.loanAmount = 10000;
    L.interestRate = 0.02;
    L.months = 12;

    double monthlyInstallment = 1000;

    simulateRepayment(&L, monthlyInstallment, 1);

    if (L.loanAmount <= 0)
        printf("Loan fully repaid.\n");
    else
        printf("Loan not fully repaid. Remaining: %.2f\n", L.loanAmount);

    return 0;
}
