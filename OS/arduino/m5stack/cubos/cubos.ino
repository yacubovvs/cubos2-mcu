/*
    ############################################################################################
    #                                                                                          #
    #                                    M5STACK SETTINGS +                                    #
    #                                                                                          #
    ############################################################################################
*/

#define serialDebug


#define SCREEN_WIDTH            320     // Note: x-coordinates go wide
#define SCREEN_HEIGHT           240     // Note: y-coordinates go high

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

#define device_has_battery

#define platform_esp32
#define device_has_bluetooth
#define device_has_wifi

#define hasHardwareButtons              // Conf of controls with hardware btns    
//#define isTouchScreen                 // Conf of controls

#define colorScreen                     // Screen is colored
#define noAnimation                     // Caurse of framebuffer type

/*
    ############################################################################################
    #                                                                                          #
    #                                    M5STACK SETTINGS -                                    #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                   APPLIACATION OJECT +                                   #
    #                                                                                          #
    ############################################################################################
*/

#define ICON_ARROW_RIGHT  0x01
#define ICON_ARROW_LEFT   0x02
#define ICON_ARROW_UP     0x03
#define ICON_ARROW_DOWN   0x04
#define BATTERY_UNKNOWN   0x05

#define BATTERY_100     0x06
#define BATTERY_90      0x07
#define BATTERY_80      0x08
#define BATTERY_70      0x09
#define BATTERY_60      0x0A
#define BATTERY_50      0x0B
#define BATTERY_40      0x0C
#define BATTERY_30      0x0D
#define BATTERY_20      0x0E
#define BATTERY_10      0x0F
#define BATTERY_0     0x10

#define WIFI_CONNECTED    0x11
#define WIFI_NOTCONNECTED 0x12
#define WI_FI_IMG_OFF   0x13
#define BT_CONNECTED    0x14
#define BT_NOTCONNECTED   0x15
#define BT_OFF        0x16

#define PARAM_TYPE_ICON   0x01
#define PARAM_TYPE_NAME   0x02


/////////////////////////////////////
// APPLICATION CLASS
#ifndef do_Not_use_native_apps
  class Application{
    public:
    #ifdef tabletView
    boolean showStatusBar = false;
    #endif
    
      int scroll_x          = 0;
      int scroll_y          = 0;
      int scroll_to_x     = 0;
      int scroll_to_y     = 0;
      virtual void loop() = 0;
      void loop_app(){
        loop();

        #ifdef noAnimation
          scroll_x = scroll_to_x;
          scroll_y = scroll_to_y;
        #else
          int dy=0; int dx =0;
    
          if(scroll_x!=scroll_to_x){
            dx = abs(scroll_x-scroll_to_x)/5 + 2;
            if(scroll_x>scroll_to_x) dx *= -1;
            scroll_x+=dx;
    
            if (abs(scroll_x-scroll_to_x)<abs(dx)) scroll_to_x=scroll_x;
          }
    
          if(scroll_y!=scroll_to_y){
            dy = abs(scroll_y-scroll_to_y)/5 + 2;
            if(scroll_y>scroll_to_y) dy *= -1;
            scroll_y+=dy;
        
            if (abs(scroll_y-scroll_to_y)<abs(dy)) scroll_y=scroll_to_y;
          }

          //Serial.println(scroll_to_y);
        #endif
      }
      Application(){};
  };

  Application* currentApp;

#else
  int scroll_x        = 0;
  int scroll_y        = 0;
  int scroll_to_x     = 0;
  int scroll_to_y     = 0;

  void appsetup(){
    no_native_apps_SETUP();
  }

  void apploop(){   
    no_native_apps_LOOP();
  }
#endif
//
/////////////////////////////////////

#ifdef useNativeMenu
  Application *getApp(byte i);
  ////////////////////////////////////

  void os_switch_to_app(byte app_numm){
    delete currentApp;
    #ifdef colorScreen
      // for correct drawing background
      driver_clearScreen();
    #endif
    currentApp = getApp(app_numm);
  }
#endif

/*
    ############################################################################################
    #                                                                                          #
    #                                   APPLIACATION OJECT -                                   #
    #                                                                                          #
    ############################################################################################
*/

void setup()
{ 
  #ifdef serialDebug
    Serial.begin(9600);
  #endif

  setup_displayDriver();
  setDrawColor(255, 0, 0);
  drawPixel(10,10);

}

void loop(){
  //clearscreen_displayDriver();
  //os_control_loop(); // Check buttons
}