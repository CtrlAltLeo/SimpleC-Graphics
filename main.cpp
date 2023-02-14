#include "graphics.h"



int main(){
	
	display_screen display;

	display.cls();

	display.rect(0,0,20,20,'^');
	
	cout << SCREEN_X << endl;


	display.draw();


	return 0;

}
