// games.cpp
#include "games.h"
#include <iostream>

Games::Games(const char* title, int year, const char* publisher, float rating) : Media(title, year) {
    strncpy(this->publisher, publisher, 99);
    this->publisher[99] = '\0';
    this->rating = rating;
}

Games::~Games() {}

void Games::display() const {
    std::cout << "Title: " << title << "\nYear: " << year << "\nPublisher: " << publisher << "\nRating: " << rating << "\n";
}

const char* Games::getPublisher() const {
    return publisher;
}

float Games::getRating() const {
    return rating;
}
