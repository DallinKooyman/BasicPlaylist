#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class song
{
public:
	song();
	song(string aname, string line);
	void setName(string aname);
	void setLine(string line);
	void setTimesPLayed(int number);
	string GetName();
	string GetLine();
	int GetNumTimesPlayed();
	void IncreaseTimesPlayed();





private:
	string name;
	string firstline;
	int numtimesplayed;
};

