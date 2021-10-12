#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

//declare function prototypes

void WriteHeader();
int AskBetAndGuess(int bet, int rounds);
void ClearPiles(int piles[],  int total);
int RandInt(int lowerBound, int upperBound);
int RemoveZeros(int piles[], int pTotal);
void CreatePiles(int piles[], int total);
void NextRound(int piles[], int total);
bool FinalConfig(int piles[], int total);
void PrintPiles(int piles[], int pTotal);
int currentSize = 0;
int counter=0;

#endif
