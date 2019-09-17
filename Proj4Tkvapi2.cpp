/* ------------------------------------------------
   tkvapi2Prog4.cpp
 
   Program #4: Twisted Hangman
               Program delays choosing which word is chosen,
               making the game as difficult as possible.
   Class: CS 141
   Author: Tomas Kvapil
   Lab: Tues 10am
   System:  DEV C++

   Grading Rubric:

   50 Execution points
         2 Displays header info and instructions on screen when run
         5 Correctly counts and displays the number of initial dictionary words, for any dictionary
        10 Correctly extracts words of the selected length and displays count for those words, < 5 seconds
         3 Move number is displayed and updates correctly.  Move number starts at 15.
         2 Handles upper and lower-case user input for the letters that are guessed
         3 Displays letters guessed so far, in alphabetical order
        10 Updates number of words left after each guess
         5 Input of '~' displays all possible words remaining
        10 Correctly displays letters once all words remaining have that letter, eliminating non-match words
         5 Displays appropriate message when word is guessed, or when it is not guessed and guesses run out
   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
        10 Meaningful identifier names
        10 Comments: Has header and this rubric.  Has comments on each block of code
        10 Appropriate data and control structures 
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/
#include <iostream>
#include <fstream> //for file input
#include <string> //for string functions
#include <vector> // for use of vectors
#include <algorithm> //transorm to upper
using namespace std;

//--------------------------------------------------------------------
// Display ID info
void displayHeaderInfo()
{
    cout << "Author:  Tomas Kvapil          \n"
         << "Class:   CS 141, Spring 2018  \n"
         << "Lab:     Tues 10am            \n"
         << "Program: #4, Twisted Hangman    \n"
         << endl;

    cout << "Welcome to Twisted Hangman! \n"
         << "\n"
         << "You have a total of fifteen tries to try and   \n"
         << "guess the word that the computer is thinking.  \n"
         << "If you guess a correct letter, the letter will \n"
         << "be displayed. Find all the correct letters     \n"
         << "and you shall be declared the winner.          \n"
         << "GOOD LUCK!                                     \n"
         << endl;
}//end displayHeaderInfo()


//---------------------------------------------------------------------------------------------------------------------------------------
//makes sure that there are no ' and no blank spaces in any of the words
void convertFileToVector(vector<string> &words, ifstream &fileName, string line)
{
		while(getline(fileName, line)){
		if(line.length()!=0){ //makes sure there are no blank spaces
			if(line.find_first_of("\'") == -1){ //makes sure there are no ' in the words
				words.push_back(line);
			}
		}
	}
}//end convertFileToVector()


//---------------------------------------------------------------------------------------------------------------------------------------
//makes all letters of all words uppercase
void upperCase(vector<string> &words)
{
	for(int i = 0; i<words.size();i++){
		transform(words[i].begin(), words[i].end(), words[i].begin(),::toupper); 
	}
}//end upperCase()


//---------------------------------------------------------------------------------------------------------------------------------------
//copies all of the words of user length to a new vector
void sameSizeWords(vector<string> &originalWords, vector<string> &templateWords, int userLength)
{
	for(int i=0; i<originalWords.size();i++){
		if(originalWords.at(i).length()==userLength){
			templateWords.push_back(originalWords.at(i)); 
		}
	}
}// end sameSizeWords()


//---------------------------------------------------------------------------------------------------------------------------------------
//initializes lettersFound[] to [_,_,_,_] of user length
void initializeFound(char lettersFound[], int size)
{
	for(int i=0; i<size; i++){
		lettersFound[i] = '_';
	}
}//end initializeFound()


//---------------------------------------------------------------------------------------------------------------------------------------
//initalizes lettersUsed[15] to ['','','','','','','','','','','','','','',''] 
void initializeUsed(char lettersUsed[])
{
	for(int i = 0; i<15;i++){
		lettersUsed[i]=' ';
	}
}//end initializeUsed()


//---------------------------------------------------------------------------------------------------------------------------------------
//displays are elements of lettersFound[]
void lettersFoundDisplay(char lettersFound[],int size)
{
	cout << endl << "Letters found: ";
	for(int i=0; i<size; i++){
		cout << lettersFound[i] << " ";
	}
	cout << endl;
}//end lettersFoundDisplay()


//---------------------------------------------------------------------------------------------------------------------------------------
//displays the whole word that the user found
void lettersFoundDisplayForWinner(char lettersFound[],int size)
{
	for(int i=0; i<size; i++){
		cout << lettersFound[i] << " ";
	}
	cout << endl;
}//end lettersFoundDisplayForWinner()


//---------------------------------------------------------------------------------------------------------------------------------------
//sorts lettersUsed in alphabetical order so the user sees what they've already guessed
void sortLettersUsed(char lettersUsed[])
{
	int counter = 0;
	for(int i =0; i<15; i++){
		if(lettersUsed[i] >'@'){ //only searches for letters
			counter ++;
		}
	}	
	sort(lettersUsed, lettersUsed+counter);
}//end sortLettersUsed()


//---------------------------------------------------------------------------------------------------------------------------------------
//displays all the letters in lettersUsed making sure not to display ' ' as it was initialized
void lettersUsedDisplay(char lettersUsed[], int countTurn)
{
	cout << countTurn << ". Letters used so far: ";
	for(int i = 0; i<15; i++){
		if(lettersUsed[i] != 32){
			cout << lettersUsed[i] << " ";
		}
	}
}//end lettersUsedDisplay()


//---------------------------------------------------------------------------------------------------------------------------------------
//Sorts and and displays the letters that the user guessed
void displayLettersUsed(char lettersUsed[], char& userLetter, int &countTurn) 
{ 
	userLetter = toupper(userLetter);
		
	lettersUsed[15-countTurn] = userLetter; //adds the guessed letter to the next empty space
		
	sortLettersUsed(lettersUsed); //sorts letters
}//end displayLettersUsed()


//---------------------------------------------------------------------------------------------------------------------------------------
//clears a vector according to which one's turn it is in the ping pong
void clearVectors(vector<string> &wordsOne, vector<string> &wordsTwo, int &countTurn)
{
	if(countTurn % 2 != 0 ){wordsOne.clear();}
	if(countTurn % 2 == 0){wordsTwo.clear();}
	
}//end clearVectors()


//---------------------------------------------------------------------------------------------------------------------------------------
//removes all the words that contain the letter chosen by the user
void removeWords(vector<string> &wordsOne, vector<string> &wordsTwo, char userLetter, int &countTurn)
{
		
	if(countTurn % 2 != 0 ){ //makes sure using correct vector in ping pong
		
		for(int i = 0; i<wordsTwo.size(); i++ ){ //iterates words
			for(int j = 0; j <= wordsTwo[i].length();j++){ //iterates letters within word
				
				if(j==wordsTwo.at(i).length()){ //adds word to vector if letter was not found in word and continues to next word
					wordsOne.push_back(wordsTwo.at(i));
					break;
				}
				
				if(wordsTwo[i][j] != userLetter){ //continues to the next letter index if letter is not found at index
					continue;
				}
				
				if(wordsTwo[i][j] == userLetter){ //breaks and iterates through next word
					break;
				}
			}
		}
	}
	
	
	if(countTurn % 2 == 0 ){ //makes sure using correct vector in ping pong
	
		for(int i = 0; i<wordsOne.size(); i++ ){ //iterates words
			for(int j = 0; j <= wordsOne[i].length();j++){ //iterates letters within word
				
				if(j==wordsOne.at(i).length()){ //adds word to vector if letter was not found in word and continues to next word
					wordsTwo.push_back(wordsOne.at(i));
					break;
				}
				
				if(wordsOne[i][j] != userLetter){ //continues to the next letter index if letter is not found at index
					continue;
				}
				
				if(wordsOne[i][j] == userLetter){ //breaks and iterates through next word
					break;
				}
			}
		}
	}
}//end removeWords()


//---------------------------------------------------------------------------------------------------------------------------------------
//checks if remaing words all share the user letter inputted
bool checkWordsForLetter(vector<string> &wordsOne, vector<string> &wordsTwo, char &userLetter,int &countTurn)
{
	//counts used depending on ping pong
	int count1 = 0;
	int count2 = 0;
	
	if(countTurn%2 == 0){ //makes sure using correct vector in ping pong
	
		for(int i = 0; i<wordsOne.size(); i++){ //iterates words
			for(int j = 0; j <wordsOne[i].length(); j++){ //iterates through letters in word
				
				if(wordsOne[i][j]==userLetter){ //counts if there is one occurrence of letter
					count1++;
					break;
				}
			}
		}
	}
	
	
	if(countTurn%2 != 0){ //makes sure using correct vector in ping pong
	
		for(int i = 0; i<wordsTwo.size(); i++){ //iterates words
			for(int j = 0; j <wordsTwo[i].length(); j++){ //iterates through letters in word
				
				if(wordsTwo[i][j]==userLetter){ //counts if there is one occurrence of letter
					count2++;
					break;
				}
			}
		}
	}
	
	
	if(count1 == wordsOne.size()){ //true if all words contain letter
		return true;
	}
	
	if(count2 == wordsTwo.size()){ //true if all words contain letter
		return true;
	}
	
	return false;
}//end checkWordsForLetter()


//---------------------------------------------------------------------------------------------------------------------------------------
// displays the size of the correct vector in the ping pong
void displayCurrentLength(vector<string> &wordsOne, vector<string> &wordsTwo, int &countTurn)
{
	if(countTurn%2 != 0){cout << "Now we have " << wordsOne.size() << " words." << endl;} 
	if(countTurn%2 == 0){cout << "Now we have " << wordsTwo.size() << " words." << endl;}
	cout << endl;
}//end displayCurrentLength()


//---------------------------------------------------------------------------------------------------------------------------------------
//displays all contents of the current vector in use
void displayCurrentWords(vector<string> &wordsOne, vector<string> &wordsTwo, int &countTurn)
{
	if(countTurn%2 != 0){ //makes sure using correct vector in ping pong
	
		for(int i = 0; i<wordsTwo.size(); i++){ 
			cout << wordsTwo.at(i) << " ";
		}
	}
	
	if(countTurn%2 == 0){ //makes sure using correct vector in ping pong
	
		for(int i=0;i<wordsOne.size();i++){
			cout << wordsOne.at(i) << " ";
		}
	}
	
	cout << endl << endl;
}//end displayCurrentWords()


//---------------------------------------------------------------------------------------------------------------------------------------
//checks if winning conditions are met
bool weHaveaWinner(vector<string> &wordsOne, vector<string> &wordsTwo, char lettersFound[], int &countTurn)
{
	//counts used depending on ping pong
	int counter1 = 0;
	int counter2 = 0;
	
	if(countTurn%2 == 0){ //makes sure using correct vector in ping pong
	
		for(int i = 0; i < wordsOne.at(0).length(); i++){ //counts how many letters match
			if(lettersFound[i] == wordsOne[0][i]){
				counter1++;
			}
		}
	}
	
	if(countTurn%2 != 0){ //makes sure using correct vector in ping pong
	
		for(int i = 0; i < wordsTwo.at(0).length(); i++){ //counts how many letters match
			if(lettersFound[i] == wordsTwo[0][i]){
				counter2++;
			}
		}
	}
	
	if(counter1 == wordsOne.at(0).length()){ //if letters match word, returns true
		return true;
	}
	
	if(counter2 == wordsTwo.at(0).length()){ //if letters match word, returns true
		return true;
	}
	
	return false;		
}//end weHaveaWinner()


//---------------------------------------------------------------------------------------------------------------------------------------
//checks if the user letter is the only occurence
bool onlyLetterInWord(string currentWord, char userLetter)
{
	int counter = 0;

	for(int i = 0; i<currentWord.length(); i++){ //counts occurences
		if(currentWord[i]==userLetter){
			counter++;
		}
	}
	
	if(counter > 1){ //makes sure only one occurence
		return false;
	}
	
	return true;	
}//end onlyLetterInWord()


//---------------------------------------------------------------------------------------------------------------------------------------
//makes letter found and deletes words that do not contain user letter in position of vector[0]
void makeLetterFound(vector<string> &wordsOne, vector<string> &wordsTwo, char lettersFound[], char &userLetter, int &countTurn)
{
	
	if(countTurn%2 == 0){ //makes sure using correct vector in ping pong
		
		for(int i=0; i<wordsOne.at(0).length(); i++){ //iterates letters for first word
		
			if(wordsOne[0][i]==userLetter){ 
				lettersFound[i] = wordsOne[0][i]; //adds letter to lettersFound array
			}
		}
		
		for(int i=0;i<wordsOne.at(0).length();i++){ //iterates through letters
			
			if(lettersFound[i]==userLetter){ //checks if letter index matches user letter
				
				for(int j =0; j<wordsOne.size();j++){ //iterates through letters that contain the correct location of user letter
					
					if(wordsOne[j][i]==userLetter){ //checks if exact index matches lettersFound
						
						if(wordsOne[j]==wordsOne[0]){ //continues so that first word is alway copied
							wordsTwo.push_back(wordsOne[j]);
							continue;
						}
						
						if(onlyLetterInWord(wordsOne[j], userLetter)){ //checks if it is the only letter that match and copies to vector
							wordsTwo.push_back(wordsOne[j]);
						}
					}
				}
				break; //breaks so words are not reapeated
			}
		}
		
		if(weHaveaWinner(wordsOne, wordsTwo, lettersFound, countTurn)){ //checks for winning condition
			cout << "Now we have 0 words." << endl;
		}else{
			cout << "Now we have " << wordsTwo.size() << " Words." << endl << endl;
		}
	}
	
	
	if(countTurn%2 != 0){ //makes sure using correct vector in ping pong
	
		for(int i=0; i<wordsTwo.at(0).length(); i++){ //iterates letters for first word
		
			if(wordsTwo[0][i]==userLetter){
				lettersFound[i] = wordsTwo[0][i]; //adds letter to lettersFound array
			}
		}
		
		for(int i=0;i<wordsTwo.at(0).length();i++){ //iterates through letters
			
			if(lettersFound[i]==userLetter){ //checks if letter index matches user letter
				
				for(int j =0; j<wordsTwo.size();j++){ //iterates through letters that contain the correct location of user letter
					
					if(wordsTwo[j][i]==userLetter){ //checks if exact index matches lettersFound
						
						if(wordsTwo[j]==wordsTwo[0]){ //continues so that first word is alway copied
							wordsOne.push_back(wordsTwo[j]);
							continue;
						}
						
						if(onlyLetterInWord(wordsTwo[j], userLetter)){ //checks if it is the only letter that match and copies to vector
						wordsOne.push_back(wordsTwo.at(j));
						}
					}
				}
				break; //breaks so words are not reapeated
			}
		}

		if(weHaveaWinner(wordsOne, wordsTwo, lettersFound, countTurn)){ //checks for winning condition
			cout << "Now we have 0 words." << endl;
		}else{
			cout << "Now we have " << wordsOne.size() <<" Words." << endl << endl;
		}
	}
}//end makeLetterFound()


//---------------------------------------------------------------------------------------------------------------------------------------
//puts everything together
int main()
{
	ifstream allWords; //file reading
	allWords.open("dictionary.txt"); //opens file
	
	vector<string> wordsOne;
	vector<string> wordsTwo; //used for ping ponging

	char lettersUsed[15]; //there can only be 15 turns so max 15 letter guesses
	string line; //reading lines
	int userLength; //user input
	char userLetter; //user input
	int countTurn = 15; //keeps track of turn 
	
	initializeUsed(lettersUsed);//['','','','',''] for 15 spaces
	
	displayHeaderInfo(); //displays header
	convertFileToVector(wordsOne, allWords, line); //function for vector conversion from file of lines
	upperCase(wordsOne); //uppercases contents
	
	cout << "Starting with " << wordsOne.size() << " Words." << endl;
	cout << "What length word do you want? ";
	cin >> userLength; //prompts for length
	
	char lettersFound[userLength]; //initialize the correct size of array
	initializeFound(lettersFound, userLength); //[_,_,_,_,_]
	
	sameSizeWords(wordsOne, wordsTwo, userLength); //function makes wordsTwo contain all words with user length
	cout << "Now we have " << wordsTwo.size() << " words of length " << userLength << endl << endl;

	
	do{
		//displays headers
		lettersUsedDisplay(lettersUsed, countTurn); 
		lettersFoundDisplay(lettersFound, userLength);
		
		cout << "Guess a letter: ";
		cin >> userLetter; //prompts for letter
		
		//checks if user inpts '~'
		if(userLetter == '~'){
			displayCurrentWords(wordsOne, wordsTwo, countTurn);
			continue;
		}else{
			displayLettersUsed(lettersUsed, userLetter, countTurn);
		}
		
		//checks if user letters can or cannot be deleted
		if(checkWordsForLetter(wordsOne, wordsTwo, userLetter, countTurn)){
			
			clearVectors(wordsOne, wordsTwo, countTurn);
			cout << "You found letter " << userLetter << endl;
			makeLetterFound(wordsOne, wordsTwo, lettersFound, userLetter, countTurn);
			
			//checks for winning condtions
			if(weHaveaWinner(wordsOne, wordsTwo, lettersFound, countTurn)){
				lettersFoundDisplayForWinner(lettersFound,userLength);
				cout << "*** Congratulations, you did it! ***" << endl << endl;
				break;
			}
			
			//subracts a turn
			countTurn--;
			continue;
		}
		
		clearVectors(wordsOne, wordsTwo, countTurn); //empties vector for copying use
		
		removeWords(wordsOne, wordsTwo, userLetter, countTurn); //removes words that contain user letter
		
		displayCurrentLength(wordsOne, wordsTwo, countTurn); //shows amount of words remaining

		countTurn--; //subtracts a turn
		
	}while(countTurn>0);
	
	//losing statements
	if(!(weHaveaWinner(wordsOne, wordsTwo, lettersFound, countTurn))){
		cout << "Nice try, but you failed to find the word. Better luck next time!" << endl << endl;
	}
	
	cout << "Done." << endl;
	
	allWords.close(); //closes file
	return 0;
}//end main()
