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

    PWM_SetCompare1(Angle / 180 * 2000 + 500);
}

/**
  * @brief  ���ö�� 2 �ĽǶ�
  * @param  ��
  * @retval ��
  */
void Servo_SetAngle2(float Angle){

    PWM_SetCompare2(Angle / 180 * 2000 + 500);
}

/**
  * @brief  ���ö�� 3 �ĽǶ�
  * @param  ��
  * @retval ��
  */
void Servo_SetAngle3(float Angle){

    PWM_SetCompare3(Angle / 180 * 2000 + 500);
}

/**
  * @brief  ���ö�� 4 �ĽǶ�
  * @param  ��
  * @retval ��
  */
void Servo_SetAngle4(float Angle){

    PWM_SetCompare4(Angle / 180 * 2000 + 500);
}
