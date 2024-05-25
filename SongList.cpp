#include "SongList.h"
#include "iostream"

SongList::SongList(const std::shared_ptr<std::map<std::string, std::string>>& songs) : MainSongPlayer(songs) {}

void SongList::playSong() {

    std::cout << "Available songs:\n";
    // Display list of songs
    int index = 1;
    for (const auto& pair : *songs) {
        std::cout << index++ << ". " << pair.second << '\n'; // pair.second is the song name
    }

}