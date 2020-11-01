void setup() {
	driver_serialport_setup(9600);
	driver_serialport_println("");
	driver_serialport_println("Serial port inited");

	driver_display_st7789_spi_setup();
	driver_serialport_println("Display ST7786 inited");

	i2c_scanner_setup();
	driver_serialport_println("I2C scanner inited");

	driver_bmp180_setup();
	driver_serialport_println("BMP180 inited");

	driver_qmc5883_setup();
	driver_qmc5883_recalibrate();
	driver_serialport_println("QMC5883 inited");

	driver_MTU6050_setup();
	driver_serialport_println("MTU6050 inited");

	i2c_scanner_test();
}

long timer = millis();
void loop() {
	
    driver_serialport_println("");
    driver_serialport_test();
    delay(1000);
    driver_display_st7789_spi_test();
    delay(1000);
    driver_serialport_println("");
    i2c_scanner_test();
    delay(1000);

    driver_serialport_println("BMP180 test...");
    timer = millis();
    while(millis()-timer < 1000){
		driver_bmp180_loop();
		driver_serialport_print("Pressure ");
		driver_serialport_println(String(get_barometer_Pressure()));
		delay(150);
    }
    driver_serialport_println("");
	
	
	
    driver_serialport_println("QMC883 test...");
    timer = millis();
    while(millis()-timer < 1000){
		driver_qmc5883_loop();
		driver_serialport_print("Azimuth ");
		driver_serialport_println(String(driver_qmc5883_get_azimuth()));
		delay(150);
    }
    driver_serialport_println("");
	


	/*
	//driver_serialport_println("MTU6050 test...");
    timer = millis();
    while(millis()-timer < 1000){
		driver_MTU6050_loop();
		driver_serialport_println("Test value: ");
		driver_MTU6050_test();
		delay(150);
    }
    //driver_serialport_println("");
	*/
	
}
