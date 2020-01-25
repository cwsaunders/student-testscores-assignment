//<CSIS 112 Lab 4 Christian Saunders> -- This program manipulates a vector. The vector is sorted, added to, and displayed as a means to view
//scores.
//CSIS 112-<002>
//<C++ How To Program>,<https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/io/readtextfile.html>
//<http://www.cplusplus.com/reference/vector/vector/push_back/>,<http://www.cplusplus.com/reference/vector/vector/empty/>

//Include statements
#include <iostream>
#include <string>
#include <fstream>
#include "TestScores.h"

using namespace std;

int main()
{
	cout << "Christian Saunders -- Lab 4" << endl << endl;
	//Variable declarations

	TestScores t; //Class variable
	char menu='z'; //Menu user input
	string fileName; //Asks for file name
	ifstream inFile; //File in
	size_t keyboardInput; //For inputting scores via cin
	

	//Program logic

	while (menu != 'Q'&&menu!='q')
	{
		cout << "Menu" << endl << endl;
		cout << "1. Enter R to read scores from file" << endl; //Prompt
		cout << "2. Enter S to enter a score from keyboard" << endl; //Prompt
		cout << "3. Enter C to Sort scores" << endl; //Prompt
		cout << "4. Enter P to compute average score" << endl; //Prompt
		cout << "5. Enter L to print scores to screen" << endl; //Prompt
		cout << "6. Enter Q to quit" << endl; //Prompt
		cin >> menu;
		switch (menu)
		{
		case'r':
		case 'R':
			size_t transferValue;
			cout << "Enter filename: " << endl; //Prompt
			cin >> fileName;
			inFile.open(fileName.c_str());
			while (!inFile)
			{
				cout << "Error! No such file exists" << endl; //Error message
				break;
			}
			while (inFile >> transferValue)
			{
				t.addScore(&transferValue);
			}
			

			inFile.close();
			break;
		case's':
		case'S':
			cout << "Enter student score: " << endl; //Prompt
			cin >> keyboardInput;
			if (cin.fail() || keyboardInput < 0 || keyboardInput>100)
			{
				cout << "Input must be a positive real number less than 100" << endl; //Error message
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> keyboardInput;
			}
			
			t.addScore(&keyboardInput);
			break;
		case'c':
		case'C':
			t.sortVector();

			break;
		
		case'p':
		case'P':
			t.computeAverage();

			break;
		
		case'l':
		case'L':
			t.displayData();
			break;
		case'Q':
			
			break;
		case'q':
			
			break;
		default:
			cout << "Error. You must enter either R,S,C,P,L, or Q." << endl; //Error message
			break;
		}

	}

	//Closing program statements
	
	return 0;
}