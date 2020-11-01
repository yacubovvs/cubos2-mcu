#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include "Arduino_ST7789.h" // Hardware-specific library for ST7789 (with or without CS pin)
#include <SPI.h>

#define TFT_DC    2 // D4
#define TFT_RST   0
#define TFT_CS    -1 // 
#define TFT_MOSI  13
#define TFT_SCLK  14

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST); //for display without CS pin

void driver_display_st7789_spi_setup(){
  tft.init(240, 240);
  tft.fillScreen(BLACK);

  pinMode(12, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(3, OUTPUT);
}

void driver_display_st7789_spi_test(){
    tft.fillScreen(BLACK);
    tft.fillScreen(YELLOW);
    tft.fillScreen(RED);
    tft.fillScreen(GREEN);
    tft.fillScreen(BLUE);
    return;

    tft.setCursor(5, 3); 
    
    tft.setTextColor(WHITE); 
    tft.setTextColor(WHITE, BLACK); 
    tft.setTextSize(3); 

    tft.println("");
    if(digitalRead(12))
        tft.println("Btn1: ON ");
    else
        tft.println("Btn1: OFF");
        
    if(digitalRead(3))
        tft.println("Btn2: ON ");
    else
        tft.println("Btn2: OFF");

    if(digitalRead(16))
        tft.println("Btn3: ON ");
    else
        tft.println("Btn3: OFF");

    if(digitalRead(15))
        tft.println("Btn4: ON ");
    else
        tft.println("Btn4: OFF");

}








