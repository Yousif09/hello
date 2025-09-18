/**
 * Yousif Alboufradi
 *
 * Mason Melcher
 *
 *
 * 2025-09-18
 *
 * This program generates an amortization table for a 401(k) account and read command line arguments.
 *
 *
 */

 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    double startBalance = atof(argv[1]);
    double monthlyCont = atof(argv[2]);
    double averageReturn = atof(argv[3]);
    double averageInflation = atof(argv[4]);
    double retirement = atof(argv[5]);
    int years;

    double adjustedRate = ((1 + averageReturn) / (1 + averageInflation)) - 1;

    double monthlyRate = (averageReturn / 100) / 12.0;

    double balance = startBalance;
    double totalInterest = 0.0;
    int months = years * 12;

    printf("Month    Interest     Balance\n");

    for (int i = 1; i <= months; i++) {
        double baseForInterest = balance + monthlyCont;
        double interest = baseForInterest * monthlyRate;

        balance = baseForInterest + interest;
        totalInterest += interest;

        printf("%5d $%10.2f $%10.2f\n", i, interest, balance);
    }

    printf("Total Interest Earned: $%10.2f\n", totalInterest);
    printf("Total Nest Egg: $%10.2f\n", balance);

    return 0;
}

