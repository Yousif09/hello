/**
 *
 * Yousif Alboufradi
 * Mason Melcher
 *
 * 2025-10-09
 *
 * Header file
 *
 */


 typedef enum {
    COLOR_OK,
    COLOR_NULL,
    COLOR_RANGE
 } ColorError;




/**
 *
 * returns the largest of the three values
 *
 *
 */
double maxOfThree(double a, double b, double c);



/**
 *
 * Converts an RGB color model to CMYK
 *
 */
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);



/**
 *
 * Converts a CMYK color model to RGB
 *
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);

