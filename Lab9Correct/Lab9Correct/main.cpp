/*
Name: John Sanabria, Section 004, johnanthonysanabria@gmail.com
I clear memory for both my playlists and my songs in main. Lines 186 and 199.
Also, on line 161 I am clearing memory for my option that allows deleting of one playlist at a time.
*/
#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"

using namespace std;

const string MENU_SELECTION_ADD_LIST_OF_SONGS = "add";
const string MENU_SELECTION_PRINT_LIST_OF_SONGS = "list";
const string MENU_SELECTION_ADD_NEW_PLAYLIST = "addp";
const string MENU_SELECTION_ADD_SONG_TO_A_PLAYLIST = "addsp";
const string MENU_SELECTION_LIST_ALL_PLAYLISTS = "listp";
const string MENU_SELECTION_PLAY_A_PLAYLIST = "play";
const string MENU_SELECTION_DELETE_A_PLAYLIST = "delp";
const string MENU_SELECTION_DELETE_SONG_FROM_PLAYLIST = "delsp";
const string MENU_SELECTION_DELETE_SONG_FROM_LIBRARY = "delsl";
const string MENU_SELECTION_PRINT_MENU = "options";
const string MENU_SELECTION_EXIT_PROGRAM = "quit";

void GetLineNotWS(string& inpString)
{
	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos)
	{
		getline(cin, inpString);
	}
}

void PrintSongsLibraryWithOnlyIndex(vector <Song*> songLibrary)
{
	for (unsigned int i = 0; i < songLibrary.size(); i++)
	{
		cout << i << ": " << songLibrary.at(i)->GetSongName() << endl;
	}
}

void PrintSongsLibrary(vector <Song*> songLibrary)
{
	for (unsigned int i = 0; i < songLibrary.size(); i++)
	{
		cout << songLibrary.at(i)->GetSongName() << ": \"";
		cout << songLibrary.at(i)->GetSongFirstLine() << "\", ";
		cout << songLibrary.at(i)->GetTimesPlayed() << " play(s)." << endl;
	}
}

void PrintSongsLibraryWithIndexAndDetails(vector <Song*> songLibrary)
{
	for (unsigned int i = 0; i < songLibrary.size(); i++)
	{
		cout << i << ": " << songLibrary.at(i)->GetSongName() << ": \"";
		cout << songLibrary.at(i)->GetSongFirstLine() << "\", ";
		cout << songLibrary.at(i)->GetTimesPlayed() << " play(s)." << endl;
	}
}

void PrintPlaylistNames(vector <Playlist*> myPlaylists)
{
	for (unsigned int i = 0; i < myPlaylists.size(); i++)
	{
		cout << i << ": " << myPlaylists.at(i)->GetPlaylistName() << endl;
	}
}

void PrintMenuOptions()
{
	cout << MENU_SELECTION_ADD_LIST_OF_SONGS << "      Adds a list of songs to the library" << endl;
	cout << MENU_SELECTION_PRINT_LIST_OF_SONGS << "     Lists all the songs in the library" << endl;
	cout << MENU_SELECTION_ADD_NEW_PLAYLIST << "     Adds a new playlist" << endl;
	cout << MENU_SELECTION_ADD_SONG_TO_A_PLAYLIST << "    Adds a song to a playlist" << endl;
	cout << MENU_SELECTION_LIST_ALL_PLAYLISTS << "    Lists all the playlists" << endl;
	cout << MENU_SELECTION_PLAY_A_PLAYLIST << "     Plays a playlist" << endl;
	cout << MENU_SELECTION_DELETE_A_PLAYLIST << "     Deletes a playlist" << endl;
	cout << MENU_SELECTION_DELETE_SONG_FROM_PLAYLIST << "    Deletes a song from a playlist" << endl;
	cout << MENU_SELECTION_DELETE_SONG_FROM_LIBRARY << "    Deletes a song from the library(and all playlists)" << endl;
	cout << MENU_SELECTION_PRINT_MENU << "  Prints this options menu" << endl;
	cout << MENU_SELECTION_EXIT_PROGRAM << "     Quits the program" << endl << endl;
}

int main()
{
	string nameOfSong;
	string firstLineOfSong;
	string userChoice;
	string playlistName;
	int playlistIndex;
	int songIndex;
	vector <Song*> songLibrary;
	vector <Playlist*> myPlaylists;
	cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl << endl;

	do
	{
		cout << "Enter your selection now: " << endl;
		GetLineNotWS(userChoice);

		if (userChoice == MENU_SELECTION_ADD_LIST_OF_SONGS)
		{
			cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
			do
			{
				cout << "Song Name: " << endl;
				GetLineNotWS(nameOfSong);
				if (nameOfSong != "STOP")
				{
					cout << "Song's first line: " << endl;
					GetLineNotWS(firstLineOfSong);
					songLibrary.push_back(new Song(nameOfSong, firstLineOfSong));
				}
			} while (nameOfSong != "STOP" && firstLineOfSong != "STOP");
			cout << endl;
		}
		else if (userChoice == MENU_SELECTION_PRINT_LIST_OF_SONGS)
		{
			PrintSongsLibrary(songLibrary);
			cout << endl;
		}
		else if (userChoice == MENU_SELECTION_ADD_NEW_PLAYLIST)
		{
			cout << "Playlist name: " << endl;
			GetLineNotWS(playlistName);
			myPlaylists.push_back(new Playlist(playlistName, songLibrary));
		}
		else if (userChoice == MENU_SELECTION_ADD_SONG_TO_A_PLAYLIST)
		{
			PrintPlaylistNames(myPlaylists);
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndex;
			PrintSongsLibraryWithOnlyIndex(songLibrary);
			cout << "Pick a song index number: " << endl;
			cin >> songIndex;
			myPlaylists.at(playlistIndex)->AddSongToPlaylist(songIndex);
			cout << endl << endl;
			cin.ignore(1000, '\n');
		}
		else if (userChoice == MENU_SELECTION_LIST_ALL_PLAYLISTS)
		{
			PrintPlaylistNames(myPlaylists);
			cout << endl;
		}
		else if (userChoice == MENU_SELECTION_PLAY_A_PLAYLIST)
		{
			PrintPlaylistNames(myPlaylists);
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndex;
			cout << endl << "Playing first lines of playlist: " << myPlaylists.at(playlistIndex)->GetPlaylistName() << endl;
			myPlaylists.at(playlistIndex)->PlayThisPlaylist();
			cout << endl;
			cin.ignore(1000, '\n');
		}
		else if (userChoice == MENU_SELECTION_DELETE_A_PLAYLIST)
		{
			PrintPlaylistNames(myPlaylists);
			cout << "Pick a playlist index number to delete: " << endl;
			cin >> playlistIndex;
			delete myPlaylists.at(playlistIndex); //CLEARING MEMORY HERE
			myPlaylists.erase(myPlaylists.begin() + playlistIndex);
			cin.ignore(1000, '\n');
		}
		else if (userChoice == MENU_SELECTION_DELETE_SONG_FROM_PLAYLIST)
		{
			PrintPlaylistNames(myPlaylists);
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndex;
			myPlaylists.at(playlistIndex)->PrintSongsInPlaylist();
			cout << "Pick a song index number to delete: " << endl;
			cin >> songIndex;
			myPlaylists.at(playlistIndex)->DeleteSongFromPlaylist(songIndex);
			cin.ignore(1000, '\n');
		}
		else if (userChoice == MENU_SELECTION_DELETE_SONG_FROM_LIBRARY)
		{
			PrintSongsLibraryWithOnlyIndex(songLibrary);
			cout << "Pick a song index number: " << endl;
			cin >> songIndex;
			nameOfSong = songLibrary.at(songIndex)->GetSongName();
			for (unsigned int i = 0; i < myPlaylists.size(); i++)
			{
				myPlaylists.at(i)->EraseSongInPlaylist(nameOfSong);
			}
			delete songLibrary.at(songIndex); //CLEARING SPACE HERE
			songLibrary.erase(songLibrary.begin() + songIndex);
			cin.ignore(1000, '\n');
		}
		else if (userChoice == MENU_SELECTION_PRINT_MENU)
		{
			PrintMenuOptions();
		}
		else if (userChoice == MENU_SELECTION_EXIT_PROGRAM)
		{
			cout << "Goodbye!" << endl;
			for (unsigned int i = 0; i < songLibrary.size(); i++)
			{
				delete songLibrary.at(i); //CLEARING SPACE HERE
			}
			for (unsigned int i = 0; i < songLibrary.size(); i)
			{
				songLibrary.erase(songLibrary.begin() + i);
			}
		}
		else
		{
			PrintMenuOptions();
		}
	} while (userChoice != MENU_SELECTION_EXIT_PROGRAM);

	return 0;
}