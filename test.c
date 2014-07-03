#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "wcwidth.h"

#define TEST(name) \
  static void test_##name(void)

#define RUN_TEST(test) \
  test_count++; \
  test_##test(); \
  puts("  " #test);

static int test_count = 0;

TEST (wcwidth) {
  assert(14 == string_width("こんにちわ世界"));
  assert(20 == string_width("こ★ん■に●ち▲わ☆世◆界"));
  assert(26 == string_width_cjk("こ★ん■に●ち▲わ☆世◆界"));
}

int
main () {
  clock_t start = clock();

  printf("\n");

  RUN_TEST(wcwidth);

  printf("\n  %d tests passed in %.5fs\n\n"
    , test_count
    , (float) (clock() - start) / CLOCKS_PER_SEC);

  return 0;
}
