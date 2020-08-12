#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <vector>

class Playlist {
private:
	std::string playlistName;
	std::vector<Song*> playlist;
public:
	//constructor(s)
	Playlist(std::string playlistName); //default constructor
	//functions
	void AddSong(Song* newSong);
	void RemoveSong(int index);

	std::string GetPlaylistName();
	void SetPlaylistName(std::string name);

	void PrintSongLines();
	std::vector<Song*> GetPlaylist();
};

#endif
