Application *getApp(byte i){
    if (i==0) return new MainMenu; 
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADD YOUR APP HERE
    else return new MainMenu;
}

const unsigned char * getAppParams(byte i, byte type){
    if(i==0){
        MainMenu *app; return ((*app).getParams(type));
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADD YOUR APP HERE
    }else{
        MainMenu *app; return ((*app).getParams(type));
    }
}