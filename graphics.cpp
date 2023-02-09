#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

//testing
#include <stdio.h>
#include <unistd.h>

using namespace std;

const int SCREEN_X = 70;
const int SCREEN_Y = 30;

char screen[SCREEN_Y][SCREEN_X] = {};


void _draw(){
	int x,y;
	for (y = 0; y < SCREEN_Y; y++){

		string h_line = "";

		for (x = 0; x < SCREEN_X; x++){
			
				h_line = h_line + screen[y][x];		

		}

		cout << h_line << endl;
	}
}

void set_char(int x, int y, char c){
	
	screen[y][x] = c;

}

void cls(){
	cout << "\033[2J\033[1;1H";
	
	//Maybe it clears the draw array too?


}

void rect_fill(int x1, int y1, int x2, int y2, char fill){
	
	int x,y;
	for (y = y1; y < y2; y++){
		for (x = x1; x < x2; x++){
			
			set_char(x,y,fill);

		}
	}

}


//this doesn't work :]
void rect(int x1, int y1, int x2, int y2, char c, int w = 2){

	int x,y;

	for (y = y1; y < y2; y++){
		for (x = x1; x < x2; x++){
			



		}
	}

}

//Neither does this. Angle is wrong for some reason.
void line(int x1, int y1, int x2, int y2, char c){

	float m = atan((y2-y1)/(x2-x1));
		
	int x,y;
	for (x = x1; x < x2; x++){
		
		set_char( floor(x*cos(m)),floor( y * sin(m)), c);

	}	



}


void print(int x, int y, string text){

		
	int i;
	for (i = 0; i < text.length(); i++){
	
		set_char(x+i,y,text[i]);

	}


}


//prints in a box, i.e. dialouge or inventory
void bounds_print(){

}

void ascii_image(int x, int y, string path){

	ifstream art;
	art.open(path);

}


int main(){
	
	
	int x,y;
	x = 20;
	y = 10;

	int ly = 10;

	while (true){

		cls();
	
		rect_fill(0,0,SCREEN_X,SCREEN_Y,'`');
		
		rect_fill(2,SCREEN_Y/2, SCREEN_X-2,SCREEN_Y-2,'%');

		rect_fill(3,SCREEN_Y/2+1, SCREEN_X-3,SCREEN_Y-3,'.');

		print(5, SCREEN_Y/2+3,"HEY! YOU'RE FINALLY AWAKE!");

		_draw();	
			
		sleep(1);

		

	}

	return 0;

}

