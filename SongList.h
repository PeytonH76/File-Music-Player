//
// Created by Peyton Haws on 5/16/24.
//

#ifndef MUSICPLAYER_SONGLIST_H
#define MUSICPLAYER_SONGLIST_H

#include <iostream>

#include "MainSongPlayer.h"

class SongList : public MainSongPlayer {
public:
    SongList(const std::shared_ptr<std::map<std::string, std::string>>& songs); // Constructor
    virtual void playSong() override;
};

#endif
