#include "music.h"
#include <iostream>

Music::Music(const char* title, int year, const char* artist, float duration, const char* publisher) : Media(title, year) {
    strncpy(this->artist, artist, 99);
    this->artist[99] = '\0';
    this->duration = duration;
    strncpy(this->publisher, publisher, 99);
    this->publisher[99] = '\0';
}

Music::~Music() {}

void Music::display() const {
    std::cout << "Title: " << title << "\nYear: " << year << "\nArtist: " << artist << "\nDuration: " << duration << " minutes\nPublisher: " << publisher << "\n";
}

const char* Music::getArtist() const {
    return artist;
}

float Music::getDuration() const {
    return duration;
}

const char* Music::getPublisher() const {
    return publisher;
}
