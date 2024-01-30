ENTRY(Reset_Handler)

MEMORY
{
	FLASH (rx): ORIGIN = 0x08000000, LENGTH = 512K
	SRAM (rwx): ORIGIN = 0x20000000, LENGTH = 128K
}


_estack = ORIGIN(SRAM) + LENGTH(SRAM) - 96K; /* end of RAM, leaving space for stack */
_Min_Heap_Size = 0x200; /* required amount of heap */
_Min_Stack_Size = 0x400; /* required amount of stack */

SECTIONS
{
  .isr_vector :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector))
    . = ALIGN(4);
  } >FLASH

  .text :
  {
    . = ALIGN(4);
		
    *(.text)
    *(.text.*)
    *(.rodata)
    *(.rodata.*)
    KEEP(*(.init))
    KEEP(*(.fini))
    *(.eh_frame)
    *(.ARM.exidx)
		
    . = ALIGN(4);
    _etext = .;
  } >FLASH

  _sidata = LOADADDR(.data);

  .data :
  {
    . = ALIGN(4);
    _sdata = .;
		
    *(.data)
    *(.data.*)
    KEEP(*(.init_array))
    KEEP(*(.fini_array))

    . = ALIGN(4);
    _edata = .;
  } >SRAM AT> FLASH

  .bss :
  {
    . = ALIGN(4);
    _sbss = .;
    __bss_start__ = _sbss;
		
    *(.bss)
    *(.bss.*)
		
    . = ALIGN(4);
    _ebss = .;
    __bss_end__ = _ebss;
  } >SRAM

  .heap : {
    __heap_start__ = .;
    end = __heap_start__;
    _end = end;
    __end = end;
    KEEP(*(.heap))
    __heap_end__ = .;
    __HeapLimit = __heap_end__;
  } > SRAM

}
