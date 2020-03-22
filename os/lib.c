#include "lib.h"

#define LM3S6965_UART0 ((volatile struct Uart*)0x4000c000)
#define LM3S6965_UART1 ((volatile struct Uart*)0x4000d000)
#define LM3S6965_UART2 ((volatile struct Uart*)0x4000e000)

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

struct Uart {
  uint32_t dr;
  union {
    uint32_t _sr;
    uint32_t _cr;
  } u1;
  uint8_t _res1[0x10];
  uint32_t fr;
  uint8_t _res2[0x04];
  uint32_t ilpr;
  uint32_t ibrd;
  uint32_t fbrd;
  uint32_t lcrh;
  uint32_t ctl;
  uint32_t ifls;
  uint32_t im;
  uint32_t ris;
  uint32_t mis;
  uint32_t icr;
  uint8_t _res3[0xf8c];

  uint32_t peripd_id4;
  uint32_t peripd_id5;
  uint32_t peripd_id6;
  uint32_t peripd_id7;
  uint32_t peripd_id0;
  uint32_t peripd_id1;
  uint32_t peripd_id2;
  uint32_t peripd_id3;

  uint32_t p_cell_id0;
  uint32_t p_cell_id1;
  uint32_t p_cell_id2;
  uint32_t p_cell_id3;
};

#define LM3S6965_UART_CTL_UARTEN (1<<1)
#define LM3S6965_UART_FR_TXFE (1<<7)
#define LM3S6965_UART_LCRH_WLEN_8 ((1<<6)|(1<<5))

volatile struct Uart* uart = LM3S6965_UART0;

void serial_init(void) {
  // uart disable
  uart->ctl &= ~LM3S6965_UART_CTL_UARTEN;

  // baudrate setting
  // uart->ibrd =;
  // uart->fbrd =;

  // UART word length = 8bit
  uart->lcrh |= LM3S6965_UART_LCRH_WLEN_8;

  // uart enable
  uart->ctl |= LM3S6965_UART_CTL_UARTEN;
}

static int serial_is_send_enable(void) {
  return (uart->fr & LM3S6965_UART_FR_TXFE);
}

static void serial_send_byte(char c) {
  while (!serial_is_send_enable()) {
  }
  uart->dr = (uint32_t)c;
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
