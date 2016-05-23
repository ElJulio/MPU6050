/*
 * MPU6050.h
 *
 * Created: 21.05.2016 15:10:49
 *  Author: Julius
 */ 


#ifndef MPU6050_H_
#define MPU6050_H_

void mpu_wakeup(void);
int16_t mpu_read_gyro_x();
int16_t mpu_read_gyro_y();
int16_t mpu_read_gyro_z();
int16_t mpu_read_accel_x();
int16_t mpu_read_accel_y();
int16_t mpu_read_accel_z();
float mpu__read_temp();



#endif /* MPU6050_H_ */