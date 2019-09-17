/*
Program #1: Toothpicks: Puzzle to equalize the number of toothpicks in three stacks.
Class: CS 141
Author: Tomas Kvapil
Lab: Tues 10am
System: DEV C++

Grading Rubric:

   50 Execution points
         5 Displays header info on screen when run
         5 Displays instructions
         5 Output is formatted as shown in sample output
         3 Handles both upper and lower case input
         5 Input can be adjacent or have spaces between them
        15 Makes moves correctly
        10 Handles the specified error conditions
         2 Gives appropriate end of program messages

   50 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
        10 Meaningful identifier names
        10 Comments: Has header.  Comments on each block of code
        10 Appropriate data and control structures
        10 Code Layout: Appropriate indentation and blank lines
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	//Header for the prject
	cout << "Program #1: Toothpicks" << endl;
	cout << "Class: CS 141" << endl;
	cout << "Author: Tomas Kvapil" << endl;
	cout << "Lab: Tues 10am" << endl;
	cout << "System: DEV C++" << endl;
	cout << endl;
	
	//Welcome block to the toothpick game
	cout << "Welcome to the Toothpick Puzzle, where the goal is to get an equal" << endl;
	cout << "number of toothpicks in each stack, in three moves." << endl;
	cout << endl;
	
	//Sample layout of Toothpick problem
	cout << "                 Stack:   A   B   C" << endl;
	cout << "  Number of Toothpicks:  11   7   6" << endl;
	cout << endl;
	
	// Instructions to the puzzle
	cout << "A move consists of moving toothpicks from one stack to a second stack," << endl;
	cout << "where the number of toothpicks moved is exactly the number that is in the" << endl;
	cout << "destination stack. In other words, to move from stack B (7 toothpicks)" << endl;
	cout << "to stack C (6) as shown above, we would move 6 from B to C, leaving us" << endl;
	cout << "with 1 in B and 12 in stack C." << endl;
	cout << endl;
	
	cout << "Here we go..." << endl;
	cout << endl;
	
	// variable initializations
	int i = 1; // 1 for first move but will go up as while loop iterates
	int stackA = 11; // starting A
	int stackB = 7; // starting B
	int stackC = 6; // starting C
	char firstLet = ' '; // used for user input character
	char secLet = ' '; // used for second user input character
	
	// while loop is set to no more than 3 because of maximum of 3 turns
	while(i <= 3){
		
		// block shows the user the current toothpick standing and is prompted to input two letters
		cout << "                Stack: " << setw(4) << " A B C \n Number of Toothpicks:" << setw(3) << stackA << " " << stackB << " " << stackC << endl;
		cout << endl;
		cout << i << ". Enter FROM and TO stack letters:";
		cin >> firstLet >> secLet;
		cout << endl;
		
		//if statement for choices of a and b
		if((firstLet == 'A' || firstLet == 'a')&&(secLet == 'B' ||secLet == 'b')){
			if(stackA > stackB){ //Prompts if move is possible
				stackA = stackA - stackB; //Cchanges stackA
				stackB = stackB * 2;// changes stack B
				i = i + 1; //moves on to the next turn
				continue;
			}
			if(stackA < stackB){ //prompts if move is not possible
				cout << "Sorry, not enough toothpicks in A. Retry..." << endl << endl;
				continue; //if statements are all similiar for all other choices
			}
		}
		
		//if statement for choices of a and c
		if((firstLet == 'A' || firstLet == 'a')&&(secLet == 'C' || secLet == 'c')){
			if(stackA > stackC){
				stackA = stackA - stackC;
				stackC = stackC * 2;
				i = i + 1;
				continue;
			}else{
				cout << "Sorry, not enough toothpicks in A. Retry..." << endl << endl;
				continue;
			}
		}
		
		//is statement for choices of b and a
		if((firstLet == 'B' || firstLet == 'b')&&(secLet == 'A' || secLet =='a')){
			if(stackB > stackA){
				stackB = stackB - stackA;
				stackA = stackA * 2;
				i = i + 1;
				continue;
			}
			else{
				cout << "Sorry, not enough toothpicks in B. Retry..." << endl << endl;
				continue;
			}
		}
		
		// if statment for choices of b and c
		if((firstLet == 'B' || firstLet == 'b')&&(secLet == 'C' || secLet == 'c')){
			if(stackB > stackC){
				stackB = stackB - stackC;
				stackC = stackC * 2;
				i = i + 1;
				continue;
			}
			else{
				cout << "Sorry, not enough toothpicks in B. Retry..." << endl << endl;
				continue;
			}
		}
		
		//if satements for choices of c and a
		if((firstLet == 'C' || firstLet == 'c')&&(secLet == 'A' || secLet == 'a')){
			if(stackC > stackA){
				stackC = stackC - stackA;
				stackA = stackA * 2;
				i = i + 1;
				continue;
			}
			else{
				cout << "Sorry, not enough toothpicks in B. Retry..." << endl << endl;
				continue;
			}
		}
		
		//if statements for choices of c and b
		if((firstLet == 'C' || firstLet == 'c')&&(secLet == 'B' || secLet == 'b')){
			if(stackC > stackB){
				stackC = stackC - stackB;
				stackB = stackB * 2;
				i = i + 1;
				continue;
			}
			else{
				cout << "Sorry, not enough toothpicks in B. Retry..." << endl << endl;
				continue;
			}
		}				
	}
	
	//
	cout << "                Stack: " << setw(4) << " A B C \n Number of Toothpicks:" << setw(3) << stackA << " " << stackB << " " << stackC << endl;	
	
	//determines if user has won or lost the game
	if((stackA == stackB)&&(stackB == stackC)){//if all stacks are equal, the user won
		cout << endl;
		cout << "Congratulations! You did it! Great Job!" << endl;
	}else{// if al stacks are not equal, the user lost
		cout << endl;
		cout << "Nope, sorry, that's not it. Try again." << endl;
	}
	
	return 0;
}
