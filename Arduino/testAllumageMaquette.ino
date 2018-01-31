#include <FastLED.h>


//commun
#define BRIGHTNESS  64
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB

//bandeau chervron
#define LED_PIN_CHEV     7
#define NUM_LEDS_CHEV    9
CRGB chevrons[NUM_LEDS_CHEV];

//bandeau glyphs
#define LED_PIN_GLYPHS     5
#define NUM_LEDS_GLYPHS    36
CRGB glyphs[NUM_LEDS_GLYPHS];

//bandeau horizon
#define LED_PIN_HORIZON     9
#define NUM_LEDS_HORIZON    30
CRGB horizon[NUM_LEDS_HORIZON];

CRGBPalette16 currentPalette;
TBlendType    currentBlending;
#define UPDATES_PER_SECOND 100

void setup() {
  // put your setup code here, to run once:
 
  delay( 3000 ); // power-up safety delay
  Serial.begin(9600);
     Serial.println("debut init");
  FastLED.addLeds<LED_TYPE, LED_PIN_CHEV, COLOR_ORDER>(chevrons, NUM_LEDS_CHEV).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_GLYPHS, COLOR_ORDER>(glyphs, NUM_LEDS_GLYPHS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_HORIZON, COLOR_ORDER>(horizon, NUM_LEDS_HORIZON).setCorrection( TypicalLEDStrip );
  
  FastLED.setBrightness(  BRIGHTNESS );
      currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
    
  Serial.println("avant raz");
RAZ();
Serial.println("fin init");
}

void RAZ(){
  for(int i =0; i< NUM_LEDS_CHEV;i++){
  chevrons[i] = CRGB::Black;
}
for(int i =0; i< NUM_LEDS_GLYPHS;i++){
  glyphs[i] = CRGB::Black;
}

for(int i =0; i< NUM_LEDS_HORIZON;i++){
  horizon[i] = CRGB::Black;
}

    Serial.println("glyphs show raz");
FastLED.show();

}

void allumage(){
  for(int i =0; i< NUM_LEDS_CHEV;i++){
  chevrons[i] = CRGB::Blue;
}
for(int i =0; i< NUM_LEDS_GLYPHS;i++){
  glyphs[i] = CRGB::Blue;
}
    Serial.println("glyphs + chevron show allumage complet");
FastLED.show();

}

void animationHorizon(int nbRepet){
  for(int t=0 ;t<nbRepet; t++){
      static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors(startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS_HORIZON; i++) {
        horizon[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
  
  }

void loop() {
  // put your main code here, to run repeatedly:
for(int c =0; c< NUM_LEDS_CHEV;c++){
  

  for(int i =0; i< NUM_LEDS_GLYPHS;i++){
    glyphs[i] = CRGB::Blue;
    Serial.println("glyphs show up");
                FastLED.show();
            // clear this led for the next time around the loop
            glyphs[i] = CRGB::Black;
            delay(30);
    }

  for(int i = NUM_LEDS_GLYPHS - 2; i > 0;i--){
    glyphs[i] = CRGB::Blue;
     Serial.println("glyphs show down");
                FastLED.show();
            // clear this led for the next time around the loop
            glyphs[i] = CRGB::Black;
            delay(30);
    }
     glyphs[0] = CRGB::Red;
  chevrons[c] = CRGB::Blue;
   Serial.println("chevron show");
    FastLED.show();
    delay(40);    
  }
allumage();
  animationHorizon(3000);
  delay(10); 
  RAZ();
}
