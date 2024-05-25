//
// Created by Peyton Haws on 5/24/24.
//

#ifndef MUSICPLAYER_ADDSONG_H
#define MUSICPLAYER_ADDSONG_H

#include "MainSongPlayer.h"
#include <iostream>


class AddSong: public MainSongPlayer {
public:
    AddSong(const std::shared_ptr<std::map<std::string, std::string>>& songs, const std::string& filePath); // This is the constructor
    virtual void playSong() override;
    void addSong(const std::string& filePath, const std::string& songName);
    void saveSongsToFile();
    void loadSongsFromFile();

private:
    std::string filePath;
};


#endif //MUSICPLAYER_ADDSONG_H
