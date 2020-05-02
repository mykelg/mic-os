#include "elf.h"
#include "lib.h"
#include "test.h"

static void init(void) {
  extern int rodata_end, data_start, data_end, bss_start, bss_end;
  memcpy(&data_start, &rodata_end, (size_t)(&data_end) - (size_t)(&data_start));
  memset(&bss_start, 0, (size_t)(&bss_end) - (size_t)(&bss_start));

  serial_init();
}

void main(void) {
  init();

  puts("Hello, World!\n");

  test();

  extern int osdata_start;
  char* entry_point = elf_load(&osdata_start);
  puts("entry point: "); putxval((unsigned long)entry_point); puts("\n");
  void (*f)(void) = (void (*)(void))entry_point;
  f();

  while (1) {
  }
}
