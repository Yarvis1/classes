#ifndef MOVIES_H
#define MOVIES_H

#include "media.h"

class Movies : public Media {
private:
    char director[100];
    float duration;
    float rating;

public:
    Movies(const char* title, int year, const char* director, float duration, float rating);
    ~Movies();
    void display() const override;
    const char* getDirector() const;
    float getDuration() const;
    float getRating() const;
};

#endif
