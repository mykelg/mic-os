MEMORY
{
  romall(rx)  : o = 0x00000000, l = 0x00040000 /* 256KB */
  vectors(r)  : o = 0x00000000, l = 0x00000100 /* top of ROM */
  rom(rx)     : o = 0x00000100, l = 0x0000ff00

  ramall(rwx) : o = 0x20000000, l = 0x00010000 /* 64KB */
  data(rwx)   : o = 0x20000000, l = 0x00000300
  stack(rw)   : o = 0x20000300, l = 0x00000000 /* end of RAM */
}

SECTIONS
{
  .vectors : {
    vector.o(.data)
  } > vectors

  .text : {
    text_start = . ;
    startup.o(.text)
    lib.o(.text)
    test.o(.text)
    main.o(.text)
    text_end = . ;
  } > rom

  .rodata : {
    rodata_start = . ;
    *(.strings)
    *(.rodata)
    *(.rodata.*)
    rodata_end = . ;
  } > rom

  .data : {
    data_start = . ;
    *(.data)
    data_end = . ;
  } > data AT> rom

  .bss : {
    bss_start = . ;
    *(.bss)
    bss_end = . ;
  } > data AT> rom

  . = ALIGN(8);

  .stack : {
    stack_top = .;
  } > stack
}
