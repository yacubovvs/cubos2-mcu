#define appNameClass    MainMenuApp      // App name without spaces
#define appName         "Main menu"      // App name with spaces 

#define PAGES_LIST_HEIGHT               20
#define ACTIVE_SCREEN_WIDTH             SCREEN_WIDTH
#define ACTIVE_SCREEN_HEIGHT            (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT - PAGES_LIST_HEIGHT)
#define SINGLE_ELEMENT_MIN_WIDTH        100
#define SINGLE_ELEMENT_MIN_HEIGHT       80

#define SINGLE_ELEMENTS_IN_X            ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH))
#define SINGLE_ELEMENTS_IN_Y            ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT))

#define SINGLE_ELEMENT_REAL_WIDTH       ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENTS_IN_X))
#define SINGLE_ELEMENT_REAL_HEIGHT      ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENTS_IN_Y))


// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # //
//                                          APPLICATIONS                                           //

#define APP_MENU_APPLICATIONS_QUANTITY      5

#define APP_MENU_APPLICATIONS_0             AlarmApp
#define APP_MENU_APPLICATIONS_1             BarometerApp
#define APP_MENU_APPLICATIONS_2             ClockApp
#define APP_MENU_APPLICATIONS_3             CompassApp
#define APP_MENU_APPLICATIONS_4             FileManagerApp
#define APP_MENU_APPLICATIONS_5             I2CScannerApp
//#define APP_MENU_APPLICATIONS_6             InternetApp
//#define APP_MENU_APPLICATIONS_7             SettingsApp
//#define APP_MENU_APPLICATIONS_8             SimpleGameApp
//#define APP_MENU_APPLICATIONS_9             TestApplicationApp

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # //

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(byte event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };

        const static byte icon[] PROGMEM;
      
    private:
        static byte current_app_menu;
        const byte* getApplicationTitle(int num);
        const unsigned char* getApplicationIcon(int num);

};

const byte appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x6f,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x1E,0x00,
    0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x78,
    0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x04,0xFF,0xFF,0xFF,0x1F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xFC,0x7F,0xFF,0xFF,0xFE,0xFF,0xFE,0x7F,0xFF,0xFF,0xF9,0x9F,0xFF,
    0xFF,0xE7,0xE7,0xFF,0xFF,0x9F,0xF9,0xFF,0xFF,0x7F,0xFE,0xFF,0xFF,0x1F,0xF8,0xFF,0xFF,0x67,0xE0,0xFF,0xFF,0x79,0x80,0xFF,0xFF,0x7E,0x00,
    0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x9F,0x01,0xFF,0xFF,0xE7,
    0x07,0xFF,0xFF,0xF9,0x1F,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0x7F,0xFF,0xFF,0xDF,0xFF,0xFF,0xFF,
    0xC7,0x6B,0xFF,0xFF,0xDB,0x65,0xFF,0xFF,0xDB,0x6D,0xFF,0xFF,0xC7,0x6D,0xFF,0x7F,0xFF,0xFF,0xFE,0x3F,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0xF8,
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x06,0x60,0x00,0x00,0x18,0x18,
    0x00,0x00,0x60,0x06,0x00,0x00,0x80,0x01,0x00,0x00,0xE0,0x07,0x00,0x00,0x98,0x19,0x00,0x00,0x86,0x61,0x00,0x00,0x81,0x81,0x00,0x00,0x80,
    0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x60,0x86,0x00,0x00,0x18,0x98,0x00,0x00,
    0x06,0xE0,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x80,0x00,0x00,0x20,0x00,0x00,0x00,0x38,0x94,0x00,
    0x00,0x24,0x9A,0x00,0x00,0x24,0x92,0x00,0x00,0x38,0x92,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

void appNameClass::onCreate(){
    core_views_statusBar_draw();
    
    /*  // * /
    #ifdef serialDebug
        // Serial.println("Application on onCreate");

        Serial.print("SINGLE_ELEMENTS_IN_X ");
        Serial.println(SINGLE_ELEMENTS_IN_X);

        Serial.print("SINGLE_ELEMENTS_IN_Y ");
        Serial.println(SINGLE_ELEMENTS_IN_Y);

        Serial.print("SINGLE_ELEMENT_REAL_WIDTH ");
        Serial.println(SINGLE_ELEMENT_REAL_WIDTH);

        Serial.print("SINGLE_ELEMENT_REAL_HEIGHT ");
        Serial.println(SINGLE_ELEMENT_REAL_HEIGHT);
    #endif
    // */

    // Drawing page list
    core_views_draw_pages_list_simple(true, SCREEN_HEIGHT-PAGES_LIST_HEIGHT/2, 6);
    core_views_draw_active_page(true, SCREEN_HEIGHT-PAGES_LIST_HEIGHT/2, 6, 5);

    // Drawing icons
    
    for (byte y_position=0; y_position<SINGLE_ELEMENTS_IN_Y; y_position++){
        for (byte x_position=0; x_position<SINGLE_ELEMENTS_IN_X; x_position++){
            int x0 = x_position*SINGLE_ELEMENT_REAL_WIDTH;
            int y0 = y_position*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
            int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
            int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

            int x_center = (x0+x1)/2;
            int y_center = (y0+y1)/2;

            int app_num = y_position*SINGLE_ELEMENTS_IN_Y + x_position;

            setDrawColor(255, 255, 255);
            drawRect(x0, y0, x1, y1);

            // Center
            //drawPixel(x_center, y_center);
            if(app_num<APP_MENU_APPLICATIONS_QUANTITY)
            core_views_draw_app_icon(true, x_center, y_center, (const byte*)this->getApplicationTitle(app_num), this->getApplicationIcon(app_num));

            // Active frame
        }
    }
}

void appNameClass::onLoop(){
    /*
    #ifdef serialDebug
        Serial.println("Application on loop");
    #endif
    delay(100);
    */
}

void appNameClass::onDestroy(){
    #ifdef serialDebug
        Serial.println("Application on onDestroy");
    #endif
}

void appNameClass::onEvent(byte event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){

    }else if(event==EVENT_BUTTON_RELEASED){

    }else if(event==EVENT_BUTTON_LONG_PRESS){

    }else if(event==EVENT_TIME_CHANGED){

    }

}

const byte* appNameClass::getApplicationTitle(int num){
    return getAppParams(num,(PARAM_TYPE_NAME));
}

const unsigned char*  appNameClass::getApplicationIcon(int num){
    return (const unsigned char *)getAppParams(num,(PARAM_TYPE_ICON));
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    SHARED FUNCTIONS +                                    #
    #                                                                                          #
    ############################################################################################
*/

Application *getApp(byte i){  
    if (i==0) return new APP_MENU_APPLICATIONS_0; 
    else if (i==1) return new APP_MENU_APPLICATIONS_1; 
    else if (i==2) return new APP_MENU_APPLICATIONS_2; 
    else if (i==3) return new APP_MENU_APPLICATIONS_3; 
    else if (i==4) return new APP_MENU_APPLICATIONS_4; 
    else if (i==5) return new APP_MENU_APPLICATIONS_5; 
    //else if (i==6) return new APP_MENU_APPLICATIONS_6; 
    //else if (i==7) return new APP_MENU_APPLICATIONS_7; 
    //else if (i==8) return new APP_MENU_APPLICATIONS_8; 
    //else if (i==9) return new APP_MENU_APPLICATIONS_9; 
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADD YOUR APP HERE
    else return new appNameClass;
}

const byte *getAppParams(byte i, byte type){
    if(i==0){
        APP_MENU_APPLICATIONS_0 *app; return ((*app).getParams(type));
    }else if(i==1){
        APP_MENU_APPLICATIONS_1 *app; return ((*app).getParams(type));
    }else if(i==2){
        APP_MENU_APPLICATIONS_2 *app; return ((*app).getParams(type));
    }else if(i==3){
        APP_MENU_APPLICATIONS_3 *app; return ((*app).getParams(type));
    }else if(i==4){
        APP_MENU_APPLICATIONS_4 *app; return ((*app).getParams(type));
    }else if(i==5){
        APP_MENU_APPLICATIONS_5 *app; return ((*app).getParams(type));
    /*}else if(i==6){
        APP_MENU_APPLICATIONS_6 *app; return ((*app).getParams(type));
    }else if(i==7){
        APP_MENU_APPLICATIONS_7 *app; return ((*app).getParams(type));
    }else if(i==8){
        APP_MENU_APPLICATIONS_8 *app; return ((*app).getParams(type));
    }else if(i==9){
        APP_MENU_APPLICATIONS_9 *app; return ((*app).getParams(type));
    }
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADD YOUR APP HERE
    else{
        appNameClass *app; return ((*app).getParams(type));
        */
    }
    return 0;
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    SHARED FUNCTIONS -                                    #
    #                                                                                          #
    ############################################################################################
*/