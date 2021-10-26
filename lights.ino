
#include <Adafruit_NeoPixel.h>
 
// the data pin for the NeoPixels
int neoPixelPin = 3;

// How many NeoPixels we will be using, charge accordingly
int numPixels = 130;

// Instatiate the NeoPixel from the ibrary
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

// Global RGB values, change to suit your needs
int r = 0;
int g = 40;
int b = 255;

void setup() {
  strip.begin();  // initialize the strip
  strip.show();   // make sure it is visible
  strip.clear();  // Initialize all pixels to 'off'
}

void loop() {
   // set the colors for the strip
   for( int i = 0; i < numPixels; i++ )
       strip.setPixelColor(i, r, g, b);
   
   // show all pixels  
   strip.show();
   
   // wait for a short amount of time -- sometimes a short delay of 5ms will help
   // technically we only need to execute this one time, since we aren't changing the colors but we will build on this structure
   delay(10);
}
