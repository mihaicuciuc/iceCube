#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>
#include <USIWire.h>
#include "myds3231.h"

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    A2

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 24

// each color R, G, B
// Each map {colorH, colorM, colorFace1, colorFace2}
const uint8_t colorMapArray[][3][12] PROGMEM = {
// Map 0, Default
 {
  {20, 20, 0,   0, 5, 35,   1, 1, 1,   1, 0, 0},   // Low intensity
  {30, 30, 0,   0, 17, 43,  2, 2, 2,   2, 0, 0},   // Mid intensity
  {40, 40, 0,   0, 20, 60,  5, 5, 5,   5, 0, 0},   // High intensity
 },
// Map 1, Captain America
 {
  {40, 0, 0,    0, 0, 40,    1, 1, 1,   1, 1, 1},   // Low intensity
  {60, 0, 0,    0, 0, 60,    2, 2, 2,   2, 2, 2},   // Mid intensity
  {80, 0, 0,    0, 0, 80,    3, 3, 3,   3, 3, 3},   // High intensity
 },
// Map 2, Joker Old
 {
  {40, 0, 0,    0, 40, 0,    1, 1, 1,   1, 0, 2},   // Low intensity
  {60, 0, 0,    0, 60, 0,    2, 2, 2,   2, 0, 4},   // Mid intensity
  {80, 0, 0,    0, 80, 0,    3, 3, 3,   3, 0, 6},   // High intensity
 },
// Map 3, Joker New
 {
  {40, 0, 0,    0, 0, 40,    2, 1, 0,   4, 1, 0},   // Low intensity
  {60, 0, 0,    0, 0, 60,    4, 2, 0,   6, 2, 0},   // Mid intensity
  {80, 0, 0,    0, 0, 80,    6, 3, 0,   8, 3, 0},   // High intensity
 },
// Map 4, Dr Strange
 {
  {20, 20, 0,   0, 0, 40,    1, 0, 0,   1, 0, 0},   // Low intensity
  {30, 30, 0,   0, 0, 60,    2, 0, 0,   2, 0, 0},   // Mid intensity
  {40, 40, 0,   0, 0, 80,    5, 0, 0,   5, 0, 0},   // High intensity
 },
// Map 5, Purple love
 {
  {0, 10, 30,   15, 0, 30,    1, 0, 2,   1, 0, 2},   // Low intensity
  {0, 20, 40,   25, 0, 40,    2, 0, 4,   2, 0, 4},   // Mid intensity
  {0, 30, 50,   35, 0, 50,    3, 0, 6,   3, 0, 6},   // High intensity
 },
// Map 6, Crystal blue
 {
  {15, 15, 0,   0, 15, 15,    0, 1, 1,   0, 1, 1},   // Low intensity
  {25, 25, 0,   0, 25, 25,    0, 2, 2,   0, 2, 2},   // Mid intensity
  {35, 35, 0,   0, 35, 35,    0, 3, 3,   0, 3, 3},   // High intensity
 },
// Map 7, Cool blue
 {
  {10, 10, 10,   0, 0, 30,    0, 0, 1,   0, 0, 1},   // Low intensity
  {17, 17, 17,   0, 0, 50,    0, 0, 2,   0, 0, 2},   // Mid intensity
  {23, 23, 23,   0, 0, 70,    0, 0, 5,   0, 0, 5},   // High intensity
 },
// Map 8, Firy red
 {
  {30, 10, 0,   30, 0, 0,    1, 0, 0,   1, 0, 0},   // Low intensity
  {40, 20, 0,   50, 0, 0,    2, 0, 0,   2, 0, 0},   // Mid intensity
  {50, 30, 0,   70, 0, 0,    5, 0, 0,   5, 0, 0},   // High intensity
 },
// Map 9, Emerald green
 {
  {0, 20, 20,   0, 30, 0,    0, 1, 0,   0, 1, 0},   // Low intensity
  {0, 30, 30,   0, 50, 0,    0, 2, 0,   0, 2, 0},   // Mid intensity
  {0, 40, 40,   0, 70, 0,    0, 5, 0,   0, 5, 0},   // High intensity
 },
// Map 10, Yellow submarine
 {
  {5, 35, 0,   15, 15, 0,    1, 1, 0,   1, 1, 0},   // Low intensity
  {10, 50, 0,   25, 25, 0,    2, 2, 0,   2, 2, 0},   // Mid intensity
  {20, 60, 0,   35, 35, 0,    3, 3, 0,   3, 3, 0},   // High intensity
 },
// Map 11, Cheshire Cat
 {
  {0, 10, 30,   0, 30, 0,    1, 1, 1,   0, 0, 0},   // Low intensity
  {0, 20, 40,   0, 50, 0,    2, 2, 2,   0, 0, 0},   // Mid intensity
  {0, 30, 50,   0, 70, 0,    3, 3, 3,   0, 0, 0},   // High intensity
 },
// Map 12, Dali
 {
  {15, 15, 0,   0, 15, 15,    0, 0, 0,   0, 0, 0},   // Low intensity
  {25, 25, 0,   0, 25, 25,    0, 0, 0,   0, 0, 0},   // Mid intensity
  {35, 35, 0,   0, 35, 35,    0, 0, 0,   0, 0, 0},   // High intensity
 },
};


ts t; //ts is a struct findable in ds3231.h
uint32_t color;
uint32_t colorH[3], colorM[3], colorFace1[3], colorFace2[3];
uint16_t adcVal = 0, adcThr[2];
uint8_t colorMap = 0, colorIdx = 0, ledOffset = 0;
uint8_t state = 0;
uint8_t i;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void(* reset) (void) = 0;

void setup()
{
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pinMode(1, INPUT);
  digitalWrite(1, HIGH);
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP

  Wire.begin(); //start i2c (required for connection)
  DS3231_init(DS3231_INTCN); //register the ds3231 (DS3231_INTCN is the default address of ds3231, this is set by macro for no performance loss)

  if (EEPROM.read(0) != 0x00)
  {
    // New chip. Set up factory defaults
    factoryDefaults();
  }
  adcThr[0] = EEPROM.read(1);
  adcThr[1] = EEPROM.read(2);
  ledOffset = EEPROM.read(3);
  colorMap = EEPROM.read(4);

  readColorMap(colorMap);

  colorIdx = 0;
}

void factoryDefaults()
{
    EEPROM.write(1, 0x09);  // Low brightness threshold
    EEPROM.write(2, 0x11);  // Mid brightness threshold
    EEPROM.write(3, 0x00);  // LED ring orientation
    EEPROM.write(4, 0x00);  // Color map
    EEPROM.write(0, 0x00);  // configured flag
    reset();
}

void readColorMap(uint8_t m)
{
  for (i = 0; i < 3; i++)
  {
    colorH[i] = strip.Color(pgm_read_byte(&colorMapArray[m][i][0]), pgm_read_byte(&colorMapArray[m][i][1]), pgm_read_byte(&colorMapArray[m][i][2]));
    colorM[i] = strip.Color(pgm_read_byte(&colorMapArray[m][i][3]), pgm_read_byte(&colorMapArray[m][i][4]), pgm_read_byte(&colorMapArray[m][i][5]));
    colorFace1[i] = strip.Color(pgm_read_byte(&colorMapArray[m][i][6]), pgm_read_byte(&colorMapArray[m][i][7]), pgm_read_byte(&colorMapArray[m][i][8]));
    colorFace2[i] = strip.Color(pgm_read_byte(&colorMapArray[m][i][9]), pgm_read_byte(&colorMapArray[m][i][10]), pgm_read_byte(&colorMapArray[m][i][11]));
  }
}

void loop()
{
  static unsigned long buttonTimeStamp = 0, buttonFallingEdge = 0, buttonLen = 0;
  static uint8_t buttonState = 1;
  static uint8_t buttonPressed = 0;
  static uint8_t oldState;

  adcVal = analogRead(A3) / 40;
  if (adcVal < adcThr[0])
  {
    colorIdx = 0;
  }

  // Histeresis implemented through truncation. When adcVal == adcThr[0] do nothing. This happens for 40 ADC counts.
  if ((adcVal > adcThr[0]) && (adcVal < adcThr[1]))
  {
    colorIdx = 1;
  }

  if (adcVal > adcThr[1])
  {
    colorIdx = 2;
  }

  if ((digitalRead(1) == 0) && (buttonState == 1))
  {
    // Button falling edge
    buttonTimeStamp = millis();
    buttonFallingEdge = buttonTimeStamp;
    buttonState = 0;
  }

  oldState = state;
  
  if ((digitalRead(1) == 1) && (buttonState == 0))
  {
    // Button rising edge
    buttonTimeStamp = millis();
    buttonLen = buttonTimeStamp - buttonFallingEdge;
    buttonState = 1;
    
    if (buttonLen > 10000)
    {
      // very long press
      factoryDefaults();
    }
    else if (buttonLen > 1000)
    {
      // long press
      state++;
    }
    else if (buttonLen > 50)
    {
      // short press
      buttonPressed = 1;
    }
  }

  if ((millis() - buttonTimeStamp) >= 5000)
  {
    if ((state != 5) && (state != 6))
    {
      state = 0;
    }
  }

  if (oldState != state)
  {
    // Handle state transition actions here.
    if (3 == oldState) EEPROM.write(4, colorMap);
    if (4 == oldState) EEPROM.write(3, ledOffset);
    if (5 == oldState) EEPROM.write(1, adcThr[0]);
    if (6 == oldState) EEPROM.write(2, adcThr[1]);
    if (0 == state) showAnimation();
  }

  switch (state)
  {
    case 0:    // default clock run state
      if (buttonPressed == 1) showAnimation();
      runClock();
      break;
    case 1:
      runSetH(buttonPressed);
      break;
    case 2:
      runSetM(buttonPressed);
      break;
    case 3:
      runSetColorMap(buttonPressed);
      break;
    case 4:
      runSetOrientation(buttonPressed);
      break;
    case 5:
      runSetBrightness(0, buttonPressed);
      break;
    case 6:
      runSetBrightness(1, buttonPressed);
      break;
  }

  buttonPressed = 0;
}


void runSetColorMap(uint8_t buttonPressed)
{
  if (buttonPressed != 0)
  {
    colorMap++;
    colorMap %= sizeof(colorMapArray) / (sizeof(uint8_t)*3*12);
    readColorMap(colorMap);
  }
  
  strip.clear();
  setColor(2, colorM[colorIdx]);
  setColor(3, colorM[colorIdx]);
  setColor(4, colorM[colorIdx]);

  setColor(20, colorH[colorIdx]);
  setColor(21, colorH[colorIdx]);
  setColor(22, colorH[colorIdx]);

  setColor(6, colorFace1[colorIdx]);
  setColor(12, colorFace1[colorIdx]);
  setColor(18, colorFace1[colorIdx]);

  setColor(8, colorFace2[colorIdx]);
  setColor(10, colorFace2[colorIdx]);
  setColor(14, colorFace2[colorIdx]);
  setColor(16, colorFace2[colorIdx]);
  strip.show();
}


void runSetOrientation(uint8_t buttonPressed)
{
  if (buttonPressed != 0)
  {
    ledOffset++;
    ledOffset %= 24;
  }
  
  strip.clear();
  setColor(0, colorFace1[colorIdx]);
  setColor(11, colorFace2[colorIdx]);
  setColor(12, colorFace2[colorIdx]);
  setColor(13, colorFace2[colorIdx]);
  strip.show();
}


void runSetH(uint8_t buttonPressed)
{
  DS3231_get(&t);
  t.hour += buttonPressed;
  if (t.hour > 23) t.hour = 0;
  DS3231_set(t);

  strip.clear();
  // draw clock face
  setColor(0, colorFace1[colorIdx]);
  setColor(12, colorFace1[colorIdx]);
  setColor((t.hour % 12) * 2, colorH[colorIdx]);
  strip.show();
}

void runSetM(uint8_t buttonPressed)
{
  uint8_t ledM;
  
  DS3231_get(&t);
  if (buttonPressed != 0)
  {
    t.min += 1;
    if (t.min > 59) t.min = 0;
    t.sec = 0;
    DS3231_set(t);
  }

  ledM = (t.min / 10) * 4;
  
  strip.clear();
  // draw clock face
  setColor(0, colorFace1[colorIdx]);
  setColor(6, colorFace1[colorIdx]);
  setColor(12, colorFace1[colorIdx]);
  setColor(18, colorFace1[colorIdx]);
  setColor(ledM, colorM[colorIdx]);
  for (i = 0; i < (t.min % 10); i++)
  {
    setColor((ledM + i + 1) % 24, colorFace2[colorIdx]);
  }
  strip.show();
}

void runSetBrightness(uint8_t thrIdx, uint8_t buttonPressed)
{
  uint32_t color;
  uint8_t led;

  if (buttonPressed == 1)
  {
    adcThr[thrIdx] += 1;
    if (adcThr[thrIdx] >= 24) adcThr[thrIdx] = 0;
  }

  led = analogRead(A3)/40;

  if (led > 24) led = 24;

  if (thrIdx == 0) color = colorFace1[colorIdx];
  else color = colorFace2[colorIdx];

  // draw ADC reading
  strip.clear();
  for (i = 0; i < led ; i++)
  {
    setColor(i, color);
  }

  // put marker for 1st threshold
  led = adcThr[0];
  color = getColor(led);
  color += colorM[colorIdx];
  setColor(led, color);

  // marker for 2nd threshold
  led = adcThr[1];
  color = getColor(led);
  color += colorH[colorIdx];
  setColor(led, color);

  strip.show();
}

void runClock()
{
  static unsigned long lastRefresh = 0;
  static uint8_t displayCounter = 0;
  static uint8_t old_ledM = 0;
  static uint8_t ledH = 0, ledM = 0;

  if ((millis() - lastRefresh) >= 500)
  {
    lastRefresh = millis();

    DS3231_get(&t);
    ledH = (t.hour % 12) * 2;
    ledM = ((uint16_t)t.min*60 + t.sec)/150;  // 3600 / 24 = 250

    strip.clear();
    showClock(ledH, ledM);
    strip.show();
  }
}

void showClock(uint8_t ledH, uint8_t ledM)
{
  // draw clock face  
  setColor(0, colorFace1[colorIdx]);
  setColor(6, colorFace1[colorIdx]);
  setColor(12, colorFace1[colorIdx]);
  setColor(18, colorFace1[colorIdx]);

  setColor(2, colorFace2[colorIdx]);
  setColor(4, colorFace2[colorIdx]);
  setColor(8, colorFace2[colorIdx]);
  setColor(10, colorFace2[colorIdx]);
  setColor(14, colorFace2[colorIdx]);
  setColor(16, colorFace2[colorIdx]);
  setColor(20, colorFace2[colorIdx]);
  setColor(22, colorFace2[colorIdx]);

  setColor(ledH, colorH[colorIdx]);        

  if (ledM == ledH) setColor(ledM, colorH[colorIdx] + colorM[colorIdx]);
  else setColor(ledM, colorM[colorIdx]);
}

void showAnimation()
{
  // draw eyes
  for (i = 0; i < 3; i++)
  {
    strip.clear();
    strip.show();
    delay(50);
    
    setColor(21, colorM[colorIdx]);
    setColor(3, colorM[colorIdx]);
    strip.show();
    delay(1000);
  }

  // draw smile
  for (i = 16; i > 7; i--)
  {
    setColor(i, colorH[colorIdx]);   
    strip.show();
    delay(100);
  }

  delay(1500);

  // wink
  for (i = 0; i < 2; i++)
  {
    setColor(3, 0);
    strip.show();
    delay(300);
    setColor(3, colorM[colorIdx]);
    strip.show();
    delay(1000);
  }
  
}

void setColor(uint8_t pixel, uint32_t color)
{
  strip.setPixelColor((pixel + ledOffset) % 24, color);
}

uint32_t getColor(uint8_t pixel)
{
  strip.getPixelColor((pixel + ledOffset) % 24);
}
