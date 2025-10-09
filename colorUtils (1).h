#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H

typedef enum {
  colorOk        = 0,
  colorNull      = 1 << 0,
  colorRange     = 1 << 1,
  colorNotFinite = 1 << 2
} ColorError;

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);

#endif
