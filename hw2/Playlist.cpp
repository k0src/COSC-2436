#include "Playlist.h"

void Playlist::AddSong(std::string title, int duration, bool fav_status) {
	auto song = new Song(title, duration, fav_status);

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
	if (!head) return;

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
	if (!head) return;

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
    if (!head) return;

    Playlist smart_playlist;
    int playlist_time = 0;
    int fav_index = -1;
    auto current = head;

    for (int i = 0; current != nullptr; i++) {
        if (current->fav_status && playlist_time + current->duration <= time_limit) {
            smart_playlist.AddSong(current->title, current->duration, current->fav_status);
            playlist_time += current->duration;
            fav_index = i;
        }
        current = current->next;
    }

    if (fav_index == -1) {
        smart_playlist.PrintPlaylist(outFile);
        return;
    }

    current = head;
    for (int i = 0; i < fav_index; i++) {
        current = current->next;
    }

    while (current) {
        if (!current->fav_status && playlist_time + current->duration <= time_limit) {
            smart_playlist.AddSong(current->title, current->duration, current->fav_status);
            playlist_time += current->duration;
        }
        current = current->prev;
    }

    current = head;
    for (int i = 0; i <= fav_index; i++) {
        current = current->next;
    }

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