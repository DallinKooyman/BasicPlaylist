#pragma once
#include "Song.h"

using namespace std; 

class playlist
{
public:
	playlist();
	playlist(string atitle);
	void setTitle(string atitle);
	string GetTitle();
	void AddSong(song*);
	int getSize();
	void playsongs();
	vector <song*> Returnsongs();
	void removesongfromplaylist(int songindex);



private:
	string title;
	vector <song*> songsInPLaylist;


};

