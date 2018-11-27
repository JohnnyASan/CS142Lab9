#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Song.h"

using namespace std;

Song::Song(string name, string fLine, int timesPlayed)
{
	this->songName = name;
	this->firstLine = fLine;
	this->timesSongHasBeenPlayed = timesPlayed;
}

string Song::GetSongName() const
{
	return this->songName;
}

string Song::GetSongFirstLine() const
{
	return this->firstLine;
}

int Song::GetTimesPlayed() const
{
	return this->timesSongHasBeenPlayed;
}

void Song::IncrementTimesPlayed()
{
	this->timesSongHasBeenPlayed++;
}
