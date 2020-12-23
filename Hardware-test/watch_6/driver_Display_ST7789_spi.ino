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
  tft.setTextSize(2); 

}

void driver_display_st7789_sleep(){
  tft.sleep();
  digitalWrite(0,0);
}

void driver_display_st7789_wakeup(){
  tft.wakeup();
  driver_display_st7789_spi_setup();
}

void driver_display_st7789_powerOff(){
  tft.sleep();
  digitalWrite(0,0);
  //delay(1000);
}

void driver_display_st7789_powerOn(){
  digitalWrite(0,1);
  driver_display_st7789_spi_setup();
}


void driver_display_st7789_spi_test_start(){

}

void driver_display_st7789_spi_test(){

}
