#include "Song.h"

song::song()
{
}

song::song(string aname, string line)
{
	name = aname;
	firstline = line;
}

void song::setName(string aname)
{
	name = aname;
}

void song::setLine(string line)
{
	firstline = line;
}

void song::setTimesPLayed(int number)
{
	numtimesplayed = number;
}

string song::GetName()
{
	return name;
}

string song::GetLine()
{
	return firstline;
}

int song::GetNumTimesPlayed()
{
	return numtimesplayed;
}

void song::IncreaseTimesPlayed()
{
	numtimesplayed += 1;
}
