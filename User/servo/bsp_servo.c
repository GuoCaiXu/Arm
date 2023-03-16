# include "./servo/bsp_servo.h"
# include "./tim/bsp_tim.h"
# include "./ad/bsp_ad.h"
# include "./delay/bsp_delay.h"

/**
  * @brief  �ŷ�ϵͳ��ʼ��
  * @param  ��
  * @retval ��
  */
void Servo_Init(void){

    PWM_TIM_Init(); 
    ADCx_Init();
 }

/**
  * @brief  ���ö�� 1 �ĽǶ�
  * @param  ��
  * @retval ��
  */
void Servo_SetAngle1(float Angle){

    PWM_SetCompare1(Angle / 180 * 200 + 500);
}

/**
  * @brief  ���ö�� 2 �ĽǶ�
  * @param  ��
  * @retval ��
  */
void Servo_SetAngle2(float Angle){

    PWM_SetCompare2(Angle / 180 * 200 + 500);
}

/**
  * @brief  ���ö�� 3 �ĽǶ�
  * @param  ��
  * @retval ��
  */
void Servo_SetAngle3(float Angle){

    PWM_SetCompare3(Angle / 180 * 200 + 500);
}

/**
  * @brief  ���ö�� 4 �ĽǶ�
  * @param  ��
  * @retval ��
  */
void Servo_SetAngle4(float Angle){

    PWM_SetCompare4(Angle / 180 * 200 + 500);
}

/**
  * @brief  ��������ӽǶ�1 ת�� �Ƕ�2
  * @param  ��
  * @retval ��
  */
void Servo1_SlowChange(float angle1, float angle2){

    int i;
    if (angle1 < angle2){

        for (i = angle1; i <= angle2; i += 2){
            Servo_SetAngle1(i);
            Delay_ms(20);
        }
    }
    else{
        for (i = angle1; i >= angle2; i -= 2){
            Servo_SetAngle1(i);
            Delay_ms(20);
        }
    }
}

void Servo2_SlowChange(float angle1, float angle2){

    int i;
    if (angle1 < angle2){

        for (i = angle1; i <= angle2; i += 2){
            Servo_SetAngle2(i);
            Delay_ms(20);
        }
    }
    else{
        for (i = angle1; i >= angle2; i -= 2){
            Servo_SetAngle2(i);
            Delay_ms(20);
        }
    }
}

void Servo3_SlowChange(float angle1, float angle2){

    int i;
    if (angle1 < angle2){

        for (i = angle1; i <= angle2; i += 2){
            Servo_SetAngle3(i);
            Delay_ms(20);
        }
    }
    else{
        for (i = angle1; i >= angle2; i -= 2){
            Servo_SetAngle3(i);
            Delay_ms(20);
        }
    }
}

void Servo4_SlowChange(float angle1, float angle2){

    int i;
    if (angle1 < angle2){

        for (i = angle1; i <= angle2; i += 2){
            Servo_SetAngle4(i);
            Delay_ms(20);
        }
    }
    else{
        for (i = angle1; i >= angle2; i -= 2){
            Servo_SetAngle4(i);
            Delay_ms(20);
        }
    }
}
