#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
public:
	Song(std::string title, int duration, bool fav_status) : title(title), duration(duration), fav_status(fav_status), next(nullptr), prev(nullptr) {}

private:
	std::string title;
	int duration;
	bool fav_status;

	Song* next;
	Song* prev;

	friend class Playlist;
};

#endif