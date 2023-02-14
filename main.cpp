#include "graphics.h"



int main(){
	
	display_screen display;
	
	display.cls();

	display.line(0,0,SCREEN_X, SCREEN_Y, '%');
	
	display.ascii_image(10,10, "test");

	display.draw();

	return 0;

}
