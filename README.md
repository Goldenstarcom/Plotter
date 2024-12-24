# Plotter

***hello world***
# eto russia
 so we want to tell you about
 - distance
 - addd
 - asd
 - dasd

* ye
    * ewe 2a
    * ewe

## this is our code log :

``` c++
#include <FastLED.h>
#define NUM_LEDS 8
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  int direction = 1; // 1 برای جلو رفتن، -1 برای برگشتن
  int currentLED = 0;
  int a=100;
  while (true) {
    // افزایش روشنایی
    for (float brightness = 0; brightness <= a; brightness+=0.4) {
      leds[currentLED] = CRGB(brightness, brightness, brightness);
      FastLED.show();
      delay(5);  // تاخیر برای افکت روشن‌شدن
    }

    // کاهش روشنایی
    for (int brightness = a; brightness >= 0; brightness-=1) {
      leds[currentLED] = CRGB(brightness, brightness, brightness);
      FastLED.show();
      delay(5);  // تاخیر برای افکت خاموش‌شدن
    }

    leds[currentLED] = CRGB::Black; // اطمینان از خاموشی LED فعلی

    // حرکت به LED بعدی بر اساس جهت
    currentLED += direction;

    // تغییر جهت در صورت رسیدن به ابتدا یا انتها
    if (currentLED == NUM_LEDS - 1 || currentLED == 0) {
      direction = -direction;
    }
  }
}
```
































