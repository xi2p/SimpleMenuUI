/*
* @author  :  xi2p
*/
#include "OLED_UI.h"
#include "OLED_UI_MenuData.h"
#include <Arduino.h>


hw_timer_t *timer = nullptr;

void setup()
{
	timer = timerBegin(0, 80, true); // 80 prescaler for 1us timer
	timerAttachInterrupt(timer, &OLED_UI_InterruptHandler, true);
	timerAlarmWrite(timer, 20000, true); // 20ms
	timerAlarmEnable(timer);
	Serial.begin(115200);

	OLED_UI_Init(&MainMenuPage);
}

void loop()
{
	OLED_UI_MainLoop();
	if (Serial.available())
	{
		uint8_t data = 0;
		Serial.read(&data, 1);	//接收数据
		if (data == 0x00)
		{
			EncoderAddition++;
		}
		else if (data == 0x01)
		{
			EncoderAddition--;
		}
		else if (data == 0x02)
		{
			EnterStatus = 0;
		}
		else if (data == 0x03)
		{
			BackStatus = 0;
		}
		else if (data == 0x04)
		{
			UpStatus = 0;
		}
		else if (data == 0x05)
		{
			DownStatus = 0;
		}
	}

}
