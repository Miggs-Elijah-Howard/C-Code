#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"
#include "Playlist.cpp"
#include "Song.cpp"

std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(std::vector<Song*> &songLibrary);
void ListSongsMenuOption(std::vector<Song*> songLibrary);
void AddPlaylistMenuOption(std::vector<Playlist*> &playlistLib);
void AddSongToPlaylistMenuOption(std::vector<Song*> songLibrary, std::vector<Playlist*> &playlistLib);
void ListPlaylistsMenuOption(std::vector<Playlist*> playlistLib);
void PlayPlaylistMenuOption(std::vector<Playlist*> playlistLib);
void RemovePlaylistMenuOption(std::vector<Playlist*> &playlistLib);
void RemoveSongFromPlaylistMenuOption(std::vector<Playlist*> &playlistLib);
void RemoveSongFromLibraryMenuOption(std::vector<Song*> &songLibrary, std::vector<Playlist*> &playlistLib);
void OptionsMenuOption();
void QuitMenuOption();

int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    std::vector<Song*> songLibrary;
    std::vector<Playlist*> playlistLib;

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(songLibrary);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(songLibrary);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(playlistLib);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(songLibrary, playlistLib);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(playlistLib);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(playlistLib);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(playlistLib);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(playlistLib);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(songLibrary, playlistLib);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }
    // ----------------------------
    for (unsigned int i = 0; i < songLibrary.size(); ++i) {
        Song* songPtr = songLibrary[i];
        delete songPtr;
    }

    for (unsigned int i = 0; i < playlistLib.size(); ++i) {
        Playlist* playPtr = playlistLib[i];
        delete playPtr;
    }
    songLibrary.clear();
    playlistLib.clear();
    // ------------------------------- In between the dashed lines is where I free up all memory prior to the program's termination

   // if (songLibrary.empty()) std::cout << "Song library is empty." << std::endl;
   // if (playlistLib.empty()) std::cout << "Playlist library is empty." << std::endl;
 
    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0.0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(std::vector<Song*> &songLibrary) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
        << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        songLibrary.push_back(new Song(songName, firstLine));

        songName = GetUserString("Song Name: ");

    }
}

void ListSongsMenuOption(std::vector<Song*> songLibrary) {
    for (auto i : songLibrary) {
        i->PrintSongInfo();
    }
}

void AddPlaylistMenuOption(std::vector<Playlist*> &playlistLib) {
    Playlist* playPtr = new Playlist(GetUserString("Playlist name: "));
    playlistLib.push_back(playPtr);
}

void AddSongToPlaylistMenuOption(std::vector<Song*> songLibrary, std::vector<Playlist*> &playlistLib) {
    ListPlaylistsMenuOption(playlistLib);
    int* indexPtr = new int(GetUserInt("Pick a playlist index number: "));
    for (unsigned int i = 0; i < songLibrary.size(); ++i) {
        std::cout << i << ": " << songLibrary.at(i)->GetSongName() << std::endl;
    }
    int* songIndex = new int(GetUserInt("Pick a song index number: "));
    Song* songPtr = songLibrary.at(*songIndex);
    playlistLib.at(*indexPtr)->AddSong(songPtr);

    delete songIndex; //free up memory
    delete indexPtr; //free up memory
 
}

void ListPlaylistsMenuOption(std::vector<Playlist*> playlistLib) {
    for (unsigned int i = 0; i < playlistLib.size(); ++i) {
        std::cout << i << ": " << playlistLib.at(i)->GetPlaylistName() << std::endl;
    }
}

void PlayPlaylistMenuOption(std::vector<Playlist*> playlistLib) {
    ListPlaylistsMenuOption(playlistLib);
    int* playlistIndex = new int(GetUserInt("Pick a playlist index number: "));
    Playlist* playlistPtr = playlistLib.at(*playlistIndex);

    std::cout << "Playing songs from playlist: " << playlistPtr->GetPlaylistName() << std::endl;
    playlistPtr->PrintSongLines();
    delete playlistIndex; //free up memory
}
void RemovePlaylistMenuOption(std::vector<Playlist*> &playlistLib) {
    ListPlaylistsMenuOption(playlistLib);
    int* indexPtr = new int(GetUserInt("Pick a playlist index number to remove: "));
    Playlist* playlistPtr = playlistLib.at(*indexPtr);

    playlistLib.erase(playlistLib.begin() + *indexPtr);
    delete playlistPtr; //free up memory
    delete indexPtr; //free up memory
}

void RemoveSongFromPlaylistMenuOption(std::vector<Playlist*> &playlistLib) {
    ListPlaylistsMenuOption(playlistLib);
    int* listLibIndex = new int(GetUserInt("Pick a playlist index number: "));
    Playlist* currList = playlistLib.at(*listLibIndex);

    for (unsigned int i = 0; i < currList->GetPlaylist().size(); ++i) {
        std::cout << i << ": " << currList->GetPlaylist().at(i)->GetSongName() << std::endl;
    }
    int* songIndex = new int(GetUserInt("Pick a song index number to remove: "));

    currList->RemoveSong(*songIndex);
    delete listLibIndex; //free up memory
    delete songIndex; //free up memory
}
void RemoveSongFromLibraryMenuOption(std::vector<Song*> &songLibrary, std::vector<Playlist*> &playlistLib) {
    
    for (unsigned int i = 0; i < songLibrary.size(); ++i) {
        std::cout << i << ": " << songLibrary.at(i)->GetSongName() << std::endl;
    }
    int* indexPtr = new int(GetUserInt("Pick a song index number to remove: "));
    
    for (auto i : playlistLib) {
        for (unsigned int j = 0; j < i->GetPlaylist().size(); ++j) {
            if (i->GetPlaylist().at(j)->GetSongName() == songLibrary.at(*indexPtr)->GetSongName()) {
                i->RemoveSong(j);
            }
        }
    }

    delete songLibrary.at(*indexPtr); //free up memory
    songLibrary.erase(songLibrary.begin() + *indexPtr);
    delete indexPtr; //free up memory
}

void OptionsMenuOption() {
    std::cout << "add      Adds a list of songs to the library" << std::endl
        << "list     Lists all the songs in the library" << std::endl
        << "addp     Adds a new playlist" << std::endl
        << "addsp    Adds a song to a playlist" << std::endl
        << "listp    Lists all the playlists" << std::endl
        << "play     Plays a playlist" << std::endl
        << "remp     Removes a playlist" << std::endl
        << "remsp    Removes a song from a playlist" << std::endl
        << "remsl    Removes a song from the library (and all playlists)" << std::endl
        << "options  Prints this options menu" << std::endl
        << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption() {
    std::cout << "Goodbye!" << std::endl;
}

