//
// Created by Peyton Haws on 5/23/24.
//

#ifndef MUSICPLAYER_PLAYSONG_H
#define MUSICPLAYER_PLAYSONG_H

#include <iostream>
#include "MainSongPlayer.h"

class PlaySong : public MainSongPlayer {
public:
    PlaySong(const std::shared_ptr<std::map<std::string, std::string>>& songs); // Constructor
    virtual void playSong() override;
};


#endif
