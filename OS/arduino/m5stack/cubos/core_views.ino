/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR +                                       #
    #                                                                                          #
    ############################################################################################
*/

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