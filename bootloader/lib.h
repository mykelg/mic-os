typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef uint32_t size_t;

void serial_init(void);
void putc(char c);
void puts(const char* s);
void putxval(unsigned long value);
void putxvald(unsigned long value, int digit);
void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* s, int c, size_t n);
void dump(const char* buffer, size_t size);
