
#ifndef MUSICPLAYER_MAINSONGPLAYER_H
#define MUSICPLAYER_MAINSONGPLAYER_H

#include <map>
#include <string>
#include <memory> // for std::shared_ptr which is a pointer

class MainSongPlayer {
protected:
    // Shared map of songs. Made possible by the shared pointer
    std::shared_ptr<std::map<std::string, std::string>> songs; // <File Path, Song Name>

public:
    MainSongPlayer(const std::shared_ptr<std::map<std::string, std::string>>& songs); // Constructor
    virtual void playSong() = 0; // Pure virtual function. This will be overridden by child classes
};


#endif //MUSICPLAYER_MAINSONGPLAYER_H
