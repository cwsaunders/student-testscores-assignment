//Include statements
#include "TestScores.h"
#include <iostream>
#include <fstream>

using namespace std;


void TestScores::addScore(size_t* score) //Adds scores to vector
{
	scoreVector.push_back (*score);
}
void TestScores::sortVector() //Sorts vector in ascending order
{
	if (scoreVector.empty())
		cout << "Error! No scores have been entered!" << endl; //Error message
	if (!scoreVector.empty())
	{
		for (size_t i = 0; i < scoreVector.size() - 1; ++i)
		{
			size_t smallVal = i;
			for (size_t index = i + 1; index < scoreVector.size(); ++index)
			{
				if (scoreVector[index] < scoreVector[smallVal])
				{
					smallVal = index;
				}
			}
			size_t hold = scoreVector[i];
			scoreVector[i] = scoreVector[smallVal];
			scoreVector[smallVal] = hold;
		}
	}
}
void TestScores::computeAverage() //Calculates average of vector scores
{
	if (!scoreVector.empty())
	{
		size_t total = 0;
		for (size_t i = 0; i < scoreVector.size(); ++i)
		{
			total += scoreVector[i];
		}
		if (total > 0)
			cout << total / scoreVector.size() << endl;
		else
			cout << "Average is 0!" << endl;
	}
	else
		cout << "Error. No scores entered." << endl; //Error message
}
void TestScores::displayData() //Displays vector data
{
	if (!scoreVector.empty())
	{
		for (size_t i = 0; i < scoreVector.size(); ++i)
		{
			cout << scoreVector[i] << endl;
		}
	}
	else
		cout << "No scores have been entered!" << endl; //Error message
}