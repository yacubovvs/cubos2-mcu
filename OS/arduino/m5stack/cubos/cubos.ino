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



/////////////////////////////////////
// APPLICATION CLASS

class Application{
  public:
    boolean showStatusBar = false;

  
    int scroll_x          = 0;
    int scroll_y          = 0;
    int scroll_to_x     = 0;
    int scroll_to_y     = 0;
    virtual void onLoop() = 0;
    virtual void onDestroy() = 0;
    virtual void onEvent(byte event, int val1, int val2) = 0;

    void loop_app(){
      onLoop();
      

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
    Serial.begin(115200);
  #endif
  setup_displayDriver();
  currentApp = getApp(0);

}

void loop(){
  //clearscreen_displayDriver();
  //os_control_loop(); // Check buttons
  
  driver_controls_loop();
  currentApp->onLoop();
  
}

void onButtonEvent(byte event, int button){
  currentApp->onEvent(event, button, 0);
}

/*
    ############################################################################################
    #                                                                                          #
    #                                          STYLE +                                         #
    #                                                                                          #
    ############################################################################################
*/

// STATUS BAR 

#define STYLE_STATUSBAR_HEIGHT  40

// background
#define STYLE_STATUSBAR_BACKGROUND_RED      116
#define STYLE_STATUSBAR_BACKGROUND_GREEN    0
#define STYLE_STATUSBAR_BACKGROUND_BLUE     176

// text color
#define STYLE_STATUSBAR_TEXT_RED      255
#define STYLE_STATUSBAR_TEXT_GREEN    255
#define STYLE_STATUSBAR_TEXT_BLUE     255

/*
    ############################################################################################
    #                                                                                          #
    #                                          STYLE -                                         #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                          ICONS +                                         #
    #                                                                                          #
    ############################################################################################
*/

#define ICON_ARROW_RIGHT            0x01
#define ICON_ARROW_LEFT             0x02
#define ICON_ARROW_UP               0x03
#define ICON_ARROW_DOWN             0x04
#define ICON_BATTERY_UNKNOWN        0x05

#define ICON_BATTERY_100            0x06
#define ICON_BATTERY_90             0x07
#define ICON_BATTERY_80             0x08
#define ICON_BATTERY_70             0x09
#define ICON_BATTERY_60             0x0A
#define ICON_BATTERY_50             0x0B
#define ICON_BATTERY_40             0x0C
#define ICON_BATTERY_30             0x0D
#define ICON_BATTERY_20             0x0E
#define ICON_BATTERY_10             0x0F
#define ICON_BATTERY_0              0x10

#define ICON_WIFI_CONNECTED         0x11
#define ICON_WIFI_NOTCONNECTED      0x12
#define ICON_WI_FI_IMG_OFF          0x13
#define ICON_BT_CONNECTED           0x14
#define ICON_BT_NOTCONNECTED        0x15
#define ICON_BT_OFF                 0x16

#define PARAM_TYPE_ICON             0x01
#define PARAM_TYPE_NAME             0x02

/*
    ############################################################################################
    #                                                                                          #
    #                                          ICONS -                                         #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                         EVENTS +                                         #
    #                                                                                          #
    ############################################################################################
*/

#define EVENT_BUTTON_PRESSED            0x00
#define EVENT_BUTTON_RELEASED           0x01
#define EVENT_BUTTON_LONG_PRESS         0x02
#define EVENT_TIME_CHANGED              0x03

/*
    ############################################################################################
    #                                                                                          #
    #                                         EVENTS -                                         #
    #                                                                                          #
    ############################################################################################
*/


/*
    ############################################################################################
    #                                                                                          #
    #                                         CONTROLS +                                       #
    #                                                                                          #
    ############################################################################################
*/

#define CONTROLS_LONG_PRESS_TIMEOUT     700
#define CONTROLS_BUTTONS_COUNT          3
#define MILLIS                          millis

/*
    ############################################################################################
    #                                                                                          #
    #                                         CONTROLS -                                       #
    #                                                                                          #
    ############################################################################################
*/