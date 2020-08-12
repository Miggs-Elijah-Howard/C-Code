#include "Song.h"
#include <string>
#include <iostream>

Song::Song() {
	this->songName = "none";
	this->firstLine = "Empty line";
	this->timesPlayed = 0;
}

Song::Song(std::string songName, std::string firstLine) {
	this->songName = songName;
	this->firstLine = firstLine;
	this->timesPlayed = 0;
}

std::string Song::GetSongName() {
	return this->songName;
}

std::string Song::GetFirstLine() {
	return this->firstLine;
}

int Song::GetTimesPlayed() {
	return this->timesPlayed;
}

void Song::PlaySong() {
	std::cout << this->firstLine << std::endl;
	timesPlayed++;
}

void Song::PrintSongInfo() {
	std::cout << this->songName << ": \"" << this->firstLine << "\", " << this->timesPlayed << " play(s)." << std::endl;
}