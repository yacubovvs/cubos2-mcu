#define appNameClass    MainMenu         // App name without spaces
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
};

const byte appNameClass::icon[] PROGMEM= {};

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
    for (byte x_position=0; x_position<SINGLE_ELEMENTS_IN_X; x_position++){
        for (byte y_position=0; y_position<SINGLE_ELEMENTS_IN_Y; y_position++){
            int x0 = x_position*SINGLE_ELEMENT_REAL_WIDTH;
            int y0 = y_position*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
            int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
            int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

            int x_center = (x0+x1)/2;
            int y_center = (y0+y1)/2;

            setDrawColor(255, 255, 255);
            drawRect(x0, y0, x1, y1);

            // Center
            drawPixel(x_center, y_center);

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
    /*
    #ifdef serialDebug
        Serial.print("Event: ");
        Serial.print(event);
        Serial.print("        Button: ");
        Serial.println(val1);
    #endif
    */
}
