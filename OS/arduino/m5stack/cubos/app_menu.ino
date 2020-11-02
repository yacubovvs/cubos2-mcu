
#define appNameClass    MainMenu         // App name without spaces
#define appName         "Main menu"      // App name with spaces 

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
    /*
    #ifdef serialDebug
        Serial.println("Application on onCreate");
    #endif
    */
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
