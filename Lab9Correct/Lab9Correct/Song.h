#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Song
{
public:
	Song(string name = "Unknown", string fLine = "Unknown", int timesPlayed = 0);
	string GetSongName() const;
	string GetSongFirstLine() const;
	int GetTimesPlayed() const;
	void IncrementTimesPlayed();
private:
	string songName;
	string firstLine;
	int timesSongHasBeenPlayed;
};