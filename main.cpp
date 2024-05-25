#include "SongList.h"
#include "PlaySong.h"
#include "AddSong.h"
#include "RandomSongPlayer.h"
#include <iostream>
#include <map>
#include <memory>

int main() {
    // Create the songs map and pass it to instances of each class
    auto songs = std::make_shared<std::map<std::string, std::string>>(std::map<std::string, std::string>{// <key=file path, value=song name>
            {"/Users/peytonhaws/Documents/AppliedProgramming/MusicPlayer/cmake-build-debug/Europa.wav",
             "Europa by Globus"},
            {"/Users/peytonhaws/Documents/AppliedProgramming/MusicPlayer/cmake-build-debug/02MightyRiversRun.m4a",
             "Mighty Rivers Run by Globus"},
            {"/Users/peytonhaws/Documents/AppliedProgramming/MusicPlayer/cmake-build-debug/meeting_stars.mp3",
             "Meeting Stars by Unanimous"},
             {"/Users/peytonhaws/Documents/AppliedProgramming/MusicPlayer/cmake-build-debug/CaliforniaDreamin.wav",
              "California Dreamin by The Mamas & Papas"}
    });

    // File path for saving and loading songs
    std::string songsFilePath = "songs.txt";

    bool isGoing = true;
    // Create instances of classes
    SongList songlist(songs);
    PlaySong playsong(songs);
    AddSong addsong(songs, songsFilePath);
    RandomSongPlayer randomSongPlayer(songs);

    while (isGoing) {

        // Display Menu
        std::cout << "Welcome to the Music Player!" << std::endl;
        std::cout << "You can choose a random song, see a list of songs, choose a song or add a song." << std::endl;
        std::cout << "1. Song List" << std::endl;
        std::cout << "2. Choose Song" << std::endl;
        std::cout << "3. Random Song" << std::endl;
        std::cout << "4. Add Song" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "\n";
        std::string choice; std::cin >> choice;
        std::cout << "\n";

        if (choice == "1" || choice == "one") {
           songlist.playSong();
           std::cout << "" << "\n";
        }
        else if (choice == "2" || choice == "two") {
            playsong.playSong();
            std::cout << "" << "\n";
        }
        else if (choice == "3" || choice == "three") {
            randomSongPlayer.playSong();
            std::cout << "" << "\n";
        }
        else if (choice == "4" || choice == "four") {
            std::string filePath, songName;
            std::cout << "Enter the file path of the new song: ";
            std::cin.ignore(); // Ignore leftover newline character from previous line
            std::getline(std::cin, filePath);
            std::cout << "Enter the name of the new song: ";
            std::getline(std::cin, songName);
            addsong.addSong(filePath, songName);

            // Display updated list
            std::cout << "\n=== Updated Song List ===\n";
            addsong.playSong();
            std::cout << "\n";
        }
        else if (choice == "5" || choice == "five"){
            std::cout << "Exiting now." << std::endl;
            isGoing = false;
        }
        else{
            std::cout << "Sorry that's not a choice. Choose again." << std::endl;
        }
    }
    return 0;
}
