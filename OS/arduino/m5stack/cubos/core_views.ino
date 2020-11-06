/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR +                                       #
    #                                                                                          #
    ############################################################################################
*/

// background
#define STYLE_STATUSBAR_BACKGROUND_RED      116
#define STYLE_STATUSBAR_BACKGROUND_GREEN    0
#define STYLE_STATUSBAR_BACKGROUND_BLUE     176

// text color
#define STYLE_STATUSBAR_TEXT_RED      255
#define STYLE_STATUSBAR_TEXT_GREEN    255
#define STYLE_STATUSBAR_TEXT_BLUE     255

void core_views_statusBar_draw(){
    /*
            [ TIME | ----- | NOTIFICATIONS | BATTERY ]
    */

    // BACKGROUND
    setDrawColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
    drawRect(0, 0, SCREEN_WIDTH, STYLE_STATUSBAR_HEIGHT, true);

    // TIME
    setDrawColor(STYLE_STATUSBAR_TEXT_RED, STYLE_STATUSBAR_TEXT_GREEN, STYLE_STATUSBAR_TEXT_BLUE);
    drawString(core_time_getTimeString(), 5, STYLE_STATUSBAR_HEIGHT/2 - FONT_CHAR_HEIGHT/2 + ( (STYLE_STATUSBAR_HEIGHT)%2 ), 2);
}

/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR -                                       #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                       PAGES LIST +                                       #
    #                                                                                          #
    ############################################################################################
*/

#define CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE                  4
#define CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE         20

void core_views_draw_pages_list_simple(
    boolean draw, // true - draw, false - clear
    int y0,
    byte pages_quantity
){
    //SCREEN_WIDTH
    //SCREEN_HEIGHT

    setDrawColor(128, 128, 128);

    for(int i=0; i<pages_quantity; i++){
        int element_x = SCREEN_WIDTH/2 + core_views_pages_list_get_element_position_x(pages_quantity, i);
        int element_y = y0;
        drawRect(element_x - CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_y - CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_x + CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_y + CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE);
    }
}

void core_views_draw_active_page(
    boolean draw, // true - draw, false - clear
    int y0,
    byte pages_quantity,
    byte position
){

    setDrawColor(0, 255, 0);

    int element_x = SCREEN_WIDTH/2 + core_views_pages_list_get_element_position_x(pages_quantity, position);
    int element_y = y0;
    drawRect(element_x - (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_y - (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_x + (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_y + (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), true);

}

int core_views_pages_list_draw_element_position_x(boolean draw, int x, int y){
    
}

int core_views_pages_list_get_element_position_x(int pages_quantity, int position){
    return ( (pages_quantity%2==1) ? 0 : (-CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE/2) ) - (-pages_quantity/2 + position) * CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE;
}

/*
    ############################################################################################
    #                                                                                          #
    #                                       PAGES LIST -                                       #
    #                                                                                          #
    ############################################################################################
*/