// Homework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Statistics 
{
	int min;
	int max;
	double average;
};
void H1N1();
string CensorString1(string text, string remove);
void CensorString2(string & text, string remove);
void H1N2();
Statistics GetStatistics(string filename);
void H1N3();
void CountLetters(string filename);
vector<int > IntializeAlphaCountVector();


int main()
{
	H1N1();
	H1N2();
	H1N3();
	return 0;
}

// ***** Start Homework 1 *****
// Prob 1
void H1N1()
{
	string text = "Llamas like to laugh";
	string remove = "la";
	cout << "CensorString1: " << CensorString1(text, remove) << endl;
	CensorString2(text, remove);
	cout << "CensorString2: " << text << endl;
}
string CensorString1(string text, string remove)
{
	int removeLen = remove.length();
	
	string returnText;

	for(int i = 0; i < removeLen; i++)
	{
		int textLen = text.length();

		for(int j = 0; j < textLen; j++)
		{
			if (text[j] != remove[i])
			{
				returnText += text[j];
			}
		}
		text = returnText;
		returnText.clear();
	}
	return text;
}

void CensorString2(string & text, string remove)
{
	int removeLen = remove.length();

	for(int i = 0; i < removeLen; i++)
	{
		int found = 0;
		while((found = text.find(remove[i], found)) != string::npos)
		{
			text.erase(found, 1);
		}
	}
}
// prob 2
void H1N2()
{
	Statistics stats = GetStatistics("C:\\Users\\oh245\\Documents\\Visual Studio 2012\\StafordProgrammingAbstractions\\StanfordProgrammingAbstractions\\Debug\\score.txt");
	cout << "average: " << stats.average << ", min: " << stats.min << ", max: " << stats.max << endl;
}
Statistics GetStatistics(string filename)
{
	int max = 0;
	int min = 100;
	int scoreTot = 0;
	int numScores = 0;

	ifstream infile;
	infile.open(filename.c_str());
	while(true)
	{
		string line;
		getline(infile, line);
		if(infile.fail()) 
		{
			infile.clear();
			break;
		}
		int score = stoi(line);
		if(score > max) max = score;
		if(score < min) min = score;
		scoreTot += score;
		numScores++;
	}
	Statistics stats;
	stats.average = double(scoreTot) / numScores;
	stats.max = max;
	stats.min = min;
	return stats;
}
// prob 3
void H1N3()
{
	CountLetters("C:\\Users\\oh245\\Documents\\Visual Studio 2012\\StafordProgrammingAbstractions\\StanfordProgrammingAbstractions\\Debug\\alphacount.txt");
}
void CountLetters(string filename)
{
	vector<string> outputVector;
	vector<int> alphaCountVector = IntializeAlphaCountVector();
	ifstream infile;
	infile.open(filename.c_str());
	int asciiCodeOfBigA = 65;
	int asciiCodeOfLittleA = 97;
	while(true)
	{
		string line;
		getline(infile, line);
		if(infile.fail()) 
		{
			infile.clear();
			break;
		}
		for(int i = 0; i < line.length(); i++)
		{
			if(isalpha(line[i]))
			{
				int index = int(toupper(line[i])) - asciiCodeOfBigA;
				alphaCountVector[index] += 1;
			}
		}
	}
	for(int i = 0; i < alphaCountVector.size(); i++)
		{
			cout << char(i + asciiCodeOfLittleA) << " : " << alphaCountVector[i] << endl;
		}
}
vector<int > IntializeAlphaCountVector()
{
	vector<int> alphaCountVector;
	for(int i = 0; i < 26; i++)
	{
		alphaCountVector.push_back(0);
	}
	return alphaCountVector;
}
//prob 4

// ***** End Homework 1 *****