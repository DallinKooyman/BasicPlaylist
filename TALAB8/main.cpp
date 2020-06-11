#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Song.h"
#include "Playlist.h"

using namespace std;


void printMenu() 
{
	cout << "add" << "\t" << "Adds a list of songs to the library" << endl;
	cout << "list" << "\t" << "Lists all the songs in the library" << endl;
	cout << "addp" << "\t" << "Adds a new playlist" << endl;
	cout << "addsp" << "\t" << "Adds a song to a playlist" << endl;
	cout << "listp" << "\t" << "Lists all the playlists" << endl;
	cout << "play" << "\t" << "Plays a playlist" << endl;
	cout << "remp" << "\t" << "Removes a playlist" << endl;
	cout << "remsp" << "\t" << "Removes a song from a playlist" << endl;
	cout << "remsl" << "\t" << "Removes a song from the library (and all playlists)" << endl;
	cout << "options" << "\t" << "Prints this options menu" << endl;
	cout << "quit" << "\t" << "Quits the program" << endl;
	return;
}

void addSong(vector<song*>& thelist) 
{
	
	string thename;
	string line;
	cout << "Enter songs' names and first lines (type \"DONE\" when done):" << endl;
	cout << "Song Name: ";
	getline(cin, thename);
	while (thename != "DONE") 
	{
		cout << "Song's first line: ";
		getline(cin, line);
		song *myPointer = new song(thename, line);
		thelist.push_back(myPointer);
		cout << "Song Name: ";
		getline(cin, thename);
	}
}

void listSongs(vector<song*>& thelist) 
{
	for (unsigned int i = 0; i < thelist.size(); ++i)
	{
		cout << thelist.at(i)->GetName() << ": \"" << thelist.at(i)->GetLine() << "\", " 
			<< thelist.at(i)->GetNumTimesPlayed() << " play(s)." << endl;
	}
}

void addplaylist(vector<playlist>& jamminplaylists)
{
	string playlistname;
	cout << "Playlist name: ";
	getline(cin, playlistname);
	new playlist(playlistname);
	jamminplaylists.push_back(playlistname);
}

void liststuff(vector<playlist>& jamminplaylists)
{
	for (unsigned int i = 0; i < jamminplaylists.size(); ++i) 
	{
		cout << "\t" << i << ": " << jamminplaylists.at(i).GetTitle() << endl;
	}
}

void chooseSongList(vector<song*>& songlist)
{
	for (unsigned int i = 0; i < songlist.size(); ++i)
	{
		cout << "\t" << i << ": " << songlist.at(i)->GetName() << endl;
	}
}

void playsongs(vector<playlist>& jamminplaylists, int playlistNum) 
{
	cout << "Playing songs from playlist: " << jamminplaylists.at(playlistNum).GetTitle() << endl;
	jamminplaylists.at(playlistNum).playsongs();
}


void chooseSongfromVector(vector<song*> playlistsonglist) 
{
	for (unsigned int i = 0; i < playlistsonglist.size(); ++i)
	{
		cout << "\t" << i << ": " << playlistsonglist.at(i)->GetName() << endl;
	}
}


int main() 
{

	string userMenuChoice;
	bool playlistOrNot = true;
	vector<song*> songlist;
	vector<playlist> jamminplaylists;
	int playlistNum;
	int songNum;

	song* tmp = nullptr;


	cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl << endl;
	cout << "Enter your selection now: ";
	cin >> userMenuChoice;
	cin.ignore();
	cout << endl;

	while (userMenuChoice != "quit") 
	{
		if (userMenuChoice == "add") 
		{
			addSong(songlist);
		}

		else if (userMenuChoice == "list")
		{
			listSongs(songlist);
		}

		else if (userMenuChoice == "addp")
		{
			addplaylist(jamminplaylists);
		}

		else if (userMenuChoice == "listp")
		{
			liststuff(jamminplaylists);
		}

		else if (userMenuChoice == "addsp")
		{
			liststuff(jamminplaylists);
			cout << "Pick a playlist index number: ";
			cin >> playlistNum;
			cin.ignore();
			chooseSongList(songlist);
			cout << "Pick a song index number : ";
			cin >> songNum;
			cin.ignore();
			jamminplaylists.at(playlistNum).AddSong(songlist.at(songNum));
		}

		else if (userMenuChoice == "play")
		{
			liststuff(jamminplaylists);
			cout << "Pick a playlist index number: ";
			cin >> playlistNum;
			cin.ignore();
			cout << endl;
			playsongs(jamminplaylists, playlistNum);
		}

		else if (userMenuChoice == "remp")
		{
			liststuff(jamminplaylists);
			cout << "Pick a playlist index number to remove: ";
			cin >> playlistNum;
			cin.ignore();
			jamminplaylists.erase(jamminplaylists.begin() + playlistNum);
		}

		else if (userMenuChoice == "remsp")
		{
			liststuff(jamminplaylists);
			cout << "Pick a playlist index number: ";
			cin >> playlistNum;
			cin.ignore();
			chooseSongfromVector(jamminplaylists.at(playlistNum).Returnsongs());
			cout << "Pick a song index number to remove: ";
			cin >> songNum;
			cin.ignore();
			jamminplaylists.at(playlistNum).removesongfromplaylist(songNum);
		}

		else if (userMenuChoice == "remsl")
		{
			chooseSongList(songlist);
			cout << "Pick a song index number to remove: ";
			cin >> songNum;
			cin.ignore();
			string removesongname = songlist.at(songNum)->GetName();
			for (unsigned int i = 0; i < jamminplaylists.size(); ++i)
			{
				for (int j = 0; j < jamminplaylists.at(i).getSize(); ++j)
				{
					if (jamminplaylists.at(i).Returnsongs().at(j)->GetName() == removesongname)
					{
						jamminplaylists.at(i).removesongfromplaylist(j);
					}
				}
			}

			tmp = songlist.at(songNum);
			delete tmp;
			songlist.erase(songlist.begin() + songNum);
		}

		else 
		{
			printMenu();
		}
		cout << endl;
		cout << "Enter your selection now: ";
		cin >> userMenuChoice;
		cin.ignore();
		cout << endl;
	}
	cout << "Goodbye!" << endl;

	while (songlist.size() > 0) 
	{
		tmp = songlist.at(songlist.size() - 1);
		delete tmp;
		songlist.erase(songlist.begin() + songlist.size() - 1);
	}

	return 0;
} 