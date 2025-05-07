/*
 * @author  :  xi2p
 * This file is based on the work of the following authors:
 * @file	:  OLED_driver.h https://github.com/bdth-7777777/OLED_UI
 */
#ifndef __OLED_DRIVER_H
#define __OLED_DRIVER_H

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

//	oled��ʼ������
void OLED_Init(void);
// ������ɫģʽ
void OLED_SetColorMode(bool colormode);
//	oledȫ��ˢ�º���
void OLED_Update(void);
//	oled�ֲ�ˢ�º���
void OLED_UpdateArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height);


// OLED �������Ⱥ���
void OLED_Brightness(int16_t Brightness);







#endif







