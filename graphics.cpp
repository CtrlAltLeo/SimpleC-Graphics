#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

//testing
#include <stdio.h>
#include <unistd.h>

//+++  TO DO +++
//- add a way to prevent text drawn off the screen from bugging out
//improve the line
//add a circle tool?
//add an empty rect


using namespace std;


const int SCREEN_X = 70;
const int SCREEN_Y = 30;



class display_screen{
	

	private:	
		
		const char null = '~';
		char screen[SCREEN_Y][SCREEN_X] = {};
	
	public:

		void draw(){
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
			
			if (c == null){
				return;
			}


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
			
			string line;
			
			int Y = 0;

			while(getline(art, line)){

				for (int i = 0; i < line.length(); i++){
					if (line[i] == ' '){
						line[i] = null;
					}

				}


				//displays the line	
				print(x,y+Y,line);
				Y += 1;
			}


		}
		
		
};

int main(){
	
	
	int x,y;
	x = 0;
	y = 0;

	display_screen display;	

	while (true){

		display.cls();

		display.rect_fill(0,0, SCREEN_X, SCREEN_Y, '-');

		display.ascii_image(1,1,"test");

		display.rect_fill(2,SCREEN_Y/2, SCREEN_X - 2, SCREEN_Y-2, '&');

		display.rect_fill(3,SCREEN_Y/2+1, SCREEN_X - 3, SCREEN_Y-3, '.');


		display.print(4,SCREEN_Y/2+2, "Hey you, you're finally awake. You were trying to cross the border..");

		display.draw();
			
		sleep(1);

		

	}

	return 0;

}

