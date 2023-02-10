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
			
			
		
			rect_fill(x1,y1,x2,y2,c);
			rect_fill(x1+w,y1+w,x2-w,y2-w,' ');		


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
		void print_bounds(int x1, int y1, int x2, int y2, string text){

			//create vector of words
			vector<string> words;
			
			

			int word_start = 0;

			while(word_start < text.length()){
				//sleep(1);	
				string sub;
				
				for (int i = word_start; i < text.length()+1; i++){
					if (text[i] == ' ' || i == text.length()){
						
						word_start = i+1;
						break;
					}

					sub = sub + text[i];
				}

				
				words.push_back(sub);
					

			}	


			//combine words into strings less than x
			
			vector<string> complete_lines;
			string holding_string;

			for (auto i : words){	

				int dist = x2 - x1;

				if (holding_string.length() + i.length() > dist){
					complete_lines.push_back(holding_string);
					holding_string = "";
				}	

				holding_string = holding_string + i + " ";

			}

			if (holding_string != ""){
				complete_lines.push_back(holding_string);
			}


			//print lines
			int y = y1;
			for (auto line: complete_lines){
				print(x1,y, line);
				y += 1;
				
			}	


					
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
					} else {
						break;
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

		display_screen display;	

		display.ascii_image(0,0,"test");

		display.rect_fill(0,0,70,30,'#');
		
		display.print_bounds(3,3,10,3,"HEY YOU");	
		
		

		for (int i = 0; i < SCREEN_X; i++){
			
		display.set_char(i,5,'*');

		}


		display.draw();
			
		sleep(1);

		x += 1;
		

	}

	return 0;

}

