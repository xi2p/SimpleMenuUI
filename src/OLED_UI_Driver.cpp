/*
* @author  :  xi2p
* This file is based on the work of the following authors:
* @file	:  OLED_UI_Driver.c https://github.com/bdth-7777777/OLED_UI
*/
#include "OLED_UI_Driver.h"

/*
【文件说明】：[硬件抽象层]
此文件包含按键与编码器的驱动程序，如果需要移植此项目，请根据实际情况修改相关代码。
当你确保oled屏幕能够正常点亮，并且能够正确地运行基础功能时（如显示字符串等），就可以开始移植
有关按键与编码器等的驱动程序了。
*/

int16_t EncoderAddition = 0;	//编码器增量值
uint8_t EnterStatus = 1;
uint8_t BackStatus = 1;
uint8_t UpStatus = 1;
uint8_t DownStatus = 1;

uint8_t Key_GetEnterStatus(void) {
	uint8_t temp = EnterStatus;	//获取当前状态
	EnterStatus = 1;			//清除当前状态
	return temp;			//返回当前状态
}

uint8_t Key_GetBackStatus(void) {
	uint8_t temp = BackStatus;	//获取当前状态
	BackStatus = 1;			//清除当前状态
	return temp;			//返回当前状态
}

uint8_t Key_GetUpStatus(void) {
	uint8_t temp = UpStatus;	//获取当前状态
	UpStatus = 1;			//清除当前状态
	return temp;			//返回当前状态
}

uint8_t Key_GetDownStatus(void) {
	uint8_t temp = DownStatus;	//获取当前状态
	DownStatus = 1;			//清除当前状态
	return temp;			//返回当前状态
}


/**
 * @brief 按键初始化函数，用于初始化按键GPIO
 * @param 无
 * @note GPIO被初始化为上拉输入模式（虽然在我的开发板上已经加上了上拉电阻，但是以防万一）
 * @return 无
 */
void Key_Init(void)
{
}



/**
 * @brief 编码器初始化函数，将定时器1配置为编码器模式
 * @param 无
 * @return 无
 */
void Encoder_Init(void)
{
	
}


/**
 * @brief 编码器使能函数
 * @param 无
 * @return 无
 */
void Encoder_Enable(void)
{
}

/**
 * @brief 编码器失能函数
 * @param 无
 * @return 无
 */
void Encoder_Disable(void)
{

}

/**
 * @brief 获取编码器的增量计数值（四倍频解码）
 * 
 * @details 该函数通过读取定时器TIM1的计数值，对编码器信号进行四倍频解码处理。
 *          使用静态变量累积计数，并通过除法和取模运算去除多余的增量部分，
 *          确保返回精确的增量值。主要用于电机控制、位置检测等应用场景。
 * 
 * @note   函数内部会自动清零定时器计数值，确保下次读取的准确性
 * 
 * @return int16_t 返回解码后的编码器增量值
 */
int16_t Encoder_Get(void)
{
	int16_t tempEncoderAddition = EncoderAddition;	//保存当前增量值 
	EncoderAddition = 0;	//清零增量值
    return tempEncoderAddition;
}



/**
  * @brief  微秒级延时
  * @param  xus 延时时长，范围：0~233015
  * @retval 无
  */
void Delay_us(uint32_t xus)
{
	uint32_t start = micros();	//获取当前时间
	while(micros() - start < xus)
	{
		//等待延时结束
	}
}

/**
  * @brief  毫秒级延时
  * @param  xms 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_ms(uint32_t xms)
{
	while(xms--)
	{
		Delay_us(1000);
	}
}
 
/**
  * @brief  秒级延时
  * @param  xs 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_s(uint32_t xs)
{
	while(xs--)
	{
		Delay_ms(1000);
	}
} 
