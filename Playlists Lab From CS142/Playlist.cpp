#include "Song.h"
#include "Playlist.h"
#include <vector>
#include <string>
#include <iostream>

Playlist::Playlist(std::string playlistName) {
	this->playlistName = playlistName;
}

void Playlist::AddSong(Song* newSong) {
	this->playlist.push_back(newSong);
}

void Playlist::RemoveSong(int index) {
	playlist.erase(playlist.begin() + index);
}

std::string Playlist::GetPlaylistName() {
	return this->playlistName;
}

void Playlist::SetPlaylistName(std::string name) {
	this->playlistName = name;
}

void Playlist::PrintSongLines() {
	for (auto i : this->playlist) {
		i->PlaySong();
	}
}

std::vector<Song*> Playlist::GetPlaylist() {
	return this->playlist;
}