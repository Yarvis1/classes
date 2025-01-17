#include "movies.h"
#include <iostream>

Movies::Movies(const char* title, int year, const char* director, float duration, float rating) : Media(title, year) {
    strncpy(this->director, director, 99);
    this->director[99] = '\0';
    this->duration = duration;
    this->rating = rating;
}

Movies::~Movies() {}

void Movies::display() const {
    std::cout << "Title: " << title << "\nYear: " << year << "\nDirector: " << director << "\nDuration: " << duration << " minutes\nRating: " << rating << "\n";
}

const char* Movies::getDirector() const {
    return director;
}

float Movies::getDuration() const {
    return duration;
}

float Movies::getRating() const {
    return rating;
}
