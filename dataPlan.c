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





    if(argc != 4) {
        printf("ERROR: incorrect number of command line arguments\n");
        exit(1);
    }


    double numGbs = atof(argv[1]);
    if(numGbs < 0) {
        printf("ERROR\n");
        exit(1);
    }

    int day = atoi(argv[2]);
    if(day < 0) {
        printf("ERROR\n");
        exit(1);
    }

    double GbsUsed = atof(argv[3]);
    if(GbsUsed < 0){
        printf("ERROR\n");
        exit(1);
    }



    // computing average usage
    double avgUsage = GbsUsed / day;

    // allowed daily
    double baseAverage = numGbs / 30;

    // how much gbs left
    double remainingGbs = numGbs - GbsUsed;

    // remaining days
    int remainingDays = 30 - day;

    // how much gbs can be used per day
    double gbPerDay = remainingGbs / remainingDays;

    double excess = GbsUsed + avgUsage * remainingDays - numGbs;


    if(avgUsage > baseAverage) {
        printf(" %d days used, %d days remaining\n Average daily use: %.3f GB/day\n", day, remainingDays, avgUsage);
        printf("You are EXCEEDING your average daily use (%.2f GB/day).\n", baseAverage);
        printf("Continuing this high usage, you'll exceed your data plan by %.2f GB\n", excess);
        printf("\nTo stay below your data plan, use no more than %.2f GB/day\n", gbPerDay);
    } else if(avgUsage < baseAverage) {
        printf(" %d days used, %d days remaining\n Average daily use: %.3fGB/day\n", day, remainingDays, avgUsage);
        printf("\nYou are at or below your average daily use (%.3fGB/day)\n You can use up to %.3fGB/day and stay below your data plan limit\n", baseAverage, gbPerDay);
    } else if(avgUsage == baseAverage) {
         printf(" %d days used, %d days remaining\n Average daily use: %.3fGB/day\n", day, remainingDays, avgUsage);
         printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");
    }




    return 0;
}