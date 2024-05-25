
#include "RandomSongPlayer.h"
#include <iostream>
#include <cstdlib> // for std::system and std::rand
#include <ctime>   // for std::time

RandomSongPlayer::RandomSongPlayer(const std::shared_ptr<std::map<std::string, std::string>>& songs)
        : MainSongPlayer(songs) {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void RandomSongPlayer::playSong() {
    if (songs->empty()) {
        std::cerr << "No songs available to play.\n";
        return;
    }

    // Get a random index
    int randomIndex = std::rand() % songs->size();

    // Get a song at the random index
    auto it = songs->begin();
    std::advance(it, randomIndex);
    std::string filePath = it->first;
    std::string songName = it->second;

    std::cout << "Playing random song: " << songName << "\n";

    std::string command = "afplay \"" + filePath + "\"";
    std::system(command.c_str());

}