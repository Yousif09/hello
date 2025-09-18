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


 int main(int argc, char **argv) {


    double startingBalance = atof(argv[1]);
    double monthlyCont = atof(argv[2]);
    double averageReturn = atof(argv[3]);
    double averageInflation = atof(argv[4]);
    double retirement = atof(argv[5]);

    int years;


    double adjustedRate = ((1 + averageReturn) / (1 + averageInflation)) - 1; // inflation adjusted rate of return formula

    double monthlyRate = (averageReturn / 12.0);

    double balance = startingBalance;
    double totalInterest = 0.0;
    int months =  years * 12;




    for(int i=1; i<= months; i++) {
      double baseForInterest = balance + monthlyCont;
      double interest = baseForInterest * monthlyRate;

      balance = baseForInterest + interest;
      totalInterest += interest; 
    }

 }