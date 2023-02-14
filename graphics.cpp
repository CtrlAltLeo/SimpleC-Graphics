
#define graphics

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

//testing
//+++  TO DO +++
//add an empty rect


using namespace std;


const int SCREEN_X = 70;
const int SCREEN_Y = 30;



class display_screen{
	

	private:	
		
		const char null = '~';
		char screen[SCREEN_Y][SCREEN_X] = {};
	
	public:
		
		display_screen(){
			for (int y = 0; y < SCREEN_Y; y++){
				for (int x = 0; x < SCREEN_X; x++){
					
					screen[y][x] = ' ';

				}
			}

		}

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
			
			if (x < 0 || y < 0 || x > SCREEN_X || y > SCREEN_Y){
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

		
		
		void line(double x1, double y1,double x2, double y2, char c){
			
			float ang = atan((y2-y1)/(x2-x1));
			
			cout << ang << endl;

			for (int i = x1; i < x2; i++){
				
			 	int x = floor(i*cos(ang));
				int y = floor(i*sin(ang));

				set_char(x,y,c);			
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
		

		void circ(int x, int y, int r, char c){
			
			for (int i = 0; i < 360; i++){
				
				double deg = (i*3.14)/180;
				
				set_char(floor(r*1.5*cos(deg))+x, floor(r*sin(deg))+y, c);
				
			}

		}

		void circ_fill(int x, int y, int r, char c){
			

			for (int i = r; i > 0; --i){
				
				circ(x,y,i,c);

			}

		}
		
};

#endif
