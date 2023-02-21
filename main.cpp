#include "graphics.h"



int main(){
	
	while (true){

	display_screen display;
	
	display.cls();

	display.line(0,0,SCREEN_X, SCREEN_Y, '%');
	
	display.ascii_image(10,10, "test");

	display.draw();
	
	system("sleep .2");
	}

	return 0;

}
