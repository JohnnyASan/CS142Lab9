#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Playlist
{
public:
	Playlist(string name = "unknown");
	Playlist(string name, vector <Song*> userLibrary);
	string GetPlaylistName() const;
	void PlayThisPlaylist() const;
	void PrintSongsInPlaylist() const;
	void AddSongToPlaylist(int songIndex);
	void DeleteSongFromPlaylist(int songIndex);
	void EraseSongInPlaylist(string songName);
private:
	string nameOfPlaylist;
	vector <Song*> songsInLibrary;
	vector <Song*> songsInPlaylist;
};