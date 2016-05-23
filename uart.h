/*
 * uart.h
 *
 * Created: 21.05.2016 13:18:51
 *  Author: Julius
 */ 


#ifndef UART_H_
#define UART_H_

void uart_init(uint16_t baudrate);
void uart_putc(unsigned char c);
void uart_puts(char *s);



#endif /* UART_H_ */