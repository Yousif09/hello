#include <math.h>
#include "colorUtils.h"

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
  int err = colorOk;
  if (!c || !m || !y || !k) err |= colorNull;
  if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) err |= colorRange;
  if (err) return err;

  if (r == 0 && g == 0 && b == 0) { *c = 0; *m = 0; *y = 0; *k = 1; return colorOk; }

  double rp = r / 255.0, gp = g / 255.0, bp = b / 255.0;
  double maxv = rp; if (gp > maxv) maxv = gp; if (bp > maxv) maxv = bp;
  double K = 1.0 - maxv, den = 1.0 - K;
  *c = (1.0 - rp - K) / den;
  *m = (1.0 - gp - K) / den;
  *y = (1.0 - bp - K) / den;
  *k = K;
  return colorOk;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
  int err = colorOk;
  if (!r || !g || !b) err |= colorNull;
  if (!isfinite(c) || !isfinite(m) || !isfinite(y) || !isfinite(k)) err |= colorNotFinite;
  if (c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1) err |= colorRange;
  if (err) return err;

  long R = lround(255.0 * (1.0 - c) * (1.0 - k));
  long G = lround(255.0 * (1.0 - m) * (1.0 - k));
  long B = lround(255.0 * (1.0 - y) * (1.0 - k));

  if (R < 0) R = 0; else if (R > 255) R = 255;
  if (G < 0) G = 0; else if (G > 255) G = 255;
  if (B < 0) B = 0; else if (B > 255) B = 255;

  *r = (int)R; *g = (int)G; *b = (int)B;
  return colorOk;
}
