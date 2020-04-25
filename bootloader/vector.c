extern void stack_top(void);
extern void start(void);

void (*vectors[])(void) = {
    stack_top,
    start,            // Reset
    0,                // NMI
    0,                // Hard Fault
    0,                // CM3 Memory Management Fault
    0,                // CM3 Bus Fault
    0,                // CM3 Usage Fault
    0,                // Reserved
    0,                // Reserved
    0,                // Reserved
    0,                // Reserved
    0,                // SVCall
    0,                // Reserved for debug
    0,                // Reserved
    0,                // PendSV
    0,                // SysTick
};
