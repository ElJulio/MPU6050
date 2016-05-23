/*
 * MPU6050.c
 *
 * Created: 21.05.2016 14:47:02
 *  Author: Julius
 */ 

 #include <stdbool.h>

 #include "i2c_master.h"
 #include "MPU6050.h"

 #define power_mgmt 0x6b
 #define address 0x68 // Achtung 7Bit Addresse wird in der ic2 lib geshifted


 //define gyro register
 #define gyro_x_H 0x43
 #define gyro_x_L 0x44
 #define gyro_y_H 0x45
 #define gyro_y_L 0x46
 #define gyro_z_H 0x47
 #define gyro_z_L 0x48

 //define accel register
 #define accel_x_H 0x3b
 #define accel_x_L 0x3c
 #define accel_y_H 0x3d
 #define accel_y_L 0x3e
 #define accel_z_H 0x3f
 #define accel_z_L 0x40

 //define temp register
 #define temp_H 0x41
 #define temp_L 0x42 

 #define write true
 #define read false	

 //wake up the mpu
 void mpu_wakeup(void){
	i2c_start(address,write);
	i2c_write(power_mgmt);
	i2c_write(0x0);
	i2c_stop();
 }

 //Set the MPU into sleep mode
 void mpu_sleep(void){
	i2c_start(address,write);
	i2c_write(power_mgmt);
	i2c_write(0x01);
	i2c_stop();
 }

 int16_t zweierkompliment(uint16_t val){
	if(val >= 0x8000){
		return -((65535 - val)+1);
	}
	else{
		return val;
	}
 }

 //read the low and and the high byte of the gyro in the mcu
 int16_t mpu_read_gyro_x(){

	uint16_t gyro_x;
	int16_t gx;

	i2c_start(address,write);
	i2c_write(gyro_x_H);

	i2c_start(address,read);

	gyro_x = ((uint8_t)i2c_read_ack())<<8;
	gyro_x |= i2c_read_nack();

	i2c_stop();

	gx = zweierkompliment(gyro_x);
	
	return gx;	
 }

int16_t mpu_read_gyro_y(){
		uint16_t gyro_y;
		int16_t gy;

		i2c_start(address,write);
		i2c_write(gyro_y_H);

		i2c_start(address,read);

		gyro_y = ((uint8_t)i2c_read_ack())<<8;
		gyro_y |= i2c_read_nack();

		i2c_stop();
		
		gy = zweierkompliment(gyro_y);

		return gy;
 }

 int16_t mpu_read_gyro_z(){
	  uint16_t gyro_z;
	  int16_t gz;

	  i2c_start(address,write);
	  i2c_write(gyro_z_H);

	  i2c_start(address,read);

	  gyro_z = ((uint8_t)i2c_read_ack())<<8;
	  gyro_z |= i2c_read_nack();

	  i2c_stop();
	  
	  gz = zweierkompliment(gyro_z);

	  return gz;
}

float mpu__read_temp(){
	  uint16_t temp;
	  float temp_c;

	  i2c_start(address,write);
	  i2c_write(temp_H);

	  i2c_start(address,read);

	  temp = ((uint8_t)i2c_read_ack())<<8;
	  temp |= i2c_read_nack();

	  i2c_stop();

	  temp_c = temp / 340 + 36.53;
	  
	  return temp_c;

}

int16_t mpu_read_accel_x(){
	uint16_t accel_x;
	int16_t ax;

	i2c_start(address,write);
	i2c_write(accel_x_H);

	i2c_start(address,read);

	accel_x = ((uint8_t)i2c_read_ack())<<8;
	accel_x |= i2c_read_nack();

	i2c_stop();
	
	ax = zweierkompliment(accel_x);

	return ax;
}

int16_t mpu_read_accel_y(){
	uint16_t accel_y;
	int16_t ay;

	i2c_start(address,write);
	i2c_write(accel_y_H);

	i2c_start(address,read);

	accel_y = ((uint8_t)i2c_read_ack())<<8;
	accel_y |= i2c_read_nack();

	i2c_stop();
	
	ay = zweierkompliment(accel_y);

	return ay;
}

int16_t mpu_read_accel_z(){
	uint16_t accel_z;
	int16_t az;

	i2c_start(address,write);
	i2c_write(accel_z_H);

	i2c_start(address,read);

	accel_z = ((uint8_t)i2c_read_ack())<<8;
	accel_z |= i2c_read_nack();

	i2c_stop();
		  
	az = zweierkompliment(accel_z);

	return az;
}

