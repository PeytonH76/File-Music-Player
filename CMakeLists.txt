cmake_minimum_required(VERSION 3.28)
project(MusicPlayer)

set(CMAKE_CXX_STANDARD 17)

# Specify source files
set(SOURCE_FILES
        main.cpp
        SongList.cpp
        PlaySong.cpp
        PlaySong.h
        MainSongPlayer.cpp
        MainSongPlayer.h
        AddSong.cpp
        AddSong.h
        RandomSongPlayer.cpp
        RandomSongPlayer.h
)

# Create executable target
add_executable(MusicPlayer ${SOURCE_FILES} SongList.h)

# Find required macOS frameworks
find_library(CoreFoundation CoreFoundation)
find_library(AudioToolbox AudioToolbox)
find_library(AVFoundation AVFoundation)

# Link macOS frameworks to the executable target
target_link_libraries(MusicPlayer ${CoreFoundation} ${AudioToolbox} ${AVFoundation})

# Set properties to compile source files as Objective-C++
set_source_files_properties(SongList.cpp PROPERTIES COMPILE_FLAGS "-x objective-c++")
