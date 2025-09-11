/**
 *
 * Yousif Alboufradi
 *
 *
 * 2025-09-11
 *
 * This program helps customers track their mobile data usage to help them know if they are using the data too quick.
 * Computing whether the customer is over, under, or on the average of usage time.
 *
 */


 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>







int main(int argc, char **argv) {




    double numGbs = atof(argv[1]);
    int day = atoi(argv[2]);
    double totalGbs = atof(argv[3]);







    // computing average
    avgUsage = totalGbs / day


    // if the user is under their average daily use
    printf(" days used,  days remaining\n Average daily use: GB/day\n" );
    printf("\nYou are at or below your average daily use (GB/day)\n You can use up to GB/day and stay below your data plan limit\n");


    // if the user is over their average daily use
    printf("\ndays used,  days remaining\n Average daily use: GB/day\n" );
    printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");


    return 0;
}