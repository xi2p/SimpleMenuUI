/*
* @author  :  xi2p
* This file is based on the work of the following authors:
* @file	:  OLED_UI_Driver.h https://github.com/bdth-7777777/OLED_UI
*/
#ifndef __OLED_UI_DRIVER_H
#define __OLED_UI_DRIVER_H
/*���������Ҫ��ֲ����Ŀ������Ҫ�������º�����ʵ�ַ�ʽ���� */
#include <stdint.h>

//��ȡȷ�ϣ�ȡ�����ϣ��°���״̬�ĺ���(��Q��Ϊʲôʹ�ú궨������Ǻ�����A����Ϊ�����������Ч�ʣ����ٴ�������)
// #define Key_GetEnterStatus()    GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)
// #define Key_GetBackStatus()     GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)
// #define Key_GetUpStatus()       GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)
// #define Key_GetDownStatus()     GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15)

uint8_t Key_GetEnterStatus(void);	//��ȡȷ�ϰ���״̬
uint8_t Key_GetBackStatus(void);	//��ȡȡ������״̬
uint8_t Key_GetUpStatus(void);	//��ȡ�ϰ���״̬
uint8_t Key_GetDownStatus(void);	//��ȡ�°���״̬

extern int16_t EncoderAddition;	//����������ֵ
extern uint8_t EnterStatus;
extern uint8_t BackStatus;
extern uint8_t UpStatus;
extern uint8_t DownStatus;

//������ʼ������
void Key_Init(void);

//��������ʼ������
void Encoder_Init(void);

// ������ʹ�ܺ���
void Encoder_Enable(void);

//������ʧ�ܺ���
void Encoder_Disable(void);

//��ȡ������������ֵ
int16_t Encoder_Get(void);

//��ʱ����
void Delay_us(uint32_t xus);
void Delay_ms(uint32_t xms);
void Delay_s(uint32_t xs);

#endif
