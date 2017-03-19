#include "Ecran.h"

Adafruit_SSD1306 display(OLED_RESET);

void Ecran::init() {
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void Ecran::welcome() {
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.setTextSize(1);
	display.println("Hello");
	display.println("");
	display.setTextSize(2);
	display.println("Emile !!!");
	display.display();
}

void Ecran::eyes() {
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.println(" O O");
	display.println("  _ ");
	display.display();
}

void Ecran::orientation(int x, int y, int z) {
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.print("x:");
	display.println(x);
	display.print("y:");
	display.println(y);
	display.print("z:");
	display.println(z);
	display.display();
}

void Ecran::clear() {
	display.clearDisplay();
	display.display();
}

void Ecran::showCommand(ParsedCommand command) {
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.print("Cmd:");
	display.println(command.cmd);
	display.print("index:");
	display.println(command.arrayArgs[0].toInt());
	display.print("angle:");
	display.println(command.arrayArgs[1].toInt());
	display.display();
}