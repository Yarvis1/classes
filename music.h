#ifndef MUSIC_H
#define MUSIC_H

#include "media.h"

class Music : public Media {
private:
    char artist[100];
    float duration;
    char publisher[100];

public:
    Music(const char* title, int year, const char* artist, float duration, const char* publisher);
    ~Music();
    void display() const override;
    const char* getArtist() const;
    float getDuration() const;
    const char* getPublisher() const;
};

#endif