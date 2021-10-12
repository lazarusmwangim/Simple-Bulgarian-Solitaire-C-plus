# Simple-Bulgarian-Solitaire-C-plus
	A very simple program in C++ for playing the bulgarian solitaire
1)	The main function begins by calling the WriteHeader function, which writes the header info to the screen along with any program-specific information for the user.  
2)	Declare variables, including an array for the distribution of piles, also known as the board.  Open a do-while or while loop for multiple game play.
3)	Using the CreatePiles and RandInt functions, generate a random board, or the initial random distribution of piles.  Display the initial board using PrintPiles.
4)	Ask the user for the amount of the bet and their guess for the  number of rounds it will take to resolve the Solitaire.  Call  AskBetAndGuess to do this.
5)	Call NextRound to play one round, which produces a new board.  The round includes checking if a pile has 0 cards, and if so, deleting the pile.  This is done in the RemoveZeros function. 
6)	Determine if the game is over with the FinalConfig function:  
a.	Does the board have the proper number of piles, that is, 9?
b.	Do the piles have the correct number of cards?  1-9, no duplicates
7)	Print the board.
8)	Display the results to the user and whether they have won. 
9)	Ask the user if they would like play another game? The user’s response should be either yes or no, y or n, 1 or 2, whatever.  Just be sure you tell the user what the choices are.  If the answer is yes, loop up to the CreatePile function.  Be sure to re-initialize any variables for the next game and use a ClearPile function for the array.
10)	When the user is finished, show a goodbye message to the screen.
![image](https://user-images.githubusercontent.com/56604861/136890473-d9854c52-a1ed-4955-8995-0625e5a2bd1a.png)
