#pragma once
//Include statements
#include <iostream>
#include <vector>
#include <fstream>

class TestScores
{
	std::vector<size_t> scoreVector; //Vector that stores scores

public:
	void addScore(size_t*); //Pushes score into vector
	void sortVector(); //Sorts vector with ascending values
	void computeAverage(); //Calculates average
	void displayData(); //Prints vector

};
