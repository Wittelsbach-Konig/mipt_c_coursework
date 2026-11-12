#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd(long long x, long long y);
unsigned long long iabs(long long x) {
  return x < 0 ? -(unsigned long long)x : (unsigned long long)x;
}

int main() {

  long long x = 0, y = 0, g;
  int res;

  res = scanf("%lld %lld", &x, &y);

  if (res != 2 || x == 0 || y == 0) {
    printf("Error: input invalid, expect x != 0 and y != 0\n");
    abort();
  }

  assert(res == 2);

  g = gcd(x, y);

  printf("%llu\n", g);
  return 0;
}

unsigned long long gcd(long long x, long long y) {
  unsigned long long a = iabs(x);
  unsigned long long b = iabs(y);

  while (a != b) {
    if (a > b) {
      a -= b;
    }
    if (b > a) {
      b -= a;
    }
  }

  return a;
}
