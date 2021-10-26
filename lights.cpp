
#include <Adafruit_NeoPixel.h>

int neoPixelPin = 3;

int numPixels = 130;

Adafruit_NeoPixel strip =
    Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

int r = 0;
int g = 40;
int b = 255;

void setup() {
    strip.begin();
    strip.show();
    strip.clear();
}

void loop() {
    for (int i = 0; i < numPixels; i++)
        strip.setPixelColor(i, r, g, b);

    strip.show();
    delay(10);
}
