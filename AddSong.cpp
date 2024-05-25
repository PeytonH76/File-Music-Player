
#include "AddSong.h"
#include <fstream> // for files

// Any changes made by AddSong are shown in the other child classes
// This is the Constructor
AddSong::AddSong(const std::shared_ptr<std::map<std::string, std::string>>& songs, const std::string& filePath)
        : MainSongPlayer(songs), filePath(filePath) { // Takes file path where songs will be loaded and saved to a text file
    loadSongsFromFile();// Loads songs when the object is created
}

void AddSong::playSong() {
    // Displays songs by iterating over the songs in the map
    std::cout << "Available songs:\n";
    int index = 1;
    for (const auto& pair : *songs) {
        std::cout << index++ << ". " << pair.second << '\n'; // pair.second is the song name
    }
}

void AddSong::addSong(const std::string& filePath, const std::string& songName) {
    // Check if the song already exists
    for (const auto& pair : *songs) {
        if (pair.second == songName) {
            std::cerr << "Song \"" << songName << "\" is already in the list.\n";
            return;
        }
    }

    // Adds song to the map
    (*songs)[filePath] = songName;
    std::cout << "Song added: " << songName << " (" << filePath << ")\n";
    saveSongsToFile(); // Save songs to file after adding songs
}

// Saves Songs to a file
void AddSong::saveSongsToFile() {
    // Open file for writing
    std::ofstream outFile(filePath, std::ios::out);
    if (!outFile) {
        std::cerr << "Unable to open file for writing: " << filePath << '\n';
        return;
    }
    // Write each song's file path and name to the file
    for (const auto& pair : *songs) {
        outFile << pair.first << "\n" << pair.second << "\n"; // Write file path and song name
    }
    // Close the file
    outFile.close();
}

// Loads Songs from a file
void AddSong::loadSongsFromFile() {
    // Open file for reading
    std::ifstream inFile(filePath, std::ios::in);

    if (!inFile) {
        std::cerr << "Unable to open file for reading: " << filePath << '\n';
        return;
    }
    std::string filePath, songName;
    // Read file path and name pairs from file
    while (std::getline(inFile, filePath) && std::getline(inFile, songName)) {
        (*songs)[filePath] = songName; // Read file path and song name
    }
    inFile.close();
}