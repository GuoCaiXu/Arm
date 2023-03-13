# ifndef _BSP_TIM_H
# define _BSP_TIM_H

# include "stm32f10x.h"

/*��ʱ������*/
# define PWM_TIM                    TIM3
# define PWM_TIM_APBxClock_FUN      RCC_APB1PeriphClockCmd
# define PWM_TIM_CLK                RCC_APB1Periph_TIM3

/*����ARR �� PSC*/
# define PWM_ARR_Period             (20000 - 1)
# define PWM_PSC_Prescaler          (72 - 1)

/*���ͨ�� 1*/
# define PWM_TIM_CH1_GPIO_CLK       RCC_APB2Periph_GPIOA
# define PWM_TIM_CH1_PORT           GPIOA
# define PWM_TIM_CH1_PIN            GPIO_Pin_6

/*���ͨ�� 2*/
# define PWM_TIM_CH2_GPIO_CLK       RCC_APB2Periph_GPIOA
# define PWM_TIM_CH2_PORT           GPIOA
# define PWM_TIM_CH2_PIN            GPIO_Pin_7

/*���ͨ�� 3*/
# define PWM_TIM_CH3_GPIO_CLK       RCC_APB2Periph_GPIOB
# define PWM_TIM_CH3_PORT           GPIOB
# define PWM_TIM_CH3_PIN                GPIO_Pin_0

/*���ͨ�� 4*/
# define PWM_TIM_CH4_GPIO_CLK       RCC_APB2Periph_GPIOB
# define PWM_TIM_CH4_PORT           GPIOB
# define PWM_TIM_CH4_PIN                GPIO_Pin_1

/*----------------��������----------------*/
void PWM_TIM_Init(void);                    //TIM ��ʱ����ʼ��
void PWM_SetCompare1(uint16_t Compare);     //����ͨ�� 1��ռ�ձ�
void PWM_SetCompare2(uint16_t Compare);     //����ͨ�� 2��ռ�ձ�
void PWM_SetCompare3(uint16_t Compare);     //����ͨ�� 3��ռ�ձ�
void PWM_SetCompare4(uint16_t Compare);     //����ͨ�� 4��ռ�ձ�

# endif /*_BSP_TIM_H*/
