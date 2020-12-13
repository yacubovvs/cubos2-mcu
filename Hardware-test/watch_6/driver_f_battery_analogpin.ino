void driver_battery_test_start(){
	tft.fillScreen(BLACK);
	tft.setCursor(0, 3); 
	tft.println("Battery voltage:");
	tft.println("");
}

void driver_battery_test(){
  tft.setCursor(0, 32);
  tft.setTextColor(WHITE, BLACK); 
  tft.print(driver_battery_getVoltage());
}

int driver_battery_getVoltage(){
	return analogRead(A0);
}