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
    double avgUsage;
    double baseAverage;
    double remainingGbs;
    int remainingDays;
    double gbPerDay;







    // computing average usage
    avgUsage = numGbs / day; // ex: if we have 25gb used / the 5th day then we get a 5gb/day usage

    // average expected usage
    baseAverage = numGbs / 30;

    // how much gbs left
    remainingGbs = totalGbs - numGbs;

    // remaining days
    reaminingDays = 30 - day;

    // how much gbs can be used per day
    gbPerDay = remainingGbs / remainingDays;


    if(avgUsage < baseAverage) {
        // if the user is under their average daily use
        printf("%d days used, %d days remaining\n Average daily use: %fGB/day\n", day, remainingDays, avgUsage);
        printf("\nYou are at or below your average daily use (%fGB/day)\n You can use up to %fGB/day and stay below your data plan limit\n", avgUsage, gbPerDay);
    } else if(avgUsage > baseAverage) {
        // if the user is over their average daily use
        printf("\n%ddays used, %ddays remaining\n Average daily use: %fGB/day\n" );
        printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");
    }











    return 0;
}