#include <Wire.h>
 
void i2c_scanner_setup(){
    Wire.begin();    
} 
 
void i2c_scanner_test(){
    byte error, address;
    int nDevices;
 
    tft.fillScreen(BLACK);
    tft.setCursor(0, 3); 
    tft.println("I2C scanner:");
    tft.println("");

    //Serial.println("Scanning...");
 
    nDevices = 0;
    for(address = 8; address < 127; address++ ){
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
 
        if (error == 0){
            tft.print("Device at 0x");
            if (address<16)
                tft.print("0");
            tft.print(address,HEX);
            tft.println("");
 
            nDevices++;
        }else if (error==4) {
            tft.print("Unknow error at address 0x");
            if (address<16)
                tft.print("0");
            tft.println(address,HEX);
        } 
    }
    if (nDevices == 0)
        tft.println("No I2C devices found\n");
    else
        tft.println("done\n");
}
