
MEMORY
{
  MFLASH (rx) : ORIGIN = 0x00000000, LENGTH = 2M
  BFLASH (rx) : ORIGIN = 0x11000000, LENGTH = 512K
  RAM0  (rwx) : ORIGIN = 0x13000000, LENGTH = 64K
  RAM1  (rwx) : ORIGIN = 0x20000000, LENGTH = 512K
  RAM2  (rwx) : ORIGIN = 0x20080000, LENGTH = 128K
}

/* Aliases */
REGION_ALIAS("CODE_FLASH", MFLASH);
REGION_ALIAS("DATA_RAM", RAM1);
REGION_ALIAS("HEAP_RAM", RAM1);
REGION_ALIAS("STACK_RAM", RAM1);
REGION_ALIAS("BSS_RAM", RAM1);

ENTRY(Reset_Handler)

SECTIONS
{
	.text :
	{
		KEEP(*(.isr_vector))
		*(.text*)

		KEEP(*(.init))
		KEEP(*(.fini))

		/* .ctors */
		*crtbegin.o(.ctors)
		*crtbegin?.o(.ctors)
		*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
		*(SORT(.ctors.*))
		*(.ctors)

		/* .dtors */
		*crtbegin.o(.dtors)
		*crtbegin?.o(.dtors)
		*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
		*(SORT(.dtors.*))
		*(.dtors)

		*(.rodata*)

		KEEP(*(.eh_frame*))
	} > CODE_FLASH

	.ARM.extab :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > CODE_FLASH

	__exidx_start = .;
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} > CODE_FLASH
	__exidx_end = .;

	.copy.table :
	{
		. = ALIGN(4);
		__textdata_start__ = LOADADDR(.data);
		__textram0_start__ = LOADADDR(.ram0data);
		__textram1_start__ = LOADADDR(.ram1data);
		__textram2_start__ = LOADADDR(.ram2data);
		__copy_table_start__ = .;
		LONG (__textdata_start__)
		LONG (__data_start__)
		LONG (__data_end__ - __data_start__)
		LONG (__textram0_start__)
		LONG (__ram0data_start__)
		LONG (__ram0data_end__ - __ram0data_start__)
		LONG (__textram1_start__)
		LONG (__ram1data_start__)
		LONG (__ram1data_end__ - __ram1data_start__)
		LONG (__textram2_start__)
		LONG (__ram2data_start__)
		LONG (__ram2data_end__ - __ram2data_start__)
		__copy_table_end__ = .;
	} > CODE_FLASH

	.zero.table :
	{
		. = ALIGN(4);
		__zero_table_start__ = .;
		LONG (__bss_start__)
		LONG (__bss_end__ - __bss_start__)
		__zero_table_end__ = .;
	} > CODE_FLASH

	.data :
	{
		. = ALIGN(4);
		__data_start__ = .;
		*(vtable)
		*(.data*)
		*(.ramfunc*)

		. = ALIGN(4);
		/* preinit data */
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);

		. = ALIGN(4);
		/* init data */
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);

		. = ALIGN(4);
		/* finit data */
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN (__fini_array_end = .);

		KEEP(*(.jcr*))
		. = ALIGN(4);
		/* All data end */
		__data_end__ = .;

	} > DATA_RAM AT > CODE_FLASH

	.bss :
	{
		. = ALIGN(4);
		__bss_start__ = .;
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > BSS_RAM

	.ram0data : ALIGN(4)
	{
		. = ALIGN(4);
		__ram0data_start__ = .;
		*(.ram0data)
		*(.ram0data*)
		*(.ram0func*)

		. = ALIGN(4);
		__ram0data_end__ = .;
	} > RAM0 AT > CODE_FLASH

	.ram1data : ALIGN(4)
	{
		. = ALIGN(4);
		__ram1data_start__ = .;
		*(.ram1data)
		*(.ram1data*)
		*(.ram1func*)

		. = ALIGN(4);
		__ram1data_end__ = .;
	} > RAM1 AT > CODE_FLASH

	.ram2data : ALIGN(4)
	{
		. = ALIGN(4);
		__ram2data_start__ = .;
		*(.ram2data)
		*(.ram2data*)
		*(.ram2func*)

		. = ALIGN(4);
		__ram2data_end__ = .;
	} > RAM2 AT > CODE_FLASH

	.heap (COPY):
	{
		__end__ = .;
		PROVIDE(end = .);
		*(.heap*)
		__HeapLimit = .;
	} > HEAP_RAM

	/* .stack_dummy section doesn't contains any symbols. It is only
	 * used for linker to calculate size of stack sections, and assign
	 * values to stack symbols later */
	.stack_dummy (COPY):
	{
		*(.stack*)
	} > STACK_RAM

	/* Set stack top to end of RAM, and stack limit move down by
	 * size of stack_dummy section */
	__StackTop = ORIGIN(STACK_RAM) + LENGTH(STACK_RAM);
	__StackLimit = __StackTop - SIZEOF(.stack_dummy);
	PROVIDE(__stack = __StackTop);

	/* Check if data + heap + stack exceeds STACK_RAM limit */
	ASSERT(__StackLimit >= __HeapLimit, "region STACK_RAM overflowed with stack")
}

