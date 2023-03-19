# include "./tim/bsp_tim.h"

/**
 *  @brief  TIM GPIO ��ʼ��
 *  @param  ��
 *  @retval ��
 */
static void PWM_TIM_GPIO_Config(void){

    RCC_APB2PeriphClockCmd(PWM_TIM_CH1_GPIO_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(PWM_TIM_CH3_GPIO_CLK, ENABLE);

    /*������������*/
    GPIO_InitTypeDef    GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = PWM_TIM_CH1_PIN | PWM_TIM_CH2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(PWM_TIM_CH1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PWM_TIM_CH3_PIN | PWM_TIM_CH4_PIN;
    GPIO_Init(PWM_TIM_CH3_PORT, &GPIO_InitStructure);
}

/**
 *  @brief  TIM ģʽ��ʼ��
 *  @param  ��
 *  @retval ��
 */
static void PWM_TIM_Mode_Config(void){

    PWM_TIM_APBxClock_FUN(PWM_TIM_CLK, ENABLE);

    /*---------------ʱ������---------------*/
    TIM_InternalClockConfig(PWM_TIM);       //ѡ���ڲ�ʱ��
    TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_Period = PWM_ARR_Period;
    TIM_TimeBaseStructure.TIM_Prescaler = PWM_PSC_Prescaler;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure);

    /*---------------���ͨ������---------------*/
    TIM_OCInitTypeDef       TIM_OCInitStructure;
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;       //PWM1ģʽ
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   //�ߵ�ƽ��Ч
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //ʹ��
    TIM_OCInitStructure.TIM_Pulse = 0;      //CCR
    TIM_OC1Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_OC2Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_OC3Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_OC4Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_Cmd(PWM_TIM, ENABLE);       //ʹ�ܶ�ʱ��
}

/**
 *  @brief  TIM ��ʼ��
 *  @param  ��
 *  @retval ��
 */
void PWM_TIM_Init(void){

    PWM_TIM_GPIO_Config();
    PWM_TIM_Mode_Config();
}

/**
 *  @brief  ����ͨ�� 1ռ�ձ�
 *  @param  ��
 *  @retval ��
 */
void PWM_SetCompare1(uint16_t Compare){
    TIM_SetCompare1(PWM_TIM, Compare);
}

/**
 *  @brief  ����ͨ�� 2ռ�ձ�
 *  @param  ��
 *  @retval ��
 */
void PWM_SetCompare2(uint16_t Compare){
    TIM_SetCompare2(PWM_TIM, Compare);
}

/**
 *  @brief  ����ͨ�� 3ռ�ձ�
 *  @param  ��
 *  @retval ��
 */
void PWM_SetCompare3(uint16_t Compare){
    TIM_SetCompare3(PWM_TIM, Compare);
}

/**
 *  @brief  ����ͨ�� 4ռ�ձ�
 *  @param  ��
 *  @retval ��
 */
void PWM_SetCompare4(uint16_t Compare){
    TIM_SetCompare4(PWM_TIM, Compare);
}
