#include <Adafruit_NeoPixel.h>

int pixel_pin = 6;
int pixel_num = 50;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixel_num, pixel_pin, NEO_GRB + NEO_KHZ800);


void setup() {
	strip.begin();
	strip.show();
	strip.clear();
}

void loop() {
	for(int i = 0; i < pixel_num; i++) {
		strip.setPixelColor(i, 0, 40, 255);
		delay(0.5);
		strip.show();
	}

	delay(10);

	for(int i = pixel_num; i > 0; i--) {
		strip.setPixelColor(i, 80, 0, 0);
		delay(0.5);
		strip.show();
	}

	delay(10);
}
