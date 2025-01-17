#include "media.h"
#include <iostream>

Media::Media(const char* title, int year) {
    strncpy(this->title, title, 99);
    this->title[99] = '\0';
    this->year = year;
}

Media::~Media() {}

const char* Media::getTitle() const {
    return title;
}

int Media::getYear() const {
    return year;
}