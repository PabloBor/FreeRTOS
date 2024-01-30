
#include<stdio.h>
#include "usart.h"

/* Variables */
extern int __io_putchar(int ch) __attribute__((weak));
extern int __io_getchar(void) __attribute__((weak));


// register char * stack_ptr asm("sp");

// caddr_t _sbrk(int incr) {
//   extern char __bss_end__;	/* Defined by the linker */
//   static char *heap_end;
//   char *prev_heap_end;
 
//   if (heap_end == 0) {
//     heap_end = &__bss_end__;
//   }
//   prev_heap_end = heap_end;
//   if (heap_end + incr > stack_ptr) {
//     while (1)
//     {
//         // Heap and stack collision
//     }
//   }

//   heap_end += incr;
//   return (caddr_t) prev_heap_end;
// }


__attribute__((weak)) int _read(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
    *ptr++ = __io_getchar();
  }

  return len;
}

__attribute__((weak)) int _write(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
    //__io_putchar(*ptr++);
     __usart_write(USART2,*ptr++);
  }
  return len;
}
