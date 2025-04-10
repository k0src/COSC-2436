#include "Playlist.h"

void Playlist::AddSong(std::string title, int duration, bool fav_status) {
	auto song = new Song(title, duration, fav_status);

    if (fav_status) has_favs = true;

	if (!head) {
		head = song;
		tail = song; 
	} else {
		tail->next = song;
		song->prev = tail;
		tail = song;
	}

	length++;
}

void Playlist::PrintPlaylist(std::ofstream& outFile) {
	if (!head) {
        outFile << "[]\n";
        return;
    }

	auto current = head;

	outFile << "[";

	while (current) {
		outFile << current->title;
		if (current->next) {
			outFile << ", ";
		}
		current = current->next;
	}

	outFile << "]\n";
}

void Playlist::PrintReversedPlaylist(std::ofstream& outFile) {
    if (!head) {
        outFile << "[]\n";
        return;
    }

	auto current = tail;

	outFile << "[";

	while (current) {
		outFile << current->title;
		if (current->prev) {
			outFile << ", ";
		}
		current = current->prev;
	}

	outFile << "]\n";
}

void Playlist::DeleteSong(std::string title) {
    if (!head) return;

    auto current = head;

    while (current) {
        if (current->title == title) {
            Song* toDelete = current;
            current = current->next;
            DeleteNode(toDelete);
        } else {
            current = current->next;
        }
    }

    length--;
}

void Playlist::CreateSmartPlaylist(int time_limit, std::ofstream& outFile) {
    Playlist smart_playlist;
    int playlist_time = 0;

    if (!head) {
        smart_playlist.PrintPlaylist(outFile);
        return;
    }

    Song* last_favorite = nullptr;
    auto current = head;

    while (current) {
        if (current->fav_status && playlist_time + current->duration <= time_limit) {
            smart_playlist.AddSong(current->title, current->duration, current->fav_status);
            playlist_time += current->duration;
            last_favorite = current;
        }
        current = current->next;
    }

    if (!last_favorite) {
        current = head;
        while (current) {
            if (playlist_time + current->duration <= time_limit) {
                smart_playlist.AddSong(current->title, current->duration, current->fav_status);
                playlist_time += current->duration;
            }
            current = current->next;
        }
        smart_playlist.PrintPlaylist(outFile);
        return;
    }

    current = head;
    while (current != last_favorite) {
        if (!current->fav_status && playlist_time + current->duration <= time_limit) {
            smart_playlist.AddSong(current->title, current->duration, current->fav_status);
            playlist_time += current->duration;
        }
        current = current->next;
    }

    current = last_favorite->next;
    while (current) {
        if (!current->fav_status && playlist_time + current->duration <= time_limit) {
            smart_playlist.AddSong(current->title, current->duration, current->fav_status);
            playlist_time += current->duration;
        }
        current = current->next;
    }

    smart_playlist.PrintPlaylist(outFile);
}

void Playlist::DeleteNode(Song* node) {
    if (!node) return;

    if (node == head) {
        head = node->next;
        if (head) head->prev = nullptr;
    }
    
    if (node == tail) {
        tail = node->prev;
        if (tail) tail->next = nullptr;
    }

    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    delete node;
}