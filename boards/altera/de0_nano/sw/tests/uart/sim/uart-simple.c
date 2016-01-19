/*
 * UART hello world
 *
 * Tests UARTs by printing a hello world string.
 *
 * Julius Baxter, julius.baxter@orsoc.se
 *
*/

#include "cpu-utils.h"
#include "board.h"
#include "uart.h"
#include "printf.h"

void hello_from_uart(int uart_core)
{
  uart_init(uart_core);
  printf("\n\tHello world from UART%d \n\0", uart_core);  
  
}

void
delay(int n)
{
  volatile int i=0;
  while(i<n)
    i++;
}


int main()
{

  hello_from_uart(0);

  

  for(;;)
  	{
	 printf("\n\tHello world from UART%d \n\0", 0); 
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 delay(50000);delay(50000);delay(50000);delay(50000);delay(50000);
	 
  }

  report(0x8000000d);
  
  exit(0);

}
