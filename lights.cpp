#include <Adafruit_NeoPixel.h>

int PIXEL_PIN = 6;
int PIXEL_NUM = 50;
int HALF_WAY = PIXEL_NUM / 2;

Adafruit_NeoPixel STRIP =
    Adafruit_NeoPixel(PIXEL_NUM, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

struct Color {
    int R;
    int G;
    int B;
}

struct Color ORANGE = {210, 140, 20};
struct Color WHITE = {255, 255, 255};

void setup() {
    STRIP.begin();
    STRIP.show();
    STRIP.clear();
}

enum TurnDirection {
	LEFT,
	RIGHT,
}

void off() {
    for (int i = 0; i < PIXEL_NUM; i++)
        STRIP.setPixelColor(i, 0, 0, 0);
    STRIP.show();
}

void turn(TurnDirection direction, int times) {
    for (int j = 0; j < times; j++) {
		if (direction == TurnDirection::LEFT) {
			for (int i = 0; i < HALF_WAY; i++) {
				STRIP.setPixelColor(i, ORANGE.R, ORANGE.G, ORANGE.b);
				delay(0.06);
				STRIP.show();
			}
		} else if (direction == TurnDirection::Right) {
			for (int i = HALF_WAY; i < PIXEL_NUM; i++) {
				STRIP.setPixelColor(i, ORANGE.R, ORANGE.G, ORANGE.b);
				delay(0.5);
				STRIP.show();
			}
		}
	}

	delay(1);
	off();
}

void loop() {
	turn(TurnDirection::LEFT);
}
