#include "PlaySong.h"
#include <cstdlib>

PlaySong::PlaySong(const std::shared_ptr<std::map<std::string, std::string>>& songs) : MainSongPlayer(songs) {}

void PlaySong::playSong() {
    std::cout << "Available songs:\n";
    int index = 1;
    for (const auto& pair : *songs) {
        std::cout << index++ << ". " << pair.second << '\n'; // pair.second is the song name
    }

    std::cout << "Enter the number of the song you want to play: ";
    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > songs->size()) {
        std::cerr << "Invalid choice.\n";
        return;
    }

    auto it = songs->begin();
    std::advance(it, choice - 1);
    std::string command = "afplay \"" + it->first + "\""; // it->first is the file path
    std::system(command.c_str());
}