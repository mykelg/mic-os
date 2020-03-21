#include "lib.h"

static volatile unsigned int * const UART_DR = (unsigned int *)0x4000c000;

static void serial_send_byte(char c) {
  *UART_DR = c;
}

void putc(char c) {
  if (c == '\n') {
    serial_send_byte('\r');
  }
  serial_send_byte(c);
}

void puts(const char* s) {
  while (*s) {
    putc(*(s++));
  }
}
