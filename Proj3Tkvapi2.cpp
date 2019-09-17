/* ------------------------------------------------
   tkvapi2Prog3.cpp
 
   Program #3: Newton game to get 5 in a row.
               Players alternate placing a piece or
               rotating a column.
   Class: CS 141
   Author: Tomas Kvapil
   Lab: Tues 10am
   System:  CDEV C++

   Grading Rubric:

   50 Execution points
         2 Displays header info and instructions on screen when run
         5 Move number and character-to-move update correctly
         3 Handles upper and lower-case user input, spaces between inputs, and 'X' to exit
         5 Does error checking of user input for valid input and space in column
        10 Handles 'R' to rotate a column
        10 Correctly places pieces on board
        15 Detects a win of 5 in a row, and gives the corresponding ending message
   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
        10 Meaningful identifier names
        10 Comments: Has header and this rubric.  Has comments on each block of code
        10 Appropriate data and control structures 
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/
#include <iostream>
#include <cctype> //For checking for Int type input
using namespace std;

//-------------------------------------------------------------------------------------------------
//Displays ID info as well as instructions to the game
void gameHeader()
{	
	//ID info
	cout << "Author:  Tomas Kvapil" << endl;
	cout << "Class:   CS 141, Spring 2018" << endl;
	cout << "Lab:     Tues 10am" << endl;
	cout << "Program: #3, Newton Game" << endl;
	cout << "DEV C++ on Windows" << endl;
	
	cout << endl; //spacing
	
	//Instructions
	cout << "Welcome to the game of Newton, where you try to be the first" << endl;
	cout << "to get 5 in a row either vertically, horizontally or diagonally." << endl;
	cout << "Two players alternate making moves. On each turn you may enter" << endl;
	cout << "the column number where your piece will be placed, where that" << endl;
	cout << "piece is inserted from the top and slides down as far as it can" << endl;
	cout << "go in that column. You may also enter 'r' to rotate a piece out" << endl;
	cout << "of the bottom of a column to be dropped back in at the top of" << endl;
	cout << "that column. Enter 'x' to exit." << endl;
	
	//spacing
	cout << endl;
	cout << endl;
}//End gameHeader()


//--------------------------------------------------------------------------------------------------
//Initializes all columns to be filled with '.'
void initializeColumn(char column[])
{
	for(int i = 0; i < 8; i++){
		column[i] = '.';
	}
}//End initializeColumn()


//--------------------------------------------------------------------------------------------------
//Prints the game board with updated pieces of X or O
void printBoard(char column1[], char column2[], char column3[], char column4[], char column5[])
{
	cout << endl;
	cout << " 1   2   3   4   5" << endl;
	cout << "--- --- --- --- ---" << endl;	
	cout << " " << column1[7] << "   " << column2[7] << "   " << column3[7] << "   " << column4[7] << "   " << column5[7] << endl;
	cout << " " << column1[6] << "   " << column2[6] << "   " << column3[6] << "   " << column4[6] << "   " << column5[6] << endl;
	cout << " " << column1[5] << "   " << column2[5] << "   " << column3[5] << "   " << column4[5] << "   " << column5[5] << endl;
	cout << " " << column1[4] << "   " << column2[4] << "   " << column3[4] << "   " << column4[4] << "   " << column5[4] << endl;
	cout << " " << column1[3] << "   " << column2[3] << "   " << column3[3] << "   " << column4[3] << "   " << column5[3] << endl;
	cout << " " << column1[2] << "   " << column2[2] << "   " << column3[2] << "   " << column4[2] << "   " << column5[2] << endl;
	cout << " " << column1[1] << "   " << column2[1] << "   " << column3[1] << "   " << column4[1] << "   " << column5[1] << endl;
	cout << " " << column1[0] << "   " << column2[0] << "   " << column3[0] << "   " << column4[0] << "   " << column5[0] << endl;
	cout << "--- --- --- --- ---" << endl;	
	cout << " 1   2   3   4   5" << endl;
	cout << endl;
}//End printBoard()


//--------------------------------------------------------------------------------------------------
//Checks if user input is a valid character (X or R)
bool validChar(char userChar)
{
		if((userChar == 'x')||(userChar == 'X')||(userChar == 'r')||(userChar == 'R')){
			return true;
		}
		return false;
	}//End validChar
	
	
//--------------------------------------------------------------------------------------------------
//Checks if the user input of a digit is in range (0<input<6)
bool inRange(int userInt)
{
	if((userInt > 0)&&(userInt < 6)){
		return true;
	}
	return false;
}//End inRange


//--------------------------------------------------------------------------------------------------
//Converts user digit into Int type
void convertInt(char userChar, int& userInt)
{
	userInt = static_cast<int>(userChar);
	userInt = userInt - '0';
}//End convertInt()


//--------------------------------------------------------------------------------------------------
//Depending on user input of digit, copies elements of column to a temporary column
void switchToTemp(char column1[], char column2[], char column3[], char column4[], char column5[], int userInt, char tempcol[])
{
	switch(userInt){
		case 1: for(int i = 0; i < 8; i++){
			tempcol[i] = column1[i];
		}break;
		case 2: for(int i = 0; i < 8; i++){
			tempcol[i] = column2[i];
		}break;
		case 3: for(int i = 0; i < 8; i++){
			tempcol[i] = column3[i];
		}break;
		case 4: for(int i = 0; i < 8; i++){
			tempcol[i] = column4[i];
		}break;
		case 5: for(int i = 0; i < 8; i++){
			tempcol[i] = column5[i];
		}break;		
	}
}//End switchToTemp()


//--------------------------------------------------------------------------------------------------
//Adds an X or O to the temporary column in the correct position
void addXorO(char tempcol[], char XorO)
{
		for(int i =0; i<8; i++){
			if(tempcol[i] == '.'){
				tempcol[i] = XorO;
				break;
			}
		}
}//End addXorO

	
//--------------------------------------------------------------------------------------------------
//Rotates the elements of the temporary column
void rotateCol(char tempCol[])
{
	char tempval = ' ';
	int counter = 0;
	
	tempval = tempCol[0];
	
	//counts number of elements if x or o
	for(int i = 0; i < 8 ; i++){
		if((tempCol[i]=='X')||(tempCol[i]=='O')){
			counter++;
		}	
	}
	
	//moves all elements down an index
	for(int j = 0; j<counter-1; j++){
		tempCol[j] = tempCol[j+1];
	}
	
	tempCol[counter-1] = tempval;
}//End rotateCol()

//--------------------------------------------------------------------------------------------------
//Checks if the temporary column is full
bool checkFull(char tempcol[])
{	
	int numPeriod = -1; //need -1 to account for columns full of only '.'
	
	for(int i=0; i<8; i++){
		if(tempcol[i]=='.'){
			numPeriod++;
		}
	}
	if(numPeriod == -1){
		return true;
	}
	return false;
}//End checkFull()

	
//--------------------------------------------------------------------------------------------------
//Switches temporary column back to orginal column by copying temporay elements to original
void switchBack(char column1[], char column2[], char column3[], char column4[], char column5[], int userInt, char tempcol[])
{
	switch(userInt){	
		case 1: for(int i = 0; i < 8; i++){
			column1[i] = tempcol[i];
		}break;
		case 2: for(int i = 0; i < 8; i++){
			column2[i] = tempcol[i];
		}break;
		case 3: for(int i = 0; i < 8; i++){
			column3[i] = tempcol[i];
		}break;
		case 4: for(int i = 0; i < 8; i++){
			column4[i] = tempcol[i];
		}break;
		case 5: for(int i = 0; i < 8; i++){
			column5[i] = tempcol[i];
		}break;
	}
}//End switchBack()


//--------------------------------------------------------------------------------------------------
//Switches value of XorO to X or O depending on which turn it is
void switchXorO(int counter, char& XorO)
{
		if(counter%2 == 0){
			XorO = 'X';
		}else{
			XorO = 'O';
		}
}//End switchXorO()


//--------------------------------------------------------------------------------------------------
//Checks if the elements in a row are all the same to determine winner
bool winnerByRow(char column1[], char column2[], char column3[], char column4[], char column5[], char XorO)
{
	
	for(int i=0; i < 5;i++){
		
		//first checks if row does not contain a '.'
		if((column1[i]!='.')&&(column2[i]!='.')&&(column3[i]!='.')&&(column4[i]!='.')&&(column5[i]!='.')){
			
			//decides winner if all elements in a row are the same		
			if((column1[i]==column2[i])&&(column1[i]==column3[i])&&(column1[i]==column4[i])&&(column1[i]==column5[i])){
				printBoard(column1, column2, column3, column4, column5);
				cout << endl;
				cout << "*** Congratulations, Winner is: " << XorO;
				return true;
			}
		}
	}
	return false;
}//End winnerByRow()


//--------------------------------------------------------------------------------------------------
//Checks if five of the same element atop of eachother are the same to determine winner
bool winnerByCol(char column1[], char column2[], char column3[], char column4[], char column5[], char tempcol[], char XorO, int userInt)
{
	char matchChar = XorO;//Current set of XorO
	
	//lowest possible value of i is 0 and highest is 3 due to height of column
	for(int i=0;i<4;i++){
		
		//makes sure that all five in a row in the column are not a '.'
		if((tempcol[i]!='.')&&(tempcol[i+1]!='.')&&(tempcol[i+2]!='.')&&(tempcol[i+3]!='.')&&(tempcol[i+4]!='.')){
			
		//If five in a row in a single column are equal to value of XorO then there is a winner
			if((tempcol[i]==matchChar)&&(tempcol[i+1]==matchChar)&&(tempcol[i+2]==matchChar)&&(tempcol[i+3]==matchChar)&&(tempcol[i+4]==matchChar)){
					switchBack(column1, column2, column3, column4, column5, userInt, tempcol);
					printBoard(column1, column2, column3, column4, column5);
					cout << endl;
					cout << "*** Congratulations, Winner is: " << XorO;
					return true;	
				}
		}
	}	
	return false;
}//End winnerByCol()


//--------------------------------------------------------------------------------------------------
//Checks all possible diagonals starting from upper left to see if there is a winner
bool winnerDiagonalUpperLeft(char column1[], char column2[], char column3[], char column4[], char column5[], char XorO)
{
	//starts off at index 7 and goes down to index 4
	for(int i = 7; i>3; i--){
		
		//makes sure that there are no '.'
		if((column1[i]!='.')&&(column2[i-1]!='.')&&(column3[i-2]!='.')&&(column4[i-3]!='.')&&(column5[i-4]!='.')){
			
			//checks if all possible diagonals
			if((column1[i]==column2[i-1])&&(column1[i]==column3[i-2])&&(column1[i]==column4[i-3])&&(column1[i]==column5[i-4])){
					printBoard(column1, column2, column3, column4, column5);
					cout << endl;
					cout << "*** Congratulations, Winner is: " << XorO;
					return true;
			}
		}
	}
	return false;
}//End winnerDiagonalUpperLeft()


//--------------------------------------------------------------------------------------------------
//Checks all possible diagonals startinf from lover left to see if there is a winner
bool winnerDiagonalLowerLeft(char column1[], char column2[], char column3[], char column4[], char column5[], char XorO)
{
	//starts off at index 0 and goes up to index 3
	for(int i = 0; i<4; i++){
		
		//makes sure that no elemts is '.'
		if((column1[i]!='.')&&(column2[i+1]!='.')&&(column3[i+2]!='.')&&(column4[i+3]!='.')&&(column5[i+4]!='.')){
			
			//checks to see if diaganol are the same
			if((column1[i]==column2[i+1])&&(column1[i]==column3[i+2])&&(column1[i]==column4[i+3])&&(column1[i]==column5[i+4])){
					printBoard(column1, column2, column3, column4, column5);
					cout << endl;
					cout << "*** Congratulations, Winner is: " << XorO;
					return true;
			}
		}
	}
	return false;
}//End winnerDiagonalLowerLeft


//--------------------------------------------------------------------------------------------------
int main()
{
	char column1[8];
	char column2[8];
	char column3[8];
	char column4[8];
	char column5[8];
	char tempcol[8];
	char XorO = 'X'; //first move puts X
	char userChar; //initial user input
	int userInt; //this will be converted version of userChar
	int counter = 1; //used to decide XorO
	
	gameHeader(); //Displays header
	
	//initializes all column to '.'
	initializeColumn(column1);
	initializeColumn(column2);
	initializeColumn(column3);
	initializeColumn(column4);
	initializeColumn(column5);
	
	
	do{ 
		printBoard(column1, column2, column3, column4, column5); //Displays the gameboard
		cout << counter << ". Enter column number to place " << XorO << " or 'r' to rotate:";
		cin >> userChar;
		cout << endl;
				
		//Makes sure that the input is an x or r
		while(!(isdigit(userChar))&&!(validChar(userChar))){				
			cout << "*** Invalid character, please retry." << endl << endl;
			cout << counter << ". Enter column number to place " << XorO << " or 'r' to rotate:";
			cin >> userChar;
		}
		

		if(isdigit(userChar)){ //checks if user input is a digit
			convertInt(userChar, userInt); //converts to int type
			
			if(inRange(userInt)){ //checks if int is in range
				switchToTemp(column1, column2, column3, column4, column5, userInt, tempcol); //switches to temporary column
				
				//loops if and prompts for input if column is full
				while(checkFull(tempcol)){
					switchBack(column1, column2, column3, column4, column5, userInt, tempcol);
					cout << "*** Column full. Please retry..." << endl << endl;
					cout << counter << ". Enter column number to place " << XorO << " or 'r' to rotate:";
					cin >> userInt;
					
					//Breaks out of loop if user inputs a valid column that is not full
					if(userInt != (userChar - '0')){ 
						switchToTemp(column1, column2, column3, column4, column5, userInt, tempcol);
						break;
					}
				}
				addXorO(tempcol, XorO); //add an x or o
		
			}else{
				
				//loops if user input is not in range until user inputs integer in range
				while(!(inRange(userInt))){
					cout << "*** Invalid input. Please retry..." << endl << endl;
					cout << counter << ". Enter column number to place " << XorO << " or 'r' to rotate:";
					cin >> userInt;
				}
				
				switchToTemp(column1, column2, column3, column4, column5, userInt, tempcol); //Switches to temporary column
				addXorO(tempcol, XorO); //adds x or o
				}	
			}
		
		
		if((userChar == 'x')||(userChar == 'X')){ //Exits the program if input is x
			cout << "Exiting program..." << endl;
			return 0;
		}
		
		if((userChar == 'r')||(userChar == 'R')){ //Prompts to rotate if user inputs r
			cin >> userChar; // prompts for an integer input
			
			if(isdigit(userChar)){ //checks if digit
				convertInt(userChar, userInt); //converts to integer
			}
			switchToTemp(column1, column2, column3, column4, column5, userInt, tempcol); //switches to temporary column
			rotateCol(tempcol);	//rotates that column
		}
		
		switchBack(column1, column2, column3, column4, column5, userInt, tempcol); //switches to original column
		if(winnerByRow(column1, column2, column3, column4, column5, XorO)){ //checks winner by Row
			return 0;
		}
		
		
		switchToTemp(column1, column2, column3, column4, column5, userInt, tempcol); //switches to temp because winnerByCol requires single column 
		if(winnerByCol(column1, column2, column3, column4, column5, tempcol, XorO, userInt)){ //checks winner by column
			return 0;
		}
		switchBack(column1, column2, column3, column4, column5, userInt, tempcol); //switches to original column if no winner
		
		
		if(winnerDiagonalUpperLeft(column1, column2, column3, column4, column5, XorO)){ //checks winner by diagnol starting upper left
			return 0;
		}
		
		
		if(winnerDiagonalLowerLeft(column1, column2, column3, column4, column5, XorO)){ //checks winner by diagnol starting lower left
			return 0;
		}
		
		switchXorO(counter, XorO); //switches value of XorO to x or o depending on which turn it is

		counter++; //adds to counter to make sure the turn is counted			
		
	}while(true); //keeps looping and breaks inside the loop
	
	return 0;
}//End main()
