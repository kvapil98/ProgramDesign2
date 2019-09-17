/* ------------------------------------------------
   tkvapi2Prog5.cpp
 
   Program #5: Ricochet Robots: Allow solving the sliding robots puzzle
   Class: CS 141
   Author: Tomas Kvapil
   Lab: Tues 10am
   System:  DEV C++

   Grading Rubric:

   55 Execution points
        2 Displays header info and instructions on screen when run
        3 Displays the board (Since I'm giving you all the code for this...)
        5 Allows selecting default values (robot 2 to square M), random values, or user-selected values.
       15 Allows making moves, displaying move numbers.  Input can be upper or lower case, and can have spaces or not.
       20 Robots stop at walls and don't run over each other
        5 Game stops and message is given when goal robot makes it to the goal square.
        5 If some robot besides robot 2 goes to the destination square (square M in this case), the destination square should change to show the robot there. When this robot moves away, the square should go back to displaying the letter that was there previously (M in our case.)

   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
         5 Meaningful identifier names
         5 Comments: Has header and this rubric.  Has comments on each block of code
        20 Appropriate data and control structures. Is implemented using classes.
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/

#include <iostream>
#include <cstring>      // for getline
#include <cstdlib>      // for the system command
#include <cctype>       // For the letter checking functions, e.g. toupper( )
#include <fstream>      // For file input and output
#include <time.h>       //to make random different each time
using namespace std;

// Global data structure for board
const int BOARD_EDGE = 16;
const int BOARD_SIZE = BOARD_EDGE * BOARD_EDGE;
const int NUMBER_OF_ROBOTS = 4;
// declare constants to later use instead of numbers to select values from theBoard
const int NUMBER_OF_ELEMENTS = 5;   // Number of elements for each piece, enumerated below
const int PIECE = 0;    // to reference the character, such as in: theBoard[ i][ PIECE]
const int LEFT = 1;     // to reference the left wall character, such as in: theBoard[ i][ LEFT]
const int ABOVE = 2;    // to reference the above wall character, such as in: theBoard[ i][ ABOVE]
const int RIGHT = 3;    // to reference the right wall character, such as in: theBoard[ i][ RIGHT]
const int BELOW = 4;    // to reference the below wall character, such as in: theBoard[ i][ BELOW]


//-------------------------------------------------------------------------------------
// class Board{} - the class that drives all functions
//
class Board{
	
	private:
		char theBoard[BOARD_SIZE][NUMBER_OF_ELEMENTS]; 
	
	public:
		void displayIdentifyingInformationAndInstructions();
		void createBoard( char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS]);
		void readFromFileAndModifyBoard(char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS], int theRobots[ ], int &numberOfDestinationPieces);
		void displayTheBoard( char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS]);
		bool winCondition(int theRobots[], int& goalRobot, int& letterIndex, int& counter);
		void moveUp(char theBoard[][NUMBER_OF_ELEMENTS], int& robotIndex, int theRobots[], int& selRobot, char& destinationLetter, int& goalRobot, int& letterIndex);
		void moveDown(char theBoard[][NUMBER_OF_ELEMENTS], int& robotIndex, int theRobots[], int& selRobot, char& destinationLetter, int& goalRobot, int& letterIndex);
		void moveLeft(char theBoard[][NUMBER_OF_ELEMENTS], int& robotIndex, int theRobots[], int& selRobot, char& destinationLetter, int& goalRobot, int& letterIndex);
		void moveRight(char theBoard[][NUMBER_OF_ELEMENTS], int& robotIndex, int theRobots[], int& selRobot, char& destinationLetter, int& goalRobot, int& letterIndex);
		void makeDefault(char theBoard[][NUMBER_OF_ELEMENTS], int& goalRobot, char& destinationLetter, int& letterIndex);
		void makeSelect(char theBoard[][NUMBER_OF_ELEMENTS], int& goalRobot, char& destinationLetter, int& letterIndex);
		void makeRandom(char theBoard[][NUMBER_OF_ELEMENTS], int& goalRobot, char& destinationLetter, int& letterIndex);
		
};//end class Board{}


//-------------------------------------------------------------------------------------
// displayIdentifyingInformationAndInstructions() - displays id info and instructions
//
void Board::displayIdentifyingInformationAndInstructions()
{
    // Display identifying information
    cout << "Author: Tomas Kvapil                   " << endl
         << "Program 5: RicoRobots in C++         " << endl
         << "TA: Anant, T 10:00 AM  " << endl
         << "April 11, 2018                       " << endl;

    // Display Instructions
    cout << "Welcome to Ricochet Robots                                     " << endl
         << "(\'Ricochet Robot\' is a registered trademark of Hans im Glück " << endl
         << "Munich, Germany, 1999. The game was created by Alex Randolph.) " << endl
         << endl
         << "The object of the game is to get the designated numbered robot " << endl
         << "to the indicated letter position.                              " << endl
         << "The numbered squares are all robots.  They unfortunately have  " << endl
         << "no brakes, and so will continue in whatever direction they are " << endl
         << "moving until they encountar an obstacle.                       " << endl
         << "For each move enter the robot number and the desired direction." << endl
         << "For instance entering                                          " << endl
         << "   1 U " << endl
         << "would move the #1 robot up as far as it can go.                " << endl
         << "The first letter of input is the robot number (1 - 4),         " << endl
         << "and the second letter is the direction:                        " << endl
         << "  (L=left, U=up, R=right, D=down)                              " << endl
         << "Enter x to exit.  Have fun!                                    " << endl
         <<  endl;
}//end displayIdentifyingInformationAndInstructions()


//-------------------------------------------------------------------------------------
//createBoard() - Create the board, initializing all the display characters
//
void Board::createBoard( char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS])
{
    for( int i=0; i<BOARD_SIZE; i++) {
        theBoard[ i][ PIECE]= '.';    // Set each playing piece default
        // set the default wall values to be blank
        theBoard[ i][ LEFT]= ' ';
        theBoard[ i][ ABOVE]= ' ';
        theBoard[ i][ RIGHT]= ' ';
        theBoard[ i][ BELOW]=  ' ';
        
        // reset the edge pieces
        // reset the left wall if piece is on left edge
        if( (i % BOARD_EDGE) == 0) {
            theBoard[ i][ LEFT]= '|';
        }
        // reset the above wall if piece is on top edge
        if( i < BOARD_EDGE) {
            theBoard[ i][ ABOVE]= '-'; 
        }
        // reset the right wall if piece is on right edge
        if( ((i+1) % BOARD_EDGE) == 0) {
            theBoard[ i][ RIGHT]= '|';
        }
        // reset the below wall if piece is on bottom edge
        if( i >= (BOARD_SIZE - BOARD_EDGE) ) {
            theBoard[ i][ BELOW]= '-';
        }
    }//end for( int i...
    
}//end createBoard()


//-------------------------------------------------------------------------------------
//readFromFileAndModifyBoard() - Read from data file, updating board accordingly
//
void Board::readFromFileAndModifyBoard(
        char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS],
        int theRobots[ ],
        int &numberOfDestinationPieces)
{
    int numberOfSpecialSquares;  // Read from file, denotes number of pieces with some kind of wall
    string inputLine;            // Input line from file
    int pieceNumber;             // pieceNumber for each square defined in data file
    char c;
    
    ifstream inStream;           // declare an input file stream
    inStream.open("board.txt");  // Open input file, associating the actual file name with "inStream"
    if ( inStream.fail() ) {
        cout << "Input file opening failed.  Exiting...\n\n";
        exit(-1);
    }
    
    // Read from file one line at a time.  First read the top three data file lines which are documentation.
    getline( inStream, inputLine);
    getline( inStream, inputLine);
    getline( inStream, inputLine);
    
    inStream >> numberOfDestinationPieces;      // read how many destination pieces there are
    inStream >> numberOfSpecialSquares;         // number of square with walls around them somewhere
    inStream.get( c);                           // Get rid of return character at end of current line
                                                // to get ready for reading a line at a time below
    
    // process the special squares, updating the board
    for( int i=0; i<numberOfSpecialSquares; i++) {
        getline( inStream, inputLine);
        char *pInputLine = &inputLine[0];
        // Extract the piece number from the input line array
        sscanf( pInputLine, "%d", &pieceNumber);
        // Advance the inputLine pointer to the space after the number
        pInputLine = strchr( pInputLine, ' ');

        // Read the information on whether or not there is each of the potential 4 walls.
        // The four values read correspond in order to the pieces on all four sides,
        // which are defined as global constants for the values LEFT=1, ABOVE=2, RIGHT=3, BELOW=4
        for( int position=1; position<=4; position++) {
            pInputLine++;   // advance to next character to be read
            sscanf( pInputLine, " %c", &c);         // Read the next potential wall character
            // Convert it to a blank if it was '0'.  '0' was left in input file to make it easier to read.
            if( c=='0') {
                c = ' ';
            }
            theBoard[ pieceNumber][ position] = c;
        }
        pInputLine++;

        // See if there is a piece letter still to be read on this input line.
        // Do this by finding the end of the line, and seeing the length of the string
        // after that.
        // An inputline sample for piece 18 would be:
        // 18 00|- A
        if( strlen( pInputLine) > 0) {
            sscanf( pInputLine, " %c", &theBoard[ pieceNumber][ PIECE]);
        }

    }//end for( int i...
    
    // At the end of the data file read the information on the location of the robots, updating the board.
    char junk[80];           // used to read and discard input file information
    // Loop starts counting from 1 (rather than 0), since we ignore the 0th position
    // of the robots array, so that robot numbers correspond to what is shown
    // on the board.
    for( int i=1; i<=NUMBER_OF_ROBOTS; i++) {
        inStream >> theRobots[ i];
        inStream.getline( junk, '\n');    // discard rest of line, which is color information, if using graphics
        // set robot on board, converting the integer value to a character
        theBoard[ theRobots[ i]][ PIECE] = (char)('0'+i);     // record the robot number in place on board
    }
    
    inStream.close();         // close the input file stream
}//end readFromFileAndModifyBoard()


//-------------------------------------------------------------------------------------
// displayTheBoard() - displays the entire board
//
void Board::displayTheBoard( char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS])
{
    // display the top edge
    cout << "  ---------------------------------------------------------------- " << endl;
    
    // display the "body" of the board
    for( int i=0; i<BOARD_SIZE; i++) {
        // Figure out what character should be displayed to the left.  It will
        // be a wall if the current spot has a left wall, or if the spot to the
        // left has a right wall.
        
        char leftCharacter = theBoard[ i][ LEFT];   // set left display char
        // See if the piece to the left has a right wall.  Don't do this for the
        // first piece on the board, since it has no left neighbor.
        if ( (i>0) && (theBoard[ i-1][ RIGHT] != ' ')) {
            leftCharacter = theBoard[ i-1][ RIGHT];
        }
        cout << " " << leftCharacter << " " << theBoard[ i][ PIECE];
        // see if we're at the end of a row
        if( ((i+1) % BOARD_EDGE) == 0) {
            // we are at the end of a row, so display right wall and go to next line
            cout << "  " << theBoard[ i][ RIGHT] << endl;
            // Now display any walls immediately below the line of pieces just displayed
            // Backup our index counter j to the beginning of this line again, to find any
            // walls displayed below this line.  Don't do it for the bottom row though.
            if( i < BOARD_SIZE - BOARD_EDGE) {
            
                cout << " |";       // display the left boundary
                for( int j=i-BOARD_EDGE+1; j<(i+1); j++) {
                    // Set the character to be displayed.  This is a wall if the
                    // current spot has a wall below, or if the spot below has a wall
                    // above.
                    char belowCharacter = theBoard[ j][ BELOW];
                    // Only check the square below if we're NOT on the bottom row
                    if ( (j<(BOARD_SIZE - BOARD_EDGE)) &&      // verify not on bottom row
                        (theBoard[ j+16][ ABOVE] != ' ')) {    // piece below has wall above
                        belowCharacter = theBoard[ j+16][ ABOVE];
                    }
                    for( int i=0; i<3; i++) {
                       cout << belowCharacter;        // display the character
                    }
                    // display extra spaces, if we're not at the end of a row
                    if( ((j+1) % BOARD_EDGE) != 0) {
                        cout << " ";
                    }
                }//end for( int j...
                cout << " |" << endl;       // display the right boundary
            }//end if( i< BOARD_SIZE...

        }//end if( ((i+1...
        
    }//end for( int i=0;...
    
    // display the bottom edge
    cout << "  ---------------------------------------------------------------- " << endl;
    cout << endl;
}//end displayTheBoard()


//-------------------------------------------------------------------------------------
// winCondition() - checks if the win condition is met
//
bool Board::winCondition(int theRobots[], int& goalRobot, int& letterIndex, int& counter)
{
	
	//makes sure the goal robot is on the destination letter
	if(theRobots[goalRobot] == letterIndex){
		cout << "Congratulations! You did it in only " << counter << " moves." << endl;
		cout << "Exiting program..." << endl;
		return true;
	}
	return false;
}//end winCondition()


//-------------------------------------------------------------------------------------
//moveUp() - moves tageted robot up until hits an obstacle
//
void Board::moveUp(char theBoard[][NUMBER_OF_ELEMENTS], int& robotIndex, int theRobots[], int& selRobot, char& destinationLetter, int& goalRobot, int& letterIndex)
{

    
	while(!((theBoard[robotIndex][ABOVE] == '-')||(theBoard[robotIndex-16][BELOW]=='-'))&&!(theBoard[robotIndex - 16][PIECE]!='.')){
		
		//allows non goalrobots to pass through destination letter
		if((robotIndex == letterIndex)&&(selRobot != goalRobot)){
			theBoard[robotIndex][PIECE] = destinationLetter;
		}else{
			theBoard[ robotIndex][ PIECE] = '.'; // blank out where we're coming FROM
		} 

	    theRobots[ selRobot] = robotIndex - 16;     // Reset robot position index to the square above
	    robotIndex = theRobots[ selRobot];          // Get the new stored value reflecting the new position
	    // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
	    // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
	    // character '2'.
	    theBoard[ robotIndex][ PIECE] = '0'+selRobot;
	
	    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	    displayTheBoard( theBoard);
	}
	
	//allows for robots to pass into the square that has the destination letter
	if(theBoard[robotIndex-16][PIECE]==destinationLetter){		
		theBoard[robotIndex][PIECE] = '.'; // blank out where we're coming FROM
		theRobots[ selRobot] = robotIndex - 16; // Reset robot position index to the square above
		robotIndex = theRobots[ selRobot]; // Get the new stored value reflecting the new position
		theBoard[robotIndex][PIECE] = '0'+ selRobot;
	    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	    displayTheBoard( theBoard);
	}
	
}//end moveUp()


//-------------------------------------------------------------------------------------
//moveDown() - moves tageted robot down until hits an obstacle
//
void Board::moveDown(char theBoard[][NUMBER_OF_ELEMENTS], int& robotIndex, int theRobots[], int& selRobot, char& destinationLetter, int& goalRobot, int& letterIndex)
{
	
    while(!((theBoard[robotIndex][BELOW] == '-')||(theBoard[robotIndex+16][ABOVE]=='-'))&&!(theBoard[robotIndex+16][PIECE]!='.')){
		
		//allows non goalrobots to pass through destination letter
		if((robotIndex == letterIndex)&&(selRobot != goalRobot)){
			theBoard[robotIndex][PIECE] = destinationLetter;
		}else{
			theBoard[ robotIndex][ PIECE] = '.'; // blank out where we're coming FROM
		} 
		 
	    theRobots[ selRobot] = robotIndex + 16;     // Reset robot position index to the square above
	    robotIndex = theRobots[ selRobot];          // Get the new stored value reflecting the new position
	    // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
	    // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
	    // character '2'.
	    theBoard[ robotIndex][ PIECE] = '0'+selRobot;
	
	    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	    displayTheBoard( theBoard);
	}
	
	//allows for robots to pass into the square that has the destination letter
	if(theBoard[robotIndex+16][PIECE]==destinationLetter){		
		theBoard[robotIndex][PIECE] = '.'; // blank out where we're coming FROM
		theRobots[ selRobot] = robotIndex + 16; // Reset robot position index to the square above
		robotIndex = theRobots[ selRobot]; // Get the new stored value reflecting the new position
		theBoard[robotIndex][PIECE] = '0'+ selRobot;
	    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	    displayTheBoard( theBoard);
	}
}//end moveDown()


//-------------------------------------------------------------------------------------
//moveLeft() - moves tageted robot left until hits an obstacle
//
void Board::moveLeft(char theBoard[][NUMBER_OF_ELEMENTS], int& robotIndex, int theRobots[], int& selRobot, char& destinationLetter, int& goalRobot, int& letterIndex)
{
	
	//allows non goalrobots to pass through destination letter
    while(!((theBoard[robotIndex][LEFT] == '|')||(theBoard[robotIndex-1][RIGHT]=='|'))&&!(theBoard[robotIndex-1][PIECE]!='.')){
		
		//allows non goalrobots to pass through destination letter
		if((robotIndex == letterIndex)&&(selRobot != goalRobot)){
			theBoard[robotIndex][PIECE] = destinationLetter;
		}else{
			theBoard[ robotIndex][ PIECE] = '.'; // blank out where we're coming FROM
		}
		  
	    theRobots[ selRobot] = robotIndex - 1;     // Reset robot position index to the square above
	    robotIndex = theRobots[ selRobot];          // Get the new stored value reflecting the new position
	    // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
	    // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
	    // character '2'.
	    theBoard[ robotIndex][ PIECE] = '0'+selRobot;
	
	    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	    displayTheBoard( theBoard);
	}
	
	//allows for robots to pass into the square that has the destination letter
	if(theBoard[robotIndex-1][PIECE]==destinationLetter){		
		theBoard[robotIndex][PIECE] = '.'; // blank out where we're coming FROM
		theRobots[ selRobot] = robotIndex - 1; // Reset robot position index to the square above
		robotIndex = theRobots[ selRobot]; // Get the new stored value reflecting the new position
		theBoard[robotIndex][PIECE] = '0'+ selRobot;
	    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	    displayTheBoard( theBoard);
	}
}//end moveLeft()


//-------------------------------------------------------------------------------------
//moveRight() - moves tageted robot right until hits an obstacle
//
void Board::moveRight(char theBoard[][NUMBER_OF_ELEMENTS], int& robotIndex, int theRobots[], int& selRobot, char& destinationLetter, int& goalRobot, int& letterIndex)
{
	
	//allows non goalrobots to pass through destination letter
    while(!((theBoard[robotIndex][RIGHT] == '|')||(theBoard[robotIndex+1][LEFT]=='|'))&&!(theBoard[robotIndex+1][PIECE]!='.')){
		
		//allows non goalrobots to pass through destination letter
		if((robotIndex == letterIndex)&&(selRobot != goalRobot)){
			theBoard[robotIndex][PIECE] = destinationLetter;
		}else{
			theBoard[ robotIndex][ PIECE] = '.'; // blank out where we're coming FROM
		}  
		
	    theRobots[ selRobot] = robotIndex + 1;     // Reset robot position index to the square above
	    robotIndex = theRobots[ selRobot];          // Get the new stored value reflecting the new position
	    // Place robot number where we're going TO.  We have to add '0' to the goal robot because the robot
	    // number is the integer 2, but the board stores characters, so we have to convert integer 2 to
	    // character '2'.
	    theBoard[ robotIndex][ PIECE] = '0'+selRobot;
	
	    //cout << "After moving robot " << goalRobot << " upwards one square we now have: " << endl;
	    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	    displayTheBoard( theBoard);
	}
	
	//allows for robots to pass into the square that has the destination letter
	if(theBoard[robotIndex+1][PIECE]==destinationLetter){		
		theBoard[robotIndex][PIECE] = '.'; // blank out where we're coming FROM
		theRobots[ selRobot] = robotIndex + 1; // Reset robot position index to the square above
		robotIndex = theRobots[ selRobot]; // Get the new stored value reflecting the new position
		theBoard[robotIndex][PIECE] = '0'+ selRobot;
	    cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	    displayTheBoard( theBoard);
	}
}//end moveRight()


//-------------------------------------------------------------------------------------
//makeDefault() - intializes the board to the default goal and target
//
void Board::makeDefault(char theBoard[][NUMBER_OF_ELEMENTS], int& goalRobot, char& destinationLetter, int& letterIndex)
{
	
	//erases nondestination letters
	for(int i = 0; i<BOARD_SIZE; i++){
		if(isalpha(theBoard[i][PIECE])&&theBoard[i][PIECE]!=theBoard[198][PIECE]){
			theBoard[i][PIECE] = '.';
		}
	}
	
	goalRobot = 2; //sets goal robaot
	destinationLetter = theBoard[198][PIECE]; //sets destination letter to letter that is default
	letterIndex = 198; //sets letter index to default index
}//end makeDefault()


//-------------------------------------------------------------------------------------
//makeSelect() - allows user to select destination and goal robot
//
void Board::makeSelect(char theBoard[][NUMBER_OF_ELEMENTS], int& goalRobot, char& destinationLetter, int& letterIndex)
{
	int selRobot; //user selected robot
	char selDest; //user selected destination
	
	cout << "Enter the goal robot number and the destination letter: ";
	cin >> selRobot;
	cin >> selDest;
	selDest = toupper(selDest);
	cout << endl;
	
	//erases nonselected letters
	for(int i =0; i < BOARD_SIZE; i++){
		if(isalpha(theBoard[i][PIECE])&&theBoard[i][PIECE]!= selDest){
			theBoard[i][PIECE] = '.';
		}
	}
	
	goalRobot = selRobot; //sets the goal robot
	destinationLetter = selDest; //sets the destination letter
	
	//sets the letterIndex
	for(int i=0; i<BOARD_SIZE; i++){
		if(theBoard[i][PIECE]==destinationLetter){
			letterIndex = i;
			break;
		}
	}
}//end makeSelect()


//-------------------------------------------------------------------------------------
//makeRandom() - makes target destination and goal robot random
//
void Board::makeRandom(char theBoard[][NUMBER_OF_ELEMENTS], int& goalRobot, char& destinationLetter, int& letterIndex)
{
	srand(time(NULL)); //creates a rndom seed
	
	goalRobot = rand()%4; //chooses a random robot number
	if(goalRobot == 0){
		goalRobot ++;
	}
	
	//keeps track of number of letters in text file
	int letterCounter;
	for(int i =0; i<BOARD_SIZE; i++){
		if(isalpha(theBoard[i][PIECE])){
			letterCounter ++;
		}
	}
	
	destinationLetter = 'A' + rand()%letterCounter; //sets destination letter to random letter
	
	//eraes all nontarget letters
	for(int i=0; i<BOARD_SIZE; i++){
		if(isalpha(theBoard[i][PIECE])&&theBoard[i][PIECE]!=destinationLetter){
			theBoard[i][PIECE]='.';
		}
	}
	
	//sets letterIndex to correct index of destination letter
	for(int i=0; i<BOARD_SIZE; i++){
		if(theBoard[i][PIECE]==destinationLetter){
			letterIndex = i;
			break;
		}
	}
}//end makeRandom()


//-------------------------------------------------------------------------------------
// main() - main part of program, that drives everything else
//
int main()
{
	Board newBoard; //sets class variable
    // theBoard itself is represented by a one-dimensional array.
    // The other entries are used to keep track of walls.  Each row
    // in theBoard array will contain the character to be displayed,
    // followed by any "walls" to be displayed around the displayed
    // character.  For instance the first couple of entries are be:
    //
    //       PIECE   LEFT ABOVE RIGHT BELOW
    //      ---0---  --1-  --2-  --3-  --4-
    //    0    .       |     _
    //    1    .             _
    //   ...
    //   255   .                   |     _
    //
    char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS];
    // Declare the 4 robots, which will store the board position of where they are found
    // Robots are displayed using values 1-4.  We declare 5 robots, though we will never use
    // the 0th robot in the array, so that we can use the robot digit itself as the index.
    int theRobots[ NUMBER_OF_ROBOTS + 1] = {0,0,0,0,0};

    int goalRobot;                  // the robot that needs to reach the goal
    char destinationLetter;         // the goal letter
    int numberOfDestinationPieces;  // Number of destination pieces.  Value
                                    //    comes from the data file.
    
    newBoard.displayIdentifyingInformationAndInstructions();
    newBoard.createBoard( theBoard);   // create the board, initializing all pieces to their default settings
    newBoard.readFromFileAndModifyBoard( theBoard, theRobots, numberOfDestinationPieces); // read from the datafile, updating board
    
    
    char selBoard; //prompts user to input type of board
    cout << "Enter 'r' for random robot and goal, 'd' for default or 's' to select: ";
    cin >> selBoard;
	selBoard = toupper(selBoard); 
    int letterIndex;
    
    //sets board to default
    if(selBoard == 'D'){
    	newBoard.makeDefault(theBoard, goalRobot, destinationLetter, letterIndex);
	}
	
	//set board to user selected target robot and destination
	if(selBoard == 'S'){
		newBoard.displayTheBoard( theBoard);
		newBoard.makeSelect(theBoard, goalRobot, destinationLetter, letterIndex);
	}
	
	//sets board to random target robot and destination
	if(selBoard == 'R'){
		newBoard.makeRandom(theBoard, goalRobot, destinationLetter, letterIndex);
	}
    
	cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
    newBoard.displayTheBoard( theBoard);
    
    char direction; //user inputted direction
    int selRobot; //user inputted target robot
    int counter = 1; //counts number of moves
    char selRobot1; //account for program exit
    
    do{
    	cout << counter << ". Please enter the robot to move and the direction (e.g. 2 r): ";
    	cin >> selRobot1;
    	selRobot1 = toupper(selRobot1);
    	
    	//exits the program if user enters 'x'
		if(selRobot1 == 'X'){
    		cout << "exiting program.. " ;
    		break;
		}

		selRobot = selRobot1 - '0'; //changes user input into integer to be used as the robot
		
		cin >> direction;
    	cout << endl;
    	direction = toupper(direction);
    	int robotIndex = theRobots[ selRobot];
    	
    	//makes sure that user enters a correct letter
		if((direction!= 'U')&&(direction != 'L')&&(direction != 'R')&&(direction!='D')){
    		cout << "*** Error, invalid direction. Retry input." << endl << endl;
    		continue;
		}
    	
    	//moves robot up
    	if(direction == 'U'){
	    	newBoard.moveUp(theBoard, robotIndex, theRobots, selRobot, destinationLetter, goalRobot, letterIndex);
			if(newBoard.winCondition(theRobots, goalRobot, letterIndex, counter)){ //checks for a win
				break;
			}
	    }
		
		//moves robot left
		if(direction == 'L'){
			newBoard.moveLeft(theBoard, robotIndex, theRobots, selRobot, destinationLetter, goalRobot, letterIndex);
			if(newBoard.winCondition(theRobots, goalRobot, letterIndex, counter)){ //checks for a win
				break;
			}
		}
		
		//moves robot right
		if(direction == 'R'){
			newBoard.moveRight(theBoard, robotIndex, theRobots, selRobot, destinationLetter, goalRobot, letterIndex);
			if(newBoard.winCondition(theRobots, goalRobot, letterIndex, counter)){ //checks for a win
				break;
			}
		}
		
		//moves robot down
		if(direction == 'D'){
			newBoard.moveDown(theBoard, robotIndex, theRobots, selRobot, destinationLetter, goalRobot, letterIndex);
			if(newBoard.winCondition(theRobots, goalRobot, letterIndex, counter)){ //checks for a win
				break;
			}
		}
		
		counter++;
	}while(true);
    return 0;
}//end main()
