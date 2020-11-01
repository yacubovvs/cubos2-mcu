void driver_serialport_setup(){
  Serial.begin(9600);
}

void driver_serialport_setup(int boundrate){
  Serial.begin(boundrate);
  while (!Serial);
}

void driver_serialport_print(String string){
  Serial.print(string);
}

void driver_serialport_println(String string){
  Serial.println(string);
}

void driver_serialport_test(){
  driver_serialport_println("Serial port test string");
}
