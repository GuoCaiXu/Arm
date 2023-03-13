# include "./ad/bsp_ad.h"

/**
 *  @brief  ADC GPIO ����
 *  @param  ��
 *  @retval ��
 */
static void ADC_GPIO_Config(void){

    RCC_APB2PeriphClockCmd(ADCx_IN1_GPIO_CLK, ENABLE);   ///����ʱ����

    /*ADC ͨ��1 GPIO��ʼ��*/
    GPIO_InitTypeDef    GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = ADCx_IN1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADCx_IN1_PORT, &GPIO_InitStructure);

    /*ADC ͨ��2 GPIO��ʼ��*/
    GPIO_InitStructure.GPIO_Pin = ADCx_IN2_PIN;
    GPIO_Init(ADCx_IN2_PORT, &GPIO_InitStructure);

    /*ADC ͨ��3 GPIO��ʼ��*/
    GPIO_InitStructure.GPIO_Pin = ADCx_IN3_PIN;
    GPIO_Init(ADCx_IN3_PORT, &GPIO_InitStructure);

    /*ADC ͨ��4 GPIO��ʼ��*/
    GPIO_InitStructure.GPIO_Pin = ADCx_IN4_PIN;
    GPIO_Init(ADCx_IN4_PORT, &GPIO_InitStructure);
}

static void ADC_Mode_Config(void){

    /*����ADC ʱ��*/
    ADCx_APBxClock_FUN(ADCx_CLK, ENABLE);

    ADC_InitTypeDef     ADC_InitStructure;
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;      //���ö���ģʽ
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  //�����Ҷ���
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;     //�����ⲿ����Ϊû��
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;     //��ֹ����ģʽ
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;           //�ر�ɨ��ģʽ
    ADC_InitStructure.ADC_NbrOfChannel = 1;                 //ѡ���õ���ͨ����ĿΪ1
    ADC_Init(ADCx, &ADC_InitStructure);

    /*ʹ��ADC*/
    ADC_Cmd(ADCx, ENABLE);

    /*ADC У׼*/
    ADC_ResetCalibration(ADCx);     //��λУ׼
    while(ADC_GetResetCalibrationStatus(ADCx) == SET);      //�ȴ���λУ׼�ɹ�
    ADC_StartCalibration(ADCx);     //��ʼУ׼
    while(ADC_GetCalibrationStatus(ADCx) == SET);           //�ȴ�У׼���
}

/**
 *  @brief  ADC ��ʼ��
 *  @param  ��
 *  @retval ��
 */
void ADCx_Init(void){

    ADC_GPIO_Config();
    ADC_Mode_Config();
}

/**
 *  @brief  ��ȡADC���
 *  @param  ��
 *  @retval ��
 */
uint16_t ADC_GetValue(uint8_t ADC_Channel){

    ADC_RegularChannelConfig(ADCx, ADC_Channel, 1, ADC_SampleTime_55Cycles5);       //���ͨ��
    ADC_SoftwareStartConvCmd(ADCx, ENABLE);     //�������ת��
    while(ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC) == RESET);      //��ȡ��־λ

    return ADC_GetConversionValue(ADCx);
}
