/*
* @author  :  xi2p
* This file is based on the work of the following authors:
* @file	:  OLED_driver.c https://github.com/bdth-7777777/OLED_UI
*/

/*
 * ���ͷ�ļ���oled��� [Ӳ����] ʵ���ļ�����ֲ��ʱ����Ҫ��������ļ�������
*/
#include "OLED_driver.h"
#include <Arduino.h>


uint8_t OLED_DisplayBuf[64/8][128];

bool OLED_ColorMode = true;

/**
  * ��    ����OLEDдSCL�ߵ͵�ƽ
  * ��    ����Ҫд��SCL�ĵ�ƽֵ����Χ��0/1
  * �� �� ֵ����
  * ˵    �������ϲ㺯����ҪдSCLʱ���˺����ᱻ����
  *           �û���Ҫ���ݲ��������ֵ����SCL��Ϊ�ߵ�ƽ���ߵ͵�ƽ
  *           ����������0ʱ����SCLΪ�͵�ƽ������������1ʱ����SCLΪ�ߵ�ƽ
  */
void OLED_W_SCL(uint8_t BitValue)
{
	/*����BitValue��ֵ����SCL�øߵ�ƽ���ߵ͵�ƽ*/
	digitalWrite(23, BitValue);

	
	/*�����Ƭ���ٶȹ��죬���ڴ����������ʱ���Ա��ⳬ��I2Cͨ�ŵ�����ٶ�*/
	//...
}

/**
  * ��    ����OLEDдSDA�ߵ͵�ƽ
  * ��    ����Ҫд��SDA�ĵ�ƽֵ����Χ��0/1
  * �� �� ֵ����
  * ˵    �������ϲ㺯����ҪдSDAʱ���˺����ᱻ����
  *           �û���Ҫ���ݲ��������ֵ����SDA��Ϊ�ߵ�ƽ���ߵ͵�ƽ
  *           ����������0ʱ����SDAΪ�͵�ƽ������������1ʱ����SDAΪ�ߵ�ƽ
  */
void OLED_W_SDA(uint8_t BitValue)
{
	/*����BitValue��ֵ����SDA�øߵ�ƽ���ߵ͵�ƽ*/
	digitalWrite(22, BitValue);
	/*�����Ƭ���ٶȹ��죬���ڴ����������ʱ���Ա��ⳬ��I2Cͨ�ŵ�����ٶ�*/
	//...
}

/*ͨ��Э��*********************/

/**
  * ��    ����I2C��ʼ
  * ��    ������
  * �� �� ֵ����
  */
void OLED_I2C_Start(void)
{

	
	OLED_W_SDA(1);		//�ͷ�SDA��ȷ��SDAΪ�ߵ�ƽ
	OLED_W_SCL(1);		//�ͷ�SCL��ȷ��SCLΪ�ߵ�ƽ
	OLED_W_SDA(0);		//��SCL�ߵ�ƽ�ڼ䣬����SDA��������ʼ�ź�
	OLED_W_SCL(0);		//��ʼ���SCLҲ���ͣ���Ϊ��ռ�����ߣ�ҲΪ�˷�������ʱ���ƴ��
}

/**
  * ��    ����I2C��ֹ
  * ��    ������
  * �� �� ֵ����
  */
void OLED_I2C_Stop(void)
{
	
	OLED_W_SDA(0);		//����SDA��ȷ��SDAΪ�͵�ƽ
	OLED_W_SCL(1);		//�ͷ�SCL��ʹSCL���ָߵ�ƽ
	OLED_W_SDA(1);		//��SCL�ߵ�ƽ�ڼ䣬�ͷ�SDA��������ֹ�ź�
}


/**
  * ��    ����I2C����һ���ֽ�
  * ��    ����Byte Ҫ���͵�һ���ֽ����ݣ���Χ��0x00~0xFF
  * �� �� ֵ����
  */
void OLED_I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	
	/*ѭ��8�Σ��������η������ݵ�ÿһλ*/
	for (i = 0; i < 8; i++)
	{
		/*ʹ������ķ�ʽȡ��Byte��ָ��һλ���ݲ�д�뵽SDA��*/
		/*����!�������ǣ������з����ֵ��Ϊ1*/
		OLED_W_SDA(!!(Byte & (0x80 >> i)));
		OLED_W_SCL(1);	//�ͷ�SCL���ӻ���SCL�ߵ�ƽ�ڼ��ȡSDA
		OLED_W_SCL(0);	//����SCL��������ʼ������һλ����
	}
	
	OLED_W_SCL(1);		//�����һ��ʱ�ӣ�������Ӧ���ź�
	OLED_W_SCL(0);
}

/**
  * ��    ����OLEDд����
  * ��    ����Command Ҫд�������ֵ����Χ��0x00~0xFF
  * �� �� ֵ����
  */
void OLED_WriteCommand(uint8_t Command)
{
	OLED_I2C_Start();				//I2C��ʼ
	OLED_I2C_SendByte(0x78);		//����OLED��I2C�ӻ���ַ
	OLED_I2C_SendByte(0x00);		//�����ֽڣ���0x00����ʾ����д����
	OLED_I2C_SendByte(Command);		//д��ָ��������
	OLED_I2C_Stop();				//I2C��ֹ
}
/**
 * @brief ������ʾģʽ
 * @param colormode true: ��ɫģʽ��false: ��ɫģʽ
 * @return ��
 */
void OLED_SetColorMode(bool colormode){
	OLED_ColorMode = colormode;
}
/**
  * ��    ����OLEDд����
  * ��    ����Data Ҫд�����ݵ���ʼ��ַ
  * ��    ����Count Ҫд�����ݵ�����
  * �� �� ֵ����
  */
void OLED_WriteData(uint8_t *Data, uint8_t Count)
{
	uint8_t i;
	
	OLED_I2C_Start();				//I2C��ʼ
	OLED_I2C_SendByte(0x78);		//����OLED��I2C�ӻ���ַ
	OLED_I2C_SendByte(0x40);		//�����ֽڣ���0x40����ʾ����д����
	/*ѭ��Count�Σ���������������д��*/
	for (i = 0; i < Count; i ++)
	{
		if(OLED_ColorMode){
			OLED_I2C_SendByte(Data[i]);	//���η���Data��ÿһ������
		}else{
			OLED_I2C_SendByte(~Data[i]);	//���η���Data��ÿһ������
		}
	}
	OLED_I2C_Stop();				//I2C��ֹ
}

/*********************ͨ��Э��*/




/**
  * ��    ����OLED���ų�ʼ��
  * ��    ������
  * �� �� ֵ����
  * ˵    �������ϲ㺯����Ҫ��ʼ��ʱ���˺����ᱻ����
  *           �û���Ҫ��SCL��SDA���ų�ʼ��Ϊ��©ģʽ�����ͷ�����
  */
void OLED_GPIO_Init(void)
{
	uint32_t i, j;
	
	/*�ڳ�ʼ��ǰ������������ʱ����OLED�����ȶ�*/
	for (i = 0; i < 1000; i ++)
	{
		for (j = 0; j < 1000; j ++);
	}
	
	pinMode(22, OUTPUT_OPEN_DRAIN);	//����SDA����Ϊ��©���
	pinMode(23, OUTPUT_OPEN_DRAIN);	//����SCL����Ϊ��©���
	
	/*�ͷ�SCL��SDA*/
	OLED_W_SCL(1);
	OLED_W_SDA(1);
}
/**
  * ��    ����OLED������ʾ���λ��
  * ��    ����Page ָ��������ڵ�ҳ����Χ��0~7
  * ��    ����X ָ��������ڵ�X�����꣬��Χ��0~127
  * �� �� ֵ����
  * ˵    ����OLEDĬ�ϵ�Y�ᣬֻ��8��BitΪһ��д�룬��1ҳ����8��Y������
  */
void OLED_SetCursor(uint8_t Page, uint8_t X)
{
	/*���ʹ�ô˳�������1.3���OLED��ʾ��������Ҫ�����ע��*/
	/*��Ϊ1.3���OLED����оƬ��SH1106����132��*/
	/*��Ļ����ʼ�н����˵�2�У������ǵ�0��*/
	/*������Ҫ��X��2������������ʾ*/
//	X += 2;
	
	/*ͨ��ָ������ҳ��ַ���е�ַ*/
	OLED_WriteCommand(0xB0 | Page);					//����ҳλ��
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));	//����Xλ�ø�4λ
	OLED_WriteCommand(0x00 | (X & 0x0F));			//����Xλ�õ�4λ
}
void OLED_Clear(void);
/**
  * ��    ����OLED��ʼ��
  * ��    ������
  * �� �� ֵ����
  * ˵    ����ʹ��ǰ����Ҫ���ô˳�ʼ������
  */
void OLED_Init(void)
{
	OLED_GPIO_Init();			//�ȵ��õײ�Ķ˿ڳ�ʼ��
	
	/*д��һϵ�е������OLED���г�ʼ������*/
	OLED_WriteCommand(0xAE);	//������ʾ����/�رգ�0xAE�رգ�0xAF����
	
	OLED_WriteCommand(0xD5);	//������ʾʱ�ӷ�Ƶ��/����Ƶ��
	OLED_WriteCommand(0xf0);	//0x00~0xFF
	
	OLED_WriteCommand(0xA8);	//���ö�·������
	OLED_WriteCommand(0x3F);	//0x0E~0x3F
	
	OLED_WriteCommand(0xD3);	//������ʾƫ��
	OLED_WriteCommand(0x00);	//0x00~0x7F
	
	OLED_WriteCommand(0x40);	//������ʾ��ʼ�У�0x40~0x7F
	
	OLED_WriteCommand(0xA1);	//�������ҷ���0xA1������0xA0���ҷ���
	
	OLED_WriteCommand(0xC8);	//�������·���0xC8������0xC0���·���

	OLED_WriteCommand(0xDA);	//����COM����Ӳ������
	OLED_WriteCommand(0x12);
	
	OLED_WriteCommand(0x81);	//���öԱȶ�
	OLED_WriteCommand(0xDF);	//0x00~0xFF

	OLED_WriteCommand(0xD9);	//����Ԥ�������
	OLED_WriteCommand(0xF1);

	OLED_WriteCommand(0xDB);	//����VCOMHȡ��ѡ�񼶱�
	OLED_WriteCommand(0x30);

	OLED_WriteCommand(0xA4);	//����������ʾ��/�ر�

	OLED_WriteCommand(0xA6);	//��������/��ɫ��ʾ��0xA6������0xA7��ɫ

	OLED_WriteCommand(0x8D);	//���ó���
	OLED_WriteCommand(0x14);

	OLED_WriteCommand(0xAF);	//������ʾ
	
	OLED_Clear();				//����Դ�����
	OLED_Update();				//������ʾ����������ֹ��ʼ����δ��ʾ����ʱ����
}
/**
  * ��    ������OLED�Դ�������µ�OLED��Ļ
  * ��    ������
  * �� �� ֵ����
  * ˵    �������е���ʾ��������ֻ�Ƕ�OLED�Դ�������ж�д
  *           ������OLED_Update������OLED_UpdateArea����
  *           �ŻὫ�Դ���������ݷ��͵�OLEDӲ����������ʾ
  *           �ʵ�����ʾ������Ҫ�������س�������Ļ�ϣ�������ø��º���
  */
void OLED_Update(void)
{
	uint8_t j;
	/*����ÿһҳ*/
	for (j = 0; j < 8; j ++)
	{
		/*���ù��λ��Ϊÿһҳ�ĵ�һ��*/
		OLED_SetCursor(j, 0);
		/*����д��128�����ݣ����Դ����������д�뵽OLEDӲ��*/
		OLED_WriteData(OLED_DisplayBuf[j], 128);
	}
	
	
}

/**
  * ��    ����OLED��������
  * ��    ����Brightness ��0-255����ͬ��ʾоƬЧ�����ܲ���ͬ��
  * �� �� ֵ����
  * ˵    ������Ҫ���ù�����߹�С��
  */
void OLED_Brightness(int16_t Brightness){
	if(Brightness>255){
		Brightness=255;
	}
	if(Brightness<0){
		Brightness=0;
	}
	OLED_WriteCommand(0x81);
	OLED_WriteCommand(Brightness);
}
/**
  * ��    ������OLED�Դ����鲿�ָ��µ�OLED��Ļ
  * ��    ����X ָ���������Ͻǵĺ����꣬��Χ��0~OLED_WIDTH-1
  * ��    ����Y ָ���������Ͻǵ������꣬��Χ��0~OLED_HEIGHT-1
  * ��    ����Width ָ������Ŀ�ȣ���Χ��0~OLED_WIDTH
  * ��    ����Height ָ������ĸ߶ȣ���Χ��0~OLED_HEIGHT
  * �� �� ֵ����
  * ˵    �����˺��������ٸ��²���ָ��������
  *           �����������Y��ֻ��������ҳ����ͬһҳ��ʣ�ಿ�ֻ����һ�����
  * ˵    �������е���ʾ��������ֻ�Ƕ�OLED�Դ�������ж�д
  *           ������OLED_Update������OLED_UpdateArea����
  *           �ŻὫ�Դ���������ݷ��͵�OLEDӲ����������ʾ
  *           �ʵ�����ʾ������Ҫ�������س�������Ļ�ϣ�������ø��º���
  */
void OLED_UpdateArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height)
{
	uint8_t j;
	
	/*������飬��ָ֤�����򲻻ᳬ����Ļ��Χ*/
	if (X > 128-1) {return;}
	if (Y > 64-1) {return;}
	if (X + Width > 128) {Width = 128 - X;}
	if (Y + Height > 64) {Height = 64 - Y;}
	
	/*����ָ�������漰�����ҳ*/
	/*(Y + Height - 1) / 8 + 1��Ŀ����(Y + Height) / 8������ȡ��*/
	for (j = Y / 8; j < (Y + Height - 1) / 8 + 1; j ++)
	{
		/*���ù��λ��Ϊ���ҳ��ָ����*/
		OLED_SetCursor(j, X);
		/*����д��Width�����ݣ����Դ����������д�뵽OLEDӲ��*/
		OLED_WriteData(&OLED_DisplayBuf[j][X], Width);
	}
	
}







