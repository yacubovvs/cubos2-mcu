void i2c_scanner_setup();
void i2c_scanner_test();

void setup() { 
	//driver_serialport_setup(9600);
	//driver_serialport_println("");
	//driver_serialport_println("Serial port inited");

  // https://github.com/jarzebski/Arduino-DS3231
  // RTC library

	driver_gpio_btn_setup();
	driver_display_st7789_spi_setup();
	//driver_serialport_println("Display ST7786 inited");

	i2c_scanner_setup();
	//driver_serialport_println("I2C scanner inited");

	driver_bmp180_setup();
	//driver_serialport_println("BMP180 inited");

	driver_qmc5883_setup();
	driver_qmc5883_recalibrate();
	//driver_serialport_println("QMC5883 inited");

	driver_MTU6050_setup();
	//driver_serialport_println("MTU6050 inited");

	//i2c_scanner_test();
	driver_DS3231SN_setup();

	pinMode(16, OUTPUT);
}

long timer = millis();
void loop() {
	
	/////////////////////////////////
	/*
	driver_gpio_btn_test_start();
	driver_DS3231SN_start_1sec_wakeupTimer();

	while(true){	
		driver_gpio_btn_test();
	}
	*/

	while(1){
		pinMode(16, OUTPUT);
        digitalWrite(16, 1);
        delay(150);
        digitalWrite(16, 0);
		/*
		
		//driver_DS3231SN_start_1sec_wakeupTimer();
		driver_display_st7789_powerOn();
		driver_gpio_btn_test_start();
		timer = millis();
		//while(1){
		while(millis()-timer < 5000){
			driver_gpio_btn_test();
		}*/

		driver_DS3231SN_start_1min_wakeupTimer();
		driver_DS3231SN_stop_wakeupTimer();
		driver_display_st7789_powerOff();
		//delay(5000);
		driver_cpu_sleep_3();
		//delay(100);
		driver_DS3231SN_start_1sec_wakeupTimer();
		driver_display_st7789_spi_setup();
		driver_DS3231SN_printsomething();
		//delay(500);
		/*
		timer = millis();
		while(digitalRead(16)){
			driver_gpio_btn_test();
		}*/
	}
	

	/*
	timer = millis();
	driver_gpio_btn_test_start();
    while(millis()-timer < 5000){
	//while(true){
		driver_gpio_btn_test();
	}
	*/

	/*
	i2c_scanner_test();
	delay(3000);

	timer = millis();
	driver_bmp180_test_start();
    while(millis()-timer < 5000){
		driver_bmp180_loop();
		driver_bmp180_test();
	}


	timer = millis();
	driver_qmc5883_test_start();
    while(millis()-timer < 7000){
		driver_qmc5883_loop();
		driver_qmc5883_test();
	}
	


	timer = millis();
	driver_battery_test_start();
    while(millis()-timer < 5000){
		while(millis()-timer < 5000){
		driver_battery_test();
	}
	*/

}
