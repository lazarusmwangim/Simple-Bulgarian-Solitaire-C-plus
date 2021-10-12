#include "functions.cpp"

//driver code
void showChoices()
{
	cout << "1: Yes " << endl;
	cout << "2: No" << endl;
	cout << "3: Exit " << endl;
	cout << "Would you like to play the game? ";
}
int main()
{
    WriteHeader();
    int choice,amt,rnds;
	do
	{
	    int *A=new int[45];
	    int total=45;
		showChoices();
		cin >> choice;
		switch (choice)
		{
		case 1:
		    CreatePiles(A,total);
		    cout<<"The board is: ";
		    PrintPiles(A,currentSize);
            AskBetAndGuess(&amt,&rnds);
		    NextRound(A,currentSize);

		    cout<<"Bulgarian soliatire rounds taken: "<<counter<<endl;
		    if(rnds==counter)
                cout<<"Congratulations! You won."<<endl;
            else
                cout<<"Oops! You lost. Having placed "<<rnds<<" rounds."<<endl;

		    ClearPiles(A,total);
			break;
		case 2:
			cout << "Thank you for trying our game. Good bye! Enter 3 to exit"<<endl;
			break;
		case 3:
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}while (choice != 3);

    return 0;
}
