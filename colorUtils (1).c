/**
 *
 * Yousif Alboufradi
 * Mason Melcher
 *
 * 2025-10-09
 *
 * Writing functions that utilize pass-by-reference (pointers) and dealing with error handling and enumerated types
 *
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <math.h>


 #include "colorUtils.h"

 double maxOfThree(double a, double b, double c) {
    return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}



 int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {

   if(c == NULL || m == NULL || y == NULL || k == NULL) {
      return COLOR_NULL;
   }

   if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
      return COLOR_RANGE;
   }

   if(r == 0 && g == 0 && b == 0) {
      *c = 0;
      *m = 0;
      *y = 0;
      *k = 1;
      return COLOR_OK;
   }


   double scaledR = r / 255.0 , scaledG = g / 255.0 , scaledB = b / 255.0;

   double K = 1 - maxOfThree(scaledR, scaledG, scaledB);
   *c = (1 - scaledR - K) / (1 - K);
   *m = (1 - scaledG - K) / (1 - K);
   *y = (1 - scaledB - K) / (1 - K);
   *k = K;
   return COLOR_OK;
 }




int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
   if(r == NULL || g == NULL || b == NULL) {
      return COLOR_NULL;
   }

   if(c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1) {
      return COLOR_RANGE;
   }

   *r = round(255.0 * (1 - c) * (1 - k));
   *g = round(255.0 * (1 - m) * (1 - k));
   *b = round(255.0 * (1 - y) * (1 - k));
   return COLOR_OK;
}

