
#include "MainSongPlayer.h"
// The base class, or parent class

MainSongPlayer::MainSongPlayer(const std::shared_ptr<std::map<std::string, std::string>>& songs) : songs(songs) {}