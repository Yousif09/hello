#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <math.h>
#include <cmocka.h>
#include "colorUtils.h"

double absd(double x) { return x < 0 ? -x : x; }

void testBlack(void **st) {
  (void)st;
  double c,m,y,k;
  int rc = rgbToCMYK(0,0,0,&c,&m,&y,&k);
  assert_int_equal(rc, colorOk);
  assert_true(absd(c-0.0) < 1e-12);
  assert_true(absd(m-0.0) < 1e-12);
  assert_true(absd(y-0.0) < 1e-12);
  assert_true(absd(k-1.0) < 1e-12);
}

void testYellow(void **st) {
  (void)st;
  double c,m,y,k;
  assert_int_equal(rgbToCMYK(255,255,0,&c,&m,&y,&k), colorOk);
  assert_true(k <= 1e-12);
  assert_true(c <= 1e-8);
  assert_true(m <= 1e-8);
  assert_true(absd(y-1.0) < 1e-8);
}

void testRoundTrip(void **st) {
  (void)st;
  int r=12, g=200, b=123, rr, gg, bb;
  double c,m,y,k;
  assert_int_equal(rgbToCMYK(r,g,b,&c,&m,&y,&k), colorOk);
  assert_int_equal(cmykToRGB(c,m,y,k,&rr,&gg,&bb), colorOk);
  assert_true(rr>=r-1 && rr<=r+1);
  assert_true(gg>=g-1 && gg<=g+1);
  assert_true(bb>=b-1 && bb<=b+1);
}

void testErrors(void **st) {
  (void)st;
  double c,m,y,k;
  int r,g,b;

  int rc = rgbToCMYK(-1,256,0,&c,&m,&y,&k);
  assert_true((rc & colorRange) != 0);

  rc = rgbToCMYK(0,0,0,NULL,&m,&y,&k);
  assert_true((rc & colorNull) != 0);

  rc = cmykToRGB(1.1,0,0,0,&r,&g,&b);
  assert_true((rc & colorRange) != 0);

  rc = cmykToRGB(NAN,0,0,0,&r,&g,&b);
  assert_true((rc & colorNotFinite) != 0);

  rc = cmykToRGB(0,0,0,0,NULL,&g,&b);
  assert_true((rc & colorNull) != 0);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(testBlack),
    cmocka_unit_test(testYellow),
    cmocka_unit_test(testRoundTrip),
    cmocka_unit_test(testErrors),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
