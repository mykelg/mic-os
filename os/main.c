#include "lib.h"

static void init(void) {
  serial_init();
}

void main(void) {
  init();

  puts("Hello, World!\n");
  while (1) {
  }
}
