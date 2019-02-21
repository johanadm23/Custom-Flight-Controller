#ifndef _UAV_DEFINES_
#define _UAV_DEFINES_

/*
 * This file defines global constants that all files need to use.
 */

/*
 * Defines
 */

#define UAV_G (9.81)
#define UAV_PI (3.1415926)

/*
 * Struct
 */

typedef struct {
   float yaw;
   float pitch;
   float roll;
} FCAttType;

typedef FCAttType FCAttRateType;

typedef struct {
   int motor1PWM;
   int motor2PWM;
   int motor3PWM;
   int motor4PWM;
} FCMotorPWMType;

typedef struct {
   float x;
   float y;
   float z;
} FCSensorDataType;

typedef FCSensorDataType FCAccDataType;
typedef FCSensorDataType FCVelDataType;

typedef struct {
   float q1;
   float q2;
   float q3;
   float q4;
} FCQuaternionType;

typedef struct {
    FCSensorDataType gyroData;
    FCSensorDataType accData;
    // FCSensorDataType magData;
} FCSensorMeasType;

typedef struct {
    FCAttType att;
    FCAttRateType attRate;
} FCStateType;

typedef struct {
    FCAccDataType desiredAcc;
    float desiredYaw;
} FCCmdType;

#endif