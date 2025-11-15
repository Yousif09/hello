/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-11-14
 *
 * designing structures to encapsulate attributes to model an airport record
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "airport.h"

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv) {

    if(gpsId == NULL || type == NULL || name == NULL ||
       city == NULL || countryAbbrv == NULL || elevationFeet < 0) {
        return NULL;
       }
    if(latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        return NULL;
    }

    Airport *a = (Airport *) malloc( sizeof(Airport));
    a->gpsId = (char *) malloc( sizeof(char) * strlen(gpsId) + 1);
    strcpy(a->gpsId, gpsId);
    a->type = (char *) malloc( sizeof(char) * strlen(type) + 1);
    strcpy(a->type, type);
    a->name = (char *) malloc( sizeof(char) * strlen(name) + 1);
    strcpy(a->name, name);
    a->latitude = latitude;
    a->longitude = longitude;
    a->elevationFeet = elevationFeet;
    a->city = (char *) malloc( sizeof(char) * strlen(city) + 1);
    strcpy(a->city, city);
    a->countryAbbrv = (char *) malloc( sizeof(char) * strlen(countryAbbrv) + 1);
    strcpy(a->countryAbbrv, countryAbbrv);

    return a;

}


void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv) {

    if(gpsId == NULL || type == NULL || name == NULL ||
       city == NULL || countryAbbrv == NULL || elevationFeet < 0) {
        return;
       }
    if(latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        return;
    }


        airport->gpsId = (char *) malloc( sizeof(char) * strlen(gpsId) + 1);
        strcpy(airport->gpsId, gpsId);
        airport->type = (char *) malloc( sizeof(char) * strlen(type) + 1);
        strcpy(airport->type, type);
        airport->name = (char *) malloc( sizeof(char) * strlen(name) + 1);
        strcpy(airport->name, name);
        airport->latitude = latitude;
        airport->longitude = longitude;
        airport->elevationFeet = elevationFeet;
        airport->city = (char *) malloc( sizeof(char) * strlen(city) + 1);
        strcpy(airport->city, city);
        airport->countryAbbrv = (char *) malloc( sizeof(char) * strlen(countryAbbrv) + 1);
        strcpy(airport->countryAbbrv, countryAbbrv);

}

char* airportToString(const Airport* a) {
    if(a == NULL) {
        return NULL;
    }

    char buffer[1000];

    sprintf(buffer, "%s, %s, %f, %f, %s, %d, %s, %s", a->gpsId, a->name, a->latitude, a->longitude, a->type, a->elevationFeet, a->city, a->countryAbbrv);
    char *result = (char *) malloc(strlen(buffer) + 1);
    strcpy(result, buffer);
    return result;

}


double getAirDistance(const Airport* origin, const Airport* destination) {
    if(origin == NULL || destination == NULL) {
        return 1;
    }

    return airDistance(origin->latitude, origin->longitude, destination->latitude, destination->longitude);

}


double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs) {
    if(stops == NULL || size <=1 || aveKmsPerHour <= 0 || aveLayoverTimeHrs < 0) {
        return 1;
    }


    double totalDist = 0;
    double travelTime = 0;
    double averageKms = 0;
    double layoverTime = 0;
    for(int i=0; i < size -1; i++) {
        double dist = airDistance(stops[i].latitude, stops[i].longitude, stops[i+1].latitude, stops[i+1].longitude);
        totalDist += dist;

    }
    averageKms = totalDist / aveKmsPerHour;
    layoverTime = aveLayoverTimeHrs * (size - 2);
    travelTime = averageKms + layoverTime;

    return travelTime;



}



    // Helper function to calculate the distance between two locations
    double airDistance(double latA, double longA, double latB, double longB) {

        double radLatA = (latA / 180) * M_PI;
        double radLongA = (longA / 180) * M_PI;
        double radLatB  = (latB / 180) * M_PI;
        double radLongB = (longB / 180) * M_PI;

        double diff = radLongB - radLongA;


        double airDist = acos(sin(radLatA) * (sin(radLatB)) + cos(radLatA) * cos(radLatB) * cos(diff)) * 6371;
        return airDist;
    }



    // Helper function to print airport information:
    void printAirport(const Airport *a) {
        printf("GPS ID: %s\n", a->gpsId);
        printf("Type: %s\n", a->type);
        printf("Name: %s\n", a->name);
        printf("latitude: %f\n", a->latitude);
        printf("longitude: %f\n", a->longitude);
        printf("Elevation: %d feet\n", a->elevationFeet);
        printf("City: %s\n", a->city);
        printf("Country: %s\n\n", a->countryAbbrv);

    }


