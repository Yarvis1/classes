// games.h
#ifndef GAMES_H
#define GAMES_H

#include "media.h"

class Games : public Media {
private:
    char publisher[100];
    float rating;

public:
    Games(const char* title, int year, const char* publisher, float rating);
    ~Games();
    void display() const override;
    const char* getPublisher() const;
    float getRating() const;
};

#endif