#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Song.h"
#include "Playlist.h"

using namespace std;

Playlist::Playlist(string name)
{
	this->nameOfPlaylist = name;
	this->songsInLibrary = this->songsInPlaylist;
}

Playlist::Playlist(string name, vector <Song*> userLibrary)
{
	this->nameOfPlaylist = name;
	this->songsInLibrary = userLibrary;
}

string Playlist::GetPlaylistName() const
{
	return this->nameOfPlaylist;
}

void Playlist::AddSongToPlaylist(int songIndex)
{
	songsInPlaylist.push_back(songsInLibrary.at(songIndex));
}

void Playlist::PlayThisPlaylist() const
{
	for (unsigned int i = 0; i < songsInPlaylist.size(); i++)
	{
		cout << songsInPlaylist.at(i)->GetSongFirstLine() << endl;
		songsInPlaylist.at(i)->IncrementTimesPlayed();
	}
}

void Playlist::PrintSongsInPlaylist() const
{
	for (unsigned int i = 0; i < songsInPlaylist.size(); i++)
	{
		cout << i << ": " << songsInPlaylist.at(i)->GetSongName() << endl;
	}
}

void Playlist::DeleteSongFromPlaylist(int songIndex)
{
	songsInPlaylist.erase(songsInPlaylist.begin() + songIndex);
}

void Playlist::EraseSongInPlaylist(string songName)
{
	string loopName;
	int index;
	for (unsigned int i = 0; i < songsInPlaylist.size(); i++)
	{
		loopName = songsInPlaylist.at(i)->GetSongName();
		if (loopName == songName)
		{
			index = i;
			songsInPlaylist.erase(songsInPlaylist.begin() + index);
		}
	}
}