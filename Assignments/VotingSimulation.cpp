#include <iostream>
using namespace std;

struct Parameters
{
	int numVoters;
	double percentageSpread;
	double votingError;
	double invalidChance;
};

const int NUMTRIALS = 500;

void SimulationUI()
{
	// Fetch simulation parameter from the user
	Parameters params = FetchParameters();
	// Perform the 500 trials
	PerformTrials(params);
	// Output result of Simulation
	cout << "Chance of an invalid election result after 500 trials = " << params.invalidChance;
}
Parameters FetchParameters()
{
	Parameters params;
	params.numVoters = -1;
	params.invalidChance = -1;
	params.percentageSpread = -1;
	params.votingError = -1;
	// ask for #of voters
	while(params.numVoters < 0)
	{
		cout << "Enter number of voters: ";
		cin >> params.numVoters;
	}
	// ask for percentage spread between candidates
	while(params.percentageSpread < 0 || params.percentageSpread > 1)
	{
		cout << "Enter percentage spread between candidates: ";
		cin >> params.numVoters;
	}
	// ask for voting error percentage
	while(params.votingError < 0 || params.votingError > 1)
	{
		cout << "Enter voting error percentage: ";
		cin >> params.numVoters;
	}
	return params;
}
void PerformTrials(Parameters &params)
{
	for(int i = 0; i < NUMTRIALS; i++)
	{

	}
}
double PerformTrials(double candidateChance, double votingError)
{
	// for each voter, generate a random real number betwee 0 and 100
	
	// if the random number is in the range 0 to (50 + spread/2) then select
	// candidate 1, otherwise select candidate 2

	// generate another random real and if it is in range 0 to votingError
	// then flip vote from current candidate to other candidate and increment 
	// errors

	// divide errors by numVoters to calculate invlaidChance
}