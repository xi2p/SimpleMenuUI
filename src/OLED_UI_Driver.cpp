/*
* @author  :  xi2p
* This file is based on the work of the following authors:
* @file	:  OLED_UI_Driver.c https://github.com/bdth-7777777/OLED_UI
*/
#include "OLED_UI_Driver.h"

/*
���ļ�˵������[Ӳ�������]
���ļ�������������������������������Ҫ��ֲ����Ŀ�������ʵ������޸���ش��롣
����ȷ��oled��Ļ�ܹ����������������ܹ���ȷ�����л�������ʱ������ʾ�ַ����ȣ����Ϳ��Կ�ʼ��ֲ
�йذ�����������ȵ����������ˡ�
*/

int16_t EncoderAddition = 0;	//����������ֵ
uint8_t EnterStatus = 1;
uint8_t BackStatus = 1;
uint8_t UpStatus = 1;
uint8_t DownStatus = 1;

uint8_t Key_GetEnterStatus(void) {
	uint8_t temp = EnterStatus;	//��ȡ��ǰ״̬
	EnterStatus = 1;			//�����ǰ״̬
	return temp;			//���ص�ǰ״̬
}

uint8_t Key_GetBackStatus(void) {
	uint8_t temp = BackStatus;	//��ȡ��ǰ״̬
	BackStatus = 1;			//�����ǰ״̬
	return temp;			//���ص�ǰ״̬
}

uint8_t Key_GetUpStatus(void) {
	uint8_t temp = UpStatus;	//��ȡ��ǰ״̬
	UpStatus = 1;			//�����ǰ״̬
	return temp;			//���ص�ǰ״̬
}

uint8_t Key_GetDownStatus(void) {
	uint8_t temp = DownStatus;	//��ȡ��ǰ״̬
	DownStatus = 1;			//�����ǰ״̬
	return temp;			//���ص�ǰ״̬
}


/**
 * @brief ������ʼ�����������ڳ�ʼ������GPIO
 * @param ��
 * @note GPIO����ʼ��Ϊ��������ģʽ����Ȼ���ҵĿ��������Ѿ��������������裬�����Է���һ��
 * @return ��
 */
void Key_Init(void)
{
}



/**
 * @brief ��������ʼ������������ʱ��1����Ϊ������ģʽ
 * @param ��
 * @return ��
 */
void Encoder_Init(void)
{
	
}


/**
 * @brief ������ʹ�ܺ���
 * @param ��
 * @return ��
 */
void Encoder_Enable(void)
{
}

/**
 * @brief ������ʧ�ܺ���
 * @param ��
 * @return ��
 */
void Encoder_Disable(void)
{

}

/**
 * @brief ��ȡ����������������ֵ���ı�Ƶ���룩
 * 
 * @details �ú���ͨ����ȡ��ʱ��TIM1�ļ���ֵ���Ա������źŽ����ı�Ƶ���봦��
 *          ʹ�þ�̬�����ۻ���������ͨ��������ȡģ����ȥ��������������֣�
 *          ȷ�����ؾ�ȷ������ֵ����Ҫ���ڵ�����ơ�λ�ü���Ӧ�ó�����
 * 
 * @note   �����ڲ����Զ����㶨ʱ������ֵ��ȷ���´ζ�ȡ��׼ȷ��
 * 
 * @return int16_t ���ؽ����ı���������ֵ
 */
int16_t Encoder_Get(void)
{
	int16_t tempEncoderAddition = EncoderAddition;	//���浱ǰ����ֵ 
	EncoderAddition = 0;	//��������ֵ
    return tempEncoderAddition;
}



/**
  * @brief  ΢�뼶��ʱ
  * @param  xus ��ʱʱ������Χ��0~233015
  * @retval ��
  */
void Delay_us(uint32_t xus)
{
	uint32_t start = micros();	//��ȡ��ǰʱ��
	while(micros() - start < xus)
	{
		//�ȴ���ʱ����
	}
}

/**
  * @brief  ���뼶��ʱ
  * @param  xms ��ʱʱ������Χ��0~4294967295
  * @retval ��
  */
void Delay_ms(uint32_t xms)
{
	while(xms--)
	{
		Delay_us(1000);
	}
}
 
/**
  * @brief  �뼶��ʱ
  * @param  xs ��ʱʱ������Χ��0~4294967295
  * @retval ��
  */
void Delay_s(uint32_t xs)
{
	while(xs--)
	{
		Delay_ms(1000);
	}
} 
