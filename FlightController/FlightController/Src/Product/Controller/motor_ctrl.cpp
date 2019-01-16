#include "motor_ctrl.h"

#include "pwm.h"

/*
 * Define
 */

#define MOTOR_MIN_DUTYCYCLE (20)
#define MOTOR_MAX_DUTYCYCLE (100)

/*
 * Code
 */

MotorCtrl::MotorCtrl()
{

}

MotorCtrl& MotorCtrl::GetInstance()
{
    static MotorCtrl motorCtrl;
    return motorCtrl;
}

bool MotorCtrl::OutputMotor(float pitchThrust, float rollThrust, float yawThrust, float heightThrust)
{
    uint8_t motorPWM[4];
    motorPWM[0] = (uint8_t) ((-1) * pitchThrust + rollThrust + yawThrust + heightThrust); // frontleft
    motorPWM[1] = (uint8_t) ((-1) * pitchThrust - rollThrust - yawThrust + heightThrust); // frontright
    motorPWM[2] = (uint8_t) (pitchThrust + rollThrust - yawThrust + heightThrust); // backleft
    motorPWM[3] = (uint8_t) (pitchThrust - rollThrust + yawThrust + heightThrust); // backright

    for (int i = 0; i < 4; ++i) {
        if (motorPWM[i] < MOTOR_MIN_DUTYCYCLE) {
            motorPWM[i] = MOTOR_MIN_DUTYCYCLE;
        } else if (motorPWM[i] > MOTOR_MIN_DUTYCYCLE) {
            motorPWM[i] = MOTOR_MIN_DUTYCYCLE;
        }
    }

    PWM_SetDutyCycle(PWM_CHANNEL_1, motorPWM[0]);
    PWM_SetDutyCycle(PWM_CHANNEL_2, motorPWM[0]);
    PWM_SetDutyCycle(PWM_CHANNEL_3, motorPWM[0]);
    PWM_SetDutyCycle(PWM_CHANNEL_4, motorPWM[0]);

    return true;
}