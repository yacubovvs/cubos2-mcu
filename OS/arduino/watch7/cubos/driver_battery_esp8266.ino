void driver_battery_setup(){
    pinMode(A0, INPUT);
}

void driver_battery_loop(){

}

int driver_battery_getVoltage(){
    return analogRead(A0);
}

byte driver_battery_getPercent(){
    return 0;
}