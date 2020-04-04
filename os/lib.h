typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

void serial_init(void);
void putc(char c);
void puts(const char* s);
void putxval(unsigned long value);
