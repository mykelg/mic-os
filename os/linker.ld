ENTRY("start")

MEMORY
{
  ramall(rwx) : o = 0x20000000, l = 0x00010000 /* 64KB */
  ram(rwx)    : o = 0x20000100, l = 0x00007f00
  stack(rw)   : o = 0x20010000, l = 0x00000000 /* end of RAM */
}

SECTIONS
{
  .text : {
    text_start = . ;
    startup.o(.text)
    lib.o(.text)
    test.o(.text)
    main.o(.text)
    text_end = . ;
  } > ram

  .rodata : {
    rodata_start = . ;
    *(.strings)
    *(.rodata)
    *(.rodata.*)
    rodata_end = . ;
  } > ram

  .data : {
    data_start = . ;
    *(.data)
    data_end = . ;
  } > ram

  .bss : {
    bss_start = . ;
    *(.bss)
    bss_end = . ;
  } > ram

  . = ALIGN(8);

  .stack : {
    stack_top = .;
  } > stack
}
