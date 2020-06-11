#include "Playlist.h"

playlist::playlist()
{
}

playlist::playlist(string atitle)
{
	title = atitle;
}

void playlist::setTitle(string atitle)
{
	title = atitle;
}

string playlist::GetTitle()
{
	return title;
}

void playlist::AddSong(song* thepointer)
{
	songsInPLaylist.push_back(thepointer);
}

int playlist::getSize()
{
	return songsInPLaylist.size();
}

void playlist::playsongs()
{
	for (int i = 0; i < songsInPLaylist.size(); ++i)
	{
		cout << songsInPLaylist.at(i)->GetLine() << endl;
		songsInPLaylist.at(i)->IncreaseTimesPlayed();
	}
}

vector<song*> playlist::Returnsongs()
{
	return songsInPLaylist;
}

void playlist::removesongfromplaylist(int songindex)
{
	songsInPLaylist.erase(songsInPLaylist.begin() + songindex);
}
