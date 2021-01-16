#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

#define PIN            6   //Arduinoで使うピン
#define NUMPIXELS      50   //LEDの数。
int value;
int i = 0;
unsigned start_time = 0;
unsigned time_now = 0;
unsigned ctime = 0;
long interval = 200;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//ミリ秒
void setup() {
    start_time = millis();//始まってから
  Serial.begin(9600);
  
  Serial.println( "Hello Arduino!" ); 
    pixels.begin();
    pixels.show();
}
 
void loop() {
  time_now = millis();//今
  int i = 0;
  if (time_now - start_time > interval){
       start_time= time_now;//経過時間
    if (Serial.available()){
       value = Serial.read();
       pixels.setPixelColor(value, pixels.Color(255, 0, 0)); 
       pixels.show();
       byte var;
 //var = var - 0x30;
        Serial.println((char)value);
      
    } else{
   pixels.setPixelColor(value, pixels.Color(0, 0, 0));   
      pixels.show();
  i++;
    }
}
}
