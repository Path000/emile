#ifndef Ecran_h
#define Ecran_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define OLED_RESET 4

class Ecran {
	public:
		void init();
		void welcome();
		void orientation(int x, int y, int z);
		void clear();
		void eyes();
		void showCommand(char *name, uint8_t pos);
		void showCommandStart();
	private:
};

#endif
