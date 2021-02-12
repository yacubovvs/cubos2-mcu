String core_time_getTimeString(){
    return "10:28";
}

//#define EVENT_ON_TIME_CHANGED              0x03
long lastTimeChange = millis()/ON_TIME_CHANGE_EVERY_MS;
void core_time_loop(){
    long currentTime = millis()/ON_TIME_CHANGE_EVERY_MS;
    if(currentTime!=lastTimeChange){
        currentApp->onEvent(EVENT_ON_TIME_CHANGED, currentTime, 0);
        lastTimeChange = currentTime;
    }
}