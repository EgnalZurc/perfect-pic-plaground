/* $Id: getsuart.c,v 1.1 2003/12/09 22:52:09 GrosbaJ Exp $ */
#include <p18cxxx.h>
#include "sw_uart.h"

/********************************************************************
*    Function Name:  getsUART                                       *
*    Return Value:   void                                           *
*    Parameters:     buffer: pointer to string                      *
*                    len: length of characters to receive           *
*    Description:    This routine receives a string of characters   *
*                    from the SW UART of length specified by len.   *
********************************************************************/
void getsUART(char *buffer, unsigned char len)
{
  char i;    // Length counter
  unsigned char data;

  for(i=0;i<len;i++)   // Only retrieve len characters
  {
    data = getcUART(); // Get a character from the USART
                       // and save in the string
    *buffer = data;
    buffer++;          // Increment the string pointer
  }
}
