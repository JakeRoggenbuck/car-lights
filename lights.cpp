#include <FastLED.h>

#define PIXEL_PIN 2
#define PIXEL_NUM 300
#define HALF_WAY (PIXEL_NUM / 2)

CRGB leds[PIXEL_NUM];

struct Color {
    int R;
    int G;
    int B;
};

struct Color ORANGE = {255, 50, 0};
struct Color WHITE = {255, 255, 255};

typedef enum {
    LEFT,
    RIGHT,
} TurnDirection;

void setup() {
    FastLED.addLeds<WS2812B, PIXEL_PIN, GRB>(leds, PIXEL_NUM);
    FastLED.setBrightness(100);
    Serial.begin(57600);
}

void off() {
    for (int i = 0; i < PIXEL_NUM; i++) {
        leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
}

void set_color(int i, Color color, int time_delay) {
    leds[i] = CRGB(color.R, color.G, color.B);
    delay(time_delay);
    FastLED.show();
}

void turn(int direction, int times, int time_delay) {
    for (int j = 0; j < times; j++) {
        if (direction == RIGHT) {
            for (int i = 0; i < HALF_WAY; i++) {
                set_color(i, ORANGE, time_delay);
            }
        } else if (direction == LEFT) {
            for (int i = HALF_WAY; i < PIXEL_NUM; i++) {
                set_color(i, ORANGE, time_delay);
            }
        }
    }

    delay(50);
    off();
}

void loop() {
    turn(RIGHT, 1, 2);
    turn(LEFT, 1, 2);
}
