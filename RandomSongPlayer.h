
#ifndef MUSICPLAYER_RANDOMSONGPLAYER_H
#define MUSICPLAYER_RANDOMSONGPLAYER_H

#include "MainSongPlayer.h"

class RandomSongPlayer: public MainSongPlayer {
public:
    RandomSongPlayer(const std::shared_ptr<std::map<std::string, std::string>>& songs);
    virtual void playSong() override;
};


#endif
