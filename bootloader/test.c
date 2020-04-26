#include "lib.h"
#include "test.h"

volatile int value_data = 0x02;
volatile int value_bss;
volatile const int value_rodata = 0x04;

static void test_ram_init(void) {
  puts("[TEST] RAM init test\n");
  puts(" .data init value (0x02): "); putxval(value_data); puts("\n");
  value_data = 0x04;
  puts(" .data assignment (0x04): "); putxval(value_data); puts("\n");
  puts("\n");
}

static void test_memory_mapping(void) {
  puts("[TEST] VA mapping test\n");
  puts(" rodata : "); putxval(&value_rodata); puts("\n");
  puts(" data   : "); putxval(&value_data);   puts("\n");
  puts(" bss    : "); putxval(&value_bss);    puts("\n");
  puts("\n");
}

static void test_memory_section(void) {
  puts("[TEST] section address test\n");
  extern int text_start, text_end;
  extern int rodata_start, rodata_end;
  extern int osdata_start, osdata_end;
  extern int data_start, data_end;
  extern int bss_start, bss_end;
  puts(" .text  : "); putxvald(&text_start,8); puts("-"); putxvald(&text_end,8);
  puts(" (len:"); putxval((int)(&text_end) - (int)(&text_start)); puts(")\n");
  puts(" .rodata: "); putxvald(&rodata_start,8); puts("-"); putxvald(&rodata_end,8);
  puts(" (len:"); putxval((int)(&rodata_end) - (int)(&rodata_start)); puts(")\n");
  puts(" .osdata: "); putxvald(&osdata_start,8); puts("-"); putxvald(&osdata_end,8);
  puts(" (len:"); putxval((int)(&osdata_end) - (int)(&osdata_start)); puts(")\n");
  puts(" .data  : "); putxvald(&data_start,8); puts("-"); putxvald(&data_end,8);
  puts(" (len:"); putxval((int)(&data_end) - (int)(&data_start)); puts(")\n");
  puts(" .bss   : "); putxvald(&bss_start,8); puts("-"); putxvald(&bss_end,8);
  puts(" (len:"); putxval((int)(&bss_end) - (int)(&bss_start)); puts(")\n");
  puts("\n");
}

static void test_memcpy(void) {
  puts("[TEST] memcpy()/memset() test\n");
  char src1[10];
  char src2[10];
  puts(" src1: init values:     |");
  for(int i=0; i<10; i++) {
    src1[i] = i;
    putxvald(src1[i],2); puts(",");
  }
  puts("\n src2: non-init values  |");
  for(int i=0; i<10; i++) {
    putxvald(src2[i],2); puts(",");
  }
  memcpy(src2, src1, 5);
  puts("\n memcpy(src2,src1,5)    |");
  for(int i=0; i<10; i++) {
    putxvald(src2[i],2); puts(",");
  }
  memset(src2, '@', 8);
  puts("\n memset(src2,@,8)       |");
  for(int i=0; i<10; i++) {
    putxvald(src2[i],2); puts(",");
  }
  puts("\n");
  puts("\n");
}

static void test_memset() {
}

static void test_memory_dump() {
  puts("[TEST] Memory dump\n");
  unsigned char* address = 0;
  dump(address, 0x200);
  address = 0x08;
  dump(address, 0x20);
  puts("\n");
}

static void test_memory_dump_osdata() {
  puts("[TEST] Memory dump osdata\n");
  extern int osdata_start, osdata_end;
  const char* osdata = &osdata_start;
  dump(osdata, 0x100);
  dump(osdata + 0x10000, 0x600);
  dump(osdata + 0x20000, 0x300);
  puts("\n");
}

void test(void) {
  test_ram_init();
  test_memory_mapping();
  test_memory_section();
  test_memcpy();
  test_memset();
  test_memory_dump();
  test_memory_dump_osdata();
}
