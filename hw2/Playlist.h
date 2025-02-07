#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <fstream>

class Playlist {
public:	
	Playlist() : head(nullptr), tail(nullptr) {}

	void AddSong(std::string title, int duration, bool fav_status);
	void PrintPlaylist(std::ofstream& outFile);
	void PrintReversedPlaylist(std::ofstream& outFile);
	void DeleteSong(std::string title);
	void CreateSmartPlaylist(int time_limit, std::ofstream& outFile);

private:
	void DeleteNode(Song* node);

	int length = 0;
	bool has_favs = false;

	Song* head;
	Song* tail;
};

#endif