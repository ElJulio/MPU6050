/*
 * I2C_Test_328P.c
 *
 * Created: 21.05.2016 12:41:53
 * Author : Julius
 */ 



#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "i2c_master.h"
#include "uart.h"
#include "MPU6050.h"

#define Baud 9600



int main(void)
{
    /* Replace with your application code */
	volatile int16_t gyro_x;
	volatile int16_t gyro_y;
	volatile int16_t gyro_z;

	volatile int16_t accel_x;
	volatile int16_t accel_y;
	volatile int16_t accel_z;

	volatile int16_t temp;

	char buffer[6];

    i2c_init();
	uart_init(256000);

	mpu_wakeup();
	

	while (1) 
    {
		gyro_x = mpu_read_gyro_x();
		gyro_y = mpu_read_gyro_y();
		gyro_z = mpu_read_gyro_z();

		accel_x = mpu_read_accel_x();
		accel_y = mpu_read_accel_y();
		accel_z = mpu_read_accel_z();

		temp = mpu__read_temp();

		itoa(temp, buffer, 10);
		uart_puts(buffer);
		uart_puts("  ");

		
		_delay_ms(10);			
    }
}

