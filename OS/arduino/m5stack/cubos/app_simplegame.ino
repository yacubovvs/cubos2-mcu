#define appNameClass    SimpleGameApp          // App name without spaces
#define appName         "Game"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(byte event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static byte icon[] PROGMEM;
      
};

void appNameClass::onCreate(){

    

    /*
        Write you code onCreate here
    */
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(byte event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const byte appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,
    0x04,0xff,0xd9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x03,0x80,
    0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x03,
    0xFF,0xFF,0xC0,0x03,0xFF,0xFF,0xC0,0x03,0xFF,0xFF,0xC0,0x1F,0x8F,0xF1,0xF8,0x1F,0x8F,0xF1,0xF8,0x1F,0x8F,0xF1,0xF8,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE3,0xFF,0xFF,0xC7,0xE3,0xFF,0xFF,0xC7,0xE3,0xFF,0xFF,
    0xC7,0xE3,0x80,0x01,0xC7,0xE3,0x80,0x01,0xC7,0xE3,0x80,0x01,0xC7,0x00,0x7E,0x7E,0x00,0x00,0x7E,0x7E,0x00,0x00,0x7E,
    0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};