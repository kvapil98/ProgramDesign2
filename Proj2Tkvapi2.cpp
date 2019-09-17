#include <iostream>
#include <cstdlib> //Include cstd library to access random function
#include <time.h> //Incldude time to set the random seed to the time
using namespace std;

/* ------------------------------------------------
   prog2memory.cpp
 
   Program #2: Memory game of guessing which X or O changed.
   Class: CS 141
   Author: Tomas Kvapil
   Lab: Tues 10am
   System:  DEV C++

   Grading Rubric:

   50 Execution points
         5 Displays header info on screen when run
         5 Displays instructions
         5 Output is formatted as shown in sample output
         3 Handles both upper and lower case input
         2 Input of 'x' in first prompt exits program
         5 Input can be adjacent or have spaces between them
        15 Displayed boards all have odd parity in rows and columns
         5 Repeated input of 'r' gives new valid random board each time
         5 Gives appropriate end of program messages

   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
        10 Meaningful identifier names
        10 Comments: Has header.  Comments on each block of code
        10 Appropriate data and control structures (-20 if using arrays or strings)
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/

//declared 36 characters for each space in the 6X6 table
char p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14,
     p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28,
	 p29, p30, p31, p32, p33, p34, p35;	

//Function that chooses at random a 'X' or 'O' tp be assigned to each character variable
void randChar(){
	srand(time(0)); //Set the seed to the time so it is random each time
	
	//Declared variable to count the number of 'X'. used 1 because if I used 0 then 0%2 would equal 0
	int oneCount = 1; //counter for first row 
	int twoCount = 1; //counter for second row
	int threeCount = 1; //counter for third row
	int fourCount = 1; //counter for fourth row
	int fiveCount = 1; //counter for fifth row
	int sixCount = 1; //counter for 6th row
	
	//While loops checks and randomizes each charcter in the first row. Makes sure to have odd parity of 'X'
	while(oneCount%2 != 0){ //Keeps looping until total number of 'X' is odd
		if((rand()% 100 + 1)%2==0){ //randomizes and assigns 'O' if even //p0 is assigned
			p0 = 'O'; 
		}else{ //assigns 'X' if odd
			p0 = 'X';
			oneCount++; //adds one to 'X' counter if variable is assigned an 'X'
		}
		if((rand()% 100 + 1)%2==0){ //p1 is assigned a 'X' or 'O'
			p1 = 'O';			
		}else{
			p1 = 'X';
			oneCount++;
		}
		if((rand()% 100 + 1)%2==0){ //p2 is assigned a 'X' or 'O'
			p2 = 'O';
		}else{
			p2 = 'X';
			oneCount++;
		}
		if((rand()% 100 + 1)%2==0){ //p3 is assigned a 'X' or 'O'
			p3 = 'O';
		}else{
			p3 = 'X';
			oneCount++;
		}
		if((rand()% 100 + 1)%2==0){ //p4 is assigned a 'X' or 'O'
			p4 = 'O';
		}else{
			p4 = 'X';
			oneCount++;
		}
		if((rand()% 100 + 1)%2==0){ //p5 is assigned a 'X' or 'O'
			p5 = 'O';
		}else{
			p5 = 'X';
			oneCount++;
		}
		if(oneCount%2 != 0){ //At the end of one iteration, if onecount is even then while loop keeps iterating
			oneCount = 1;
		}
	}
	//While loops in this function reapeat for each row so they are all the same but with different variables
	
	//While loops checks and randomizes each charcter in the second row. Makes sure to have odd parity of 'X'
	while(twoCount%2 != 0){
		if((rand()% 100 + 1)%2==0){
			p6 = 'O';
		}else{
			p6 = 'X';
			twoCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p7 = 'O';
		}else{
			p7 = 'X';
			twoCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p8 = 'O';
		}else{
			p8 = 'X';
			twoCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p9 = 'O';
		}else{
			p9 = 'X';
			twoCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p10 = 'O';
		}else{
			p10 = 'X';
			twoCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p11 = 'O';
		}else{
			p11 = 'X';
			twoCount++;
		}
		if(twoCount%2 != 0){
			twoCount = 1;
		}
	}
		
	//While loops checks and randomizes each charcter in the third row. Makes sure to have odd parity of 'X'
	while(threeCount%2 != 0){
		if((rand()% 100 + 1)%2==0){
			p12 = 'O';
		}else{
			p12 = 'X';
			threeCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p13 = 'O';
		}else{
			p13 = 'X';
			threeCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p14 = 'O';
		}else{
			p14 = 'X';
			threeCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p15 = 'O';
		}else{
			p15 = 'X';
			threeCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p16 = 'O';
		}else{
			p16 = 'X';
			threeCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p17 = 'O';
		}else{
			p17 = 'X';
			threeCount++;
		}
		if(threeCount%2 != 0){
			threeCount = 1;
		}
	}
	
	//While loops checks and randomizes each charcter in the fourth row. Makes sure to have odd parity of 'X'
	while(fourCount%2 != 0){
		if((rand()% 100 + 1)%2==0){
			p18 = 'O';
		}else{
			p18 = 'X';
			fourCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p19 = 'O';
		}else{
			p19 = 'X';
			fourCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p20 = 'O';
		}else{
			p20 = 'X';
			fourCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p21 = 'O';
		}else{
			p21 = 'X';
			fourCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p22 = 'O';
		}else{
			p22 = 'X';
			fourCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p23 = 'O';
		}else{
			p23 = 'X';
			fourCount++;
		}
		if(oneCount%2 != 0){
			fourCount = 1;
		}
	}
	
	//While loops checks and randomizes each charcter in the fifth row. Makes sure to have odd parity of 'X'
	while(fiveCount%2 != 0){
		if((rand()% 100 + 1)%2==0){
			p24 = 'O';
		}else{
			p24 = 'X';
			fiveCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p25 = 'O';
		}else{
			p25 = 'X';
			fiveCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p26 = 'O';
		}else{
			p26 = 'X';
			fiveCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p27 = 'O';
		}else{
			p27 = 'X';
			fiveCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p28 = 'O';
		}else{
			p28 = 'X';
			fiveCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p29 = 'O';
		}else{
			p29 = 'X';
			fiveCount++;
		}
		if(fiveCount%2 != 0){
			fiveCount = 1;
		}
	}
	
	//While loops checks and randomizes each charcter in the sixth row. Makes sure to have odd parity of 'X'
	while(sixCount%2 != 0){
		if((rand()% 100 + 1)%2==0){
			p30 = 'O';
		}else{
			p30 = 'X';
			sixCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p31 = 'O';
		}else{
			p31 = 'X';
			sixCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p32 = 'O';
		}else{
			p32 = 'X';
			sixCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p33 = 'O';
		}else{
			p33 = 'X';
			sixCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p34 = 'O';
		}else{
			p34 = 'X';
			sixCount++;
		}	
		if((rand()% 100 + 1)%2==0){
			p35 = 'O';
		}else{
			p35 = 'X';
			sixCount++;
		}
		if(sixCount%2 != 0){
			sixCount = 1;
		}
	}
}

//Function that when called, prints 25 empty lines
void emptySpace(){
	int i;
	for(i=0; i<25; i++){
		cout << endl; //prints empty lines
	}
}

//Prints board when user puts 'r' so they are prompted to enter an input again
void printBoard(){
	
	//board is printed neatly with spacing and variables all aligned 
	cout << endl;
	cout << "     1 2 3 4 5 6    " << endl;
	cout << "   - - - - - - - -  " << endl;
	cout << " A | "<<p0 <<" "<<p1 <<" "<<p2 <<" "<<p3 <<" "<<p4 <<" "<<p5 <<" | A"<< endl;
	cout << " B | "<<p6 <<" "<<p7 <<" "<<p8 <<" "<<p9 <<" "<<p10<<" "<<p11<<" | B" << endl;
	cout << " C | "<<p12<<" "<<p13<<" "<<p14<<" "<<p15<<" "<<p16<<" "<<p17<<" | C" << endl;
	cout << " D | "<<p18<<" "<<p19<<" "<<p20<<" "<<p21<<" "<<p22<<" "<<p23<<" | D" << endl;
	cout << " E | "<<p24<<" "<<p25<<" "<<p26<<" "<<p27<<" "<<p28<<" "<<p29<<" | E" << endl;
	cout << " F | "<<p30<<" "<<p31<<" "<<p32<<" "<<p33<<" "<<p34<<" "<<p35<<" | F" << endl;
	cout << "   - - - - - - - -  " << endl << endl;
	
	cout << "Enter r to randomize to board, or row and column to change a value -> "; //user is prompter to enter input
}

//prints board when user inputs a coordinate so they are prompted to inser what coordinate they think was changed
void printBoard2(){
	
	//board is printed neatly with spacing and variables all aligned
	cout << endl;
	cout << "     1 2 3 4 5 6    " << endl;
	cout << "   - - - - - - - -  " << endl;
	cout << " A | "<<p0 <<" "<<p1 <<" "<<p2 <<" "<<p3 <<" "<<p4 <<" "<<p5 <<" | A"<< endl;
	cout << " B | "<<p6 <<" "<<p7 <<" "<<p8 <<" "<<p9 <<" "<<p10<<" "<<p11<<" | B" << endl;
	cout << " C | "<<p12<<" "<<p13<<" "<<p14<<" "<<p15<<" "<<p16<<" "<<p17<<" | C" << endl;
	cout << " D | "<<p18<<" "<<p19<<" "<<p20<<" "<<p21<<" "<<p22<<" "<<p23<<" | D" << endl;
	cout << " E | "<<p24<<" "<<p25<<" "<<p26<<" "<<p27<<" "<<p28<<" "<<p29<<" | E" << endl;
	cout << " F | "<<p30<<" "<<p31<<" "<<p32<<" "<<p33<<" "<<p34<<" "<<p35<<" | F" << endl;
	cout << "   - - - - - - - -  " << endl << endl;
	
	cout << "What piece do you think it was? -> "; //user is prompted to enter input
}
	
	

//main function that assembles all the above functions
int main(){
	
	//Header for the project
	cout << "Author: Tomas Kvapil" << endl;
	cout << "Class: CS 141, Spring 2018" << endl;
	cout << "Lab: Tues 10am" << endl;
	cout << "Program: #2, Memory Game" << endl;
	cout << "System: DEV C++" << endl;
	cout << endl;
	
	//varibale declaration
	char userin; //user input for first charcter
	int userin2; //user input if they decide to enter a coordinate with integer
	char userin3; //user input for the guess (charcter)
	int userin4; //user input for the guess (integer)
	
	//instructions for the game
	cout << "Welcome to the memory game!" << endl;
	cout << endl;
	cout << "Look away from the board and have a helper enter r" << endl;
	cout << "to randomize the board until they have a random board" << endl;
	cout << "that they like. Then you glance at it and try to" << endl;
	cout << "imprint it in your mind and look away. Your helper" << endl;
	cout << "will then select a single piece to be flipped by" << endl;
	cout << "choosing its row and column. The changed board is then" << endl;
	cout << "dispayed. You then must try to guess which one it was." << endl;
	cout << "Enter x to exit the program" << endl << endl;
	
	//sample board layout at the beginning of program
	cout << "     1 2 3 4 5 6    " << endl;
	cout << "   - - - - - - - -  " << endl;
	cout << " A | X X O O X O | A" << endl;
	cout << " B | X O O O X X | B" << endl;
	cout << " C | X X O O O X | C" << endl;
	cout << " D | O X X X X X | D" << endl;
	cout << " E | X O X X O O | E" << endl;
	cout << " F | X O X X O O | F" << endl;
	cout << "   - - - - - - - -  " << endl;
	
	cout << endl;
	cout << "Enter r to randomize to board, or row and column to change a value -> "; //user prompted to input
	cin >> userin;	
	userin = toupper(userin); //uppercases user input so it doesnt matter if user input upper or lower case character
	
	if(userin == 'X'){ //if user inputs 'x' the program is terminated
		cout << endl << "Exiting the program.";
		return 0; //automatically ends program
	}
	
	//while loop that keeps randomizing the board when the user enters r
	while(userin == 'R'){
		randChar(); //calls randchar() to randomize all the variable
		printBoard(); //prints the playing board
		cin >> userin; //asks user for another input
		userin = toupper(userin); //uppercases the input
		
		if(userin == 'X'){ //if user inputs 'x' the program is terminated
			cout << endl << "Exiting the program.";
			return 0; //automatically ends program
		}
	}
	
	//This giant block of if else statements accounts for every possiblility that the user can enter and changes that specific variable the user inputs
	if((userin != 'R')||(userin != 'X')){ //goes into block if userinput is other than an 'x' or 'r'
		cin >> userin2; //next integer input
		
		if ((userin == 'A')&&(userin2 == 1)){ //changes value of variable for p0 if user inputs A1
			if(p0 == 'X'){ //changes 'x' to 'o'
				p0 = 'O';
			}else{
				p0 = 'X'; //changes 'o' to 'x'
			}
			emptySpace(); //calls emptyspace() to print 25 empty lines
			printBoard2(); //prints 2nd board so the user can input their guess
			cin >> userin3; //charcer for guess
			userin3 = toupper(userin3); //uppercases the input
			cin >> userin4; //integer for guess
			
			if((userin3 == 'A')&&(userin4 == 1)){ //If the guess is correct then awarding line of text is printed
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{ //otherwise the user has lost and prints out statement
				cout << endl << "Sorry, it was A1. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}
		}
		//Rest of if statements are exactly the same except for the different coordinates
		
		if((userin == 'A')&&(userin2 == 2)){ //changes value of variable for p1 if user inputs A2
			if(p1 == 'X'){
				p1 = 'O';
			}else{
				p1 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'A')&&(userin4 == 2)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was A2. Better luck next time." << endl;	
				cout << endl << "Thank you for playing. Exiting. . .";
			}	
		}
		
		if((userin == 'A')&&(userin2 == 3)){ //changes value of variable for p2 if user inputs A3
			if(p2 == 'X'){
				p2 = 'O';
			}else{
				p2 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'A')&&(userin4 == 3)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was A3. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'A')&&(userin2 == 4)){ //changes value of variable for p3 if user inputs A4
			if(p3 == 'X'){
				p3 = 'O';
			}else{
				p3 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'A')&&(userin4 == 4)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was A4. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'A')&&(userin2 == 5)){ //changes value of variable for p4 if user inputs A5
			if(p4 == 'X'){
				p4 = 'O';
			}else{
				p4 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'A')&&(userin4 == 5)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was A5. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'A')&&(userin2 == 6)){ //changes value of variable for p5 if user inputs A6
			if(p5 == 'X'){
				p5 = 'O';
			}else{
				p5 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'A')&&(userin4 == 6)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was A6. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'B')&&(userin2 == 1)){ //changes value of variable for p6 if user inputs B1
			if(p6 == 'X'){
				p6 = 'O';
			}else{
				p6 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'B')&&(userin4 == 1)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was B1. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'B')&&(userin2 == 2)){ //changes value of variable for p7 if user inputs B2
			if(p7 == 'X'){
				p7 = 'O';
			}else{
				p7 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'B')&&(userin4 == 2)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was B2. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'B')&&(userin2 == 3)){ //changes value of variable for p8 if user inputs B3
			if(p8 == 'X'){
				p8 = 'O';
			}else{
				p8 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'B')&&(userin4 == 3)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was B3. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'B')&&(userin2 == 4)){ //changes value of variable for p9 if user inputs B4
			if(p9 == 'X'){
				p9 = 'O';
			}else{
				p9 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'B')&&(userin4 == 4)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was B4. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'B')&&(userin2 == 5)){ //changes value of variable for p10 if user inputs B5
			if(p10 == 'X'){
				p10 = 'O';
			}else{
				p10 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'B')&&(userin4 == 5)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was B5. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'B')&&(userin2 == 6)){ //changes value of variable for p11 if user inputs B6
			if(p11 == 'X'){
				p11 = 'O';
			}else{
				p11 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'B')&&(userin4 == 6)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was B6. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'C')&&(userin2 == 1)){ //changes value of variable for p12 if user inputs C1
			if(p12 == 'X'){
				p12 = 'O';
			}else{
				p12 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'C')&&(userin4 == 1)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was C1. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'C')&&(userin2 == 2)){ //changes value of variable for p13 if user inputs C2
			if(p13 == 'X'){
				p13 = 'O';
			}else{
				p13 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'C')&&(userin4 == 2)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was C2. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'C')&&(userin2 == 3)){ //changes value of variable for p14 if user inputs C3
			if(p14 == 'X'){
				p14 = 'O';
			}else{
				p14 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'C')&&(userin4 == 3)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was C3. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'C')&&(userin2 == 4)){ //changes value of variable for p15 if user inputs C4
			if(p15 == 'X'){
				p15 = 'O';
			}else{
				p15 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'C')&&(userin4 == 4)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was C4. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'C')&&(userin2 == 5)){ //changes value of variable for p16 if user inputs C5
			if(p16 == 'X'){
				p16 = 'O';
			}else{
				p16 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'C')&&(userin4 == 5)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was C5. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'C')&&(userin2 == 6)){ //changes value of variable for p17 if user inputs C6
			if(p17 == 'X'){
				p17 = 'O';
			}else{
				p17 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'C')&&(userin4 == 6)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was C6. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'D')&&(userin2 == 1)){ //changes value of variable for p18 if user inputs D1
			if(p18 == 'X'){
				p18 = 'O';
			}else{
				p18 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'D')&&(userin4 == 1)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was D1. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'D')&&(userin2 == 2)){ //changes value of variable for p19 if user inputs D2
			if(p19 == 'X'){
				p19 = 'O';
			}else{
				p19 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'D')&&(userin4 == 2)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was D2. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'D')&&(userin2 == 3)){ //changes value of variable for p20 if user inputs D3
			if(p20 == 'X'){
				p20 = 'O';
			}else{
				p20 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'D')&&(userin4 == 3)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was D3. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'D')&&(userin2 == 4)){ //changes value of variable for p21 if user inputs D4
			if(p21 == 'X'){
				p21 = 'O';
			}else{
				p21 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'D')&&(userin4 == 4)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was D4. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'D')&&(userin2 == 5)){ //changes value of variable for p22 if user inputs D5
			if(p22 == 'X'){
				p22 = 'O';
			}else{
				p22 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'D')&&(userin4 == 5)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was D5. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'D')&&(userin2 == 6)){ //changes value of variable for p23 if user inputs D6
			if(p23 == 'X'){
				p23 = 'O';
			}else{
				p23 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'D')&&(userin4 == 6)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was D6. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'E')&&(userin2 == 1)){ //changes value of variable for p24 if user inputs E1
			if(p24 == 'X'){
				p24 = 'O';
			}else{
				p24 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'E')&&(userin4 == 1)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was E1. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'E')&&(userin2 == 2)){ //changes value of variable for p25 if user inputs E2
			if(p25 == 'X'){
				p25 = 'O';
			}else{
				p25 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'E')&&(userin4 == 2)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was E2. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'E')&&(userin2 == 3)){ //changes value of variable for p26 if user inputs E3
			if(p26 == 'X'){
				p26 = 'O';
			}else{
				p26 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'E')&&(userin4 == 3)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was E3. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'E')&&(userin2 == 4)){ //changes value of variable for p27 if user inputs E4
			if(p27 == 'X'){
				p27 = 'O';
			}else{
				p27 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'E')&&(userin4 == 4)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was E4. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'E')&&(userin2 == 5)){ //changes value of variable for p27 if user inputs E5
			if(p28 == 'X'){
				p28 = 'O';
			}else{
				p28 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'E')&&(userin4 == 5)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was E5. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'E')&&(userin2 == 6)){ //changes value of variable for p29 if user inputs E6
			if(p29 == 'X'){
				p29 = 'O';
			}else{
				p29 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'E')&&(userin4 == 6)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was E6. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'F')&&(userin2 == 1)){ //changes value of variable for p30 if user inputs F1
			if(p30 == 'X'){
				p30 = 'O';
			}else{
				p30 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'F')&&(userin4 == 1)){
				cout << endl << "*** Congratulations, you did it! ***1" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was F1. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'F')&&(userin2 == 2)){ //changes value of variable for p31 if user inputs F2
			if(p31 == 'X'){
				p31 = 'O';
			}else{
				p31 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'F')&&(userin4 == 2)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was F2. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'F')&&(userin2 == 3)){ //changes value of variable for p32 if user inputs F3
			if(p32 == 'X'){
				p32 = 'O';
			}else{
				p32 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'F')&&(userin4 == 3)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was F3. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";	
			}	
		}
		
		if((userin == 'F')&&(userin2 == 4)){ //changes value of variable for p33 if user inputs F4
			if(p33 == 'X'){
				p33 = 'O';
			}else{
				p33 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'F')&&(userin4 == 4)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was F4. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'F')&&(userin2 == 5)){ //changes value of variable for p34 if user inputs F5
			if(p34 == 'X'){
				p34 = 'O';
			}else{
				p34 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'F')&&(userin4 == 5)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was F5. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}
		
		if((userin == 'F')&&(userin2 == 6)){ //changes value of variable for p35 if user inputs F6
			if(p35 == 'X'){
				p35 = 'O';
			}else{
				p35 = 'X';
			}
			emptySpace();
			printBoard2();
			cin >> userin3;
			userin3 = toupper(userin3);
			cin >> userin4;
			
			if((userin3 == 'F')&&(userin4 == 6)){
				cout << endl << "*** Congratulations, you did it! ***" << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}else{
				cout << endl << "Sorry, it was F6. Better luck next time." << endl;
				cout << endl << "Thank you for playing. Exiting. . .";
			}
		}		
	}
	return 0; //terminates program
}

