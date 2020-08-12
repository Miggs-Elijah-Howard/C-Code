#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
private:
	std::string songName;
	std::string firstLine;
	int timesPlayed;
	
public:
	Song();
	Song(std::string songName, std::string firstLine);

	std::string GetSongName();
	std::string GetFirstLine();
	int GetTimesPlayed();
	void PlaySong();
	void PrintSongInfo();
	
};

#endif
