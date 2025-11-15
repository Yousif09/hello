/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-11-14
 *
 * Tester file for the implementation on structures
 *
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include "airport.h"


 int main(int argc, char **argv) {

   // createAirport test cases:
   Airport *a = createAirport("JFK", "International", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "New York", "USA");
   printAirport(a);


   Airport *a2 = createAirport("DFW", "International", "Dallas Fort Worth International Airport", 32.8998, -97.0403, 607, "Dallas", "USA");
   printAirport(a2);


   Airport *a3 = createAirport("SEA", "International", "Seattle-Tacoma International Airport", 47.4502, -122.3088, 433, "Seattle", "USA");
   printAirport(a3);


   // initAirport test cases:

   Airport *b = (Airport *) malloc( sizeof(Airport));
   initAirport(b, "LAX", "International", "Los Angeles International Airport", 33.9416, -118.4085, 125, "Los Angeles", "USA");
   printAirport(b);

   Airport *b2 = (Airport *) malloc( sizeof(Airport));
   initAirport(b2, "DEN", "International", "Denver International Airport", 39.8561, -104.6737, 5431, "Denver", "USA");
   printAirport(b2);

   Airport *b3 = (Airport *) malloc( sizeof(Airport));
   initAirport(b3, "ORD", "International", "Chicago O'Hare International Airport", 41.9742, -87.9073, 672, "Chicago", "USA");
   printAirport(b3);


   // airportToString test cases:

   Airport *c = createAirport("JFK", "International", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "New York", "USA");
   char *s = airportToString(c);
   printf("Airport #1: %s\n\n", s);
   free(s);

   Airport *c1 = createAirport("LAX", "International", "Los Angeles International Airport", 33.9416, -118.4085, 125, "Los Angeles", "USA");
   char *s1 = airportToString(c1);
   printf("Airport #2: %s\n\n", s1);
   free(s1);

   Airport *c2 = createAirport("ORD", "International", "Chicago O'Hare International Airport", 41.9742, -87.9073, 672, "Chicago", "USA");
   char *s2 = airportToString(c2);
   printf("Airport #3: %s\n\n", s2);
   free(s2);

   // getAirDistance test cases:

   Airport *origin = createAirport("JFK", "International", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "New York", "USA");
   Airport *destination = createAirport("LAX", "International", "Los Angeles International Airport", 33.9416, -118.4085, 125, "Los Angeles", "USA");
   double dest = getAirDistance(origin, destination);
   printf("Distance from JFK to LAX is: %.2f km\n\n", dest);

   Airport *origin2 = createAirport("DFW", "International", "Dallas Fort Worth International Airport", 32.8998, -97.0403, 607, "Dallas", "USA");
   Airport *destination2 = createAirport("SEA", "International", "Seattle-Tacoma International Airport", 47.4502, -122.3088, 433, "Seattle", "USA");
   double dest2 = getAirDistance(origin2, destination2);
   printf("Distance from DFW to SEA is: %.2f km\n\n", dest2);

   Airport *origin3 = createAirport("ORD", "International", "Chicago O'Hare International Airport", 41.9742, -87.9073, 672, "Chicago", "USA");
   Airport *destination3 = createAirport("DEN", "International", "Denver International Airport", 39.8561, -104.6737, 5431, "Denver", "USA");
   double dest3 = getAirDistance(origin3, destination3);
   printf("Distance from ORD to DEN is: %.2f km\n\n", dest3);

   // getEstimatedTravelTime test cases:

   printf("Estimating travel time for flight #1.... \n");
   Airport *d = createAirport("ORD", "International", "Chicago O'Hare International Airport", 41.9742, -87.9073, 672, "Chicago", "USA");
   Airport *d2 = createAirport("DEN", "International", "Denver International Airport", 39.8561, -104.6737, 5431, "Denver", "USA");
   Airport stops[2] = {*d, *d2};
   double time = getEstimatedTravelTime(stops, 2, 800.0, 2.0);
   printf("Estimated travel time from ORD to DEN will be: %.1f hours\n\n", time);

   printf("Estimating travel time for flight #2.... \n");
   Airport *d3 = createAirport("LAX", "International", "Los Angeles International Airport", 33.9416, -118.4085, 125, "Los Angeles", "USA");
   Airport *d4 = createAirport("SFO", "International", "San Francisco International Airport", 37.6213, -122.3790, 13, "San Francisco", "USA");
   Airport stops2[2] = {*d3, *d4};
   double time2 = getEstimatedTravelTime(stops2, 2, 800.0, 2.0);
   printf("Estimated travel time from LAX to SFO will be: %.1f hours\n\n", time2);

   printf("Estimating travel time for flight #2.... \n");
   Airport *d5 = createAirport("MIA", "International", "Miami International Airport", 25.7959, -80.2870, 8, "Miami", "USA");
   Airport *d6 = createAirport("JFK", "International", "John F. Kennedy International Airport", 40.6413, -73.7781, 13, "New York", "USA");
   Airport stops3[2] = {*d5, *d6};
   double time3 = getEstimatedTravelTime(stops3, 2, 800.0, 2.0);
   printf("Estimated travel time from MIA to JFK will be: %.1f hours\n\n", time3);


    return 0;
 }
