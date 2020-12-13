#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 pressure;


double 
        barometer_Temperature,
        barometer_Pressure
        ;

double barometer_Pressure_Current = 760;

void driver_bmp180_setup()
{
  pressure.begin();
}

// TODO: starting of device
void driver_bmp180_wake(){
}

// TODO: stoping of device
void driver_bmp180_sleep(){
    //pressure.stop(); -- not working
    //pressure.end(); -- not working
}

void barometer_reset_current_pressure(){
  barometer_Pressure_Current = get_barometer_mm_Hg();
}

double get_barometer_Pressure(){
  return barometer_Pressure;
}

double get_barometer_mm_Hg(){
  return barometer_Pressure*100/133.322;
}

double get_altitude(){
  return ((double)760 - get_barometer_mm_Hg())*10;
}

double get_altitude_def(){
  return ((double)barometer_Pressure_Current - get_barometer_mm_Hg())*10;
}

void driver_bmp180_test_start(){
	tft.fillScreen(BLACK);
	tft.setCursor(0, 3); 
	tft.println("BMP180 Altitude:");
	tft.println("");
}

boolean driver_bmp180_test(){
  tft.setCursor(0, 32);
  tft.setTextColor(WHITE, BLACK); 
  tft.print(get_altitude());
}

boolean driver_bmp180_loop(){
  

  char status;
  
  status = pressure.startTemperature();

  
  if (status != 0)
  {
    delay(status);

    status = pressure.getTemperature(barometer_Temperature);
    if (status != 0)
    {
      status = pressure.startPressure(3);
      if (status != 0)
      {
        // Wait for the measurement to complete:
        delay(status);

        status = pressure.getPressure(barometer_Pressure,barometer_Temperature);
        if (status != 0){

          //barometer_Altitude
          
          //barometer_Altitude = pressure.sealevel();
          //barometer_Sealevel;

          //drawIntString( ((long)(barometer_Pressure * 10.0)), 20);
          //drawDebugString((int)(barometer_Temperature*1000), 30);


          return true;
          
        }
        return false;
      }
      return false;
    }
    return false;
  }
  return false;
}