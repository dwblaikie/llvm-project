// RUN: %clangxx_msan -O0 -g %s -o %t && %run %t

#include <assert.h>
#include <malloc.h>

#include <sanitizer/msan_interface.h>

int main(void) {
  struct mallinfo mi = mallinfo();
  assert(__msan_test_shadow(&mi, sizeof(mi)) == -1);

  struct mallinfo2 mi2 = mallinfo2();
  assert(__msan_test_shadow(&mi2, sizeof(mi2)) == -1);
  return 0;
}
