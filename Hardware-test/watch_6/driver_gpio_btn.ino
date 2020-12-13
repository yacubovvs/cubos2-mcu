#define btn1

void driver_gpio_btn_setup(){
    
    pinMode(16, INPUT);
    pinMode(15, INPUT);
    pinMode(1, INPUT);
    pinMode(3, INPUT);
    
    pinMode(12, OUTPUT);

    /*
    pinMode(12, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(3, OUTPUT);
    */
}


void driver_gpio_btn_test_start(){
  	tft.fillScreen(BLACK);
	tft.setCursor(0, 3); 
	tft.println("Buttons test:");
	tft.println("");

    tft.setTextColor(WHITE, BLACK); 

    tft.setCursor(0, 40); 
	tft.print("Button 1:");
    tft.setCursor(0, 80); 
	tft.print("Button 2:");
    tft.setCursor(0, 120); 
	tft.print("Button 3:");
    tft.setCursor(0, 160); 
	tft.print("Button 3:");
}

void driver_gpio_btn_test(){
    if(digitalRead(16)){
        tft.setCursor(120, 40); 
        tft.println("ON ");
    }else{
        tft.setCursor(120, 40); 
        tft.println("OFF");
    }
        
        
    if(digitalRead(3)){
        tft.setCursor(120, 80); 
        tft.println("ON ");

    }else{
        tft.setCursor(120, 80); 
        tft.println("OFF");

        pinMode(12, OUTPUT);
        digitalWrite(12, 1);
        delay(200);
        digitalWrite(12, 0);
    }

    if(digitalRead(15)){
        tft.setCursor(120, 120); 
        tft.println("ON ");
    }else{
        tft.setCursor(120, 120); 
        tft.println("OFF");
    }
        

    if(digitalRead(1)){
        tft.setCursor(120, 160); 
        tft.println("ON ");
    }else{
        tft.setCursor(120, 160); 
        tft.println("OFF");
    }

}