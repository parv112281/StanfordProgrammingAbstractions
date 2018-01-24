// Assignments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "VotingSimulation.cpp"

using namespace std;

// ***** Assignment 1 *****
void A1N1();
bool IsPerfect(int number);

int main()
{
	A1N1();
	return 0;
}

// ***** Start Assignment 1 *****
// prob 1
void A1N1()
{
	for(int i = 1; i < 10000; i++)
	{
		if(IsPerfect(i))
		{
			cout << i << " is a perfect number." << endl;
		}
	}
}
bool IsPerfect(int number)
{
	bool result = false;
	int divisorSum = 1;

	for(int i = 2; i <= number / 2; i++)
	{
		if(number % i == 0) 
			divisorSum += i; 
	}

	if (divisorSum == number ) 
		result = true;

	return result;
}
// prob 2

// ***** End Assignment 1 *****