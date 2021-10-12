#include "functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

void WriteHeader()
{
    //course information
    cout << "Program 1: Solitaire \nCIS 2275: C++ Programming II"<<endl;
    cout << "Ashley Luna"<<endl;
    cout << "Email@email.email"<<endl;
    //program information
    cout << "The game begins with 45 cards that have been randomly placed into a random number of piles."<<endl;
    cout << "For each round, one card will be taken from each pile, and added into a new pile."<<endl;
    cout << "Piles with 0 cards will be removed."<<endl;
    cout << "The game will end when there are piles with 1,2,3,4,5,6,7,8, and 9 total cards in each pile, with no duplicates."<<endl;
}

int AskBetAndGuess(int* pBet, int* pGuess)
{
cout << "Please enter the amount you wish to bet:" <<endl;
cin>>*pBet;
cout << "Rounds to complete the game? :"<<endl;
cin>>*pGuess;
cout << "Let's get started! You bet $" << *pBet;
cout << " that the game will end in " << *pGuess; cout << " rounds."<<endl;
return *pGuess,*pBet;
}

void ClearPiles(int piles[],  int total)
{
    delete [] piles;
    currentSize=0;
    counter=0;
    //piles={};
}

int RandInt(int lowerBound, int upperBound)
{
//get a random number between the two bounds and return it
srand(time(0));
return rand()%(upperBound-lowerBound+1)+lowerBound;
}

int RemoveZeros(int piles[], int pTotal)
{
    for(int i=0; i<pTotal; i++)
    {
      if(piles[i]==0 && piles[pTotal-1]!=0)
      {
        piles[i] = piles[pTotal-1];
        pTotal--;
      }
      if(piles[pTotal-1]==0)
      {
        pTotal--;
        i--;
      }
    }
    return pTotal;
}

void CreatePiles(int piles[], int total)
{
    while(total > 0)
	{
		int cards = RandInt(1,45);
		if(cards > total)
		{
			cards = total;
		}
		total -= cards;
		piles[currentSize] = cards;
		currentSize++;
	}
	// A[0]=45;
   // A[1]=15;
   // A[2]=15;
   // currentSize=1;

}

bool FinalConfig(int piles[], int size)
{
    for(int i=0; i<size; i++)
    {
      for(int j=i; j<size; j++)
      {
        if(piles[j]<piles[i])
        {
          int temp = piles[i];
          piles[i] = piles[j];
          piles[j] = temp;
        }
      }
    }



    for(int i=1; i<9; i++)
    {
        bool found=false;
        for(int j=0;j<size;j++){
            if(piles[j]==i){
                found =true;
            }

        }
        if(!found){
            return false;
        }
    }

    return true;
}
void NextRound(int piles[], int currentSize){
    //Start game of removing one card from each pile
        while(true)
        {
          int newPile=0;
          for(int i=0; i<currentSize ; i++)
          {
            piles[i] = piles[i]-1; //remove one card from each pile
            newPile++;
          }

          currentSize++;
          piles[currentSize-1] = newPile; //form new pile from removed cards

          //remove any zero-ed out piles and get size of trimmed array
          currentSize = RemoveZeros(piles,currentSize);

          PrintPiles(piles, currentSize);
          counter++; //count number of solitaire steps

          //check if goal solitaire config has been reached
          if(currentSize==9)
          {
            bool done = FinalConfig(piles, currentSize);

            if(done) //exit if achieved
            {
              cout<<"***Solitaire Config Reached!!***"<<endl;
              break;
            }
           // break;
          }
        }//while loop ends
        cout<<"Final pile: ";
        PrintPiles(piles, currentSize);

}
void PrintPiles(int piles[], int pTotal)
{
    for(int i=0; i<pTotal; i++)
        cout<<piles[i]<<" ";
    cout<<endl;
}

