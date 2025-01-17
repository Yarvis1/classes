#ifndef MEDIA_H
#define MEDIA_H

#include <cstring>
#include <string>

class Media {
protected:
    char title[100];
    int year;

public:
    Media(const char* title, int year);
    virtual ~Media();
    virtual void display() const = 0;
    const char* getTitle() const;
    int getYear() const;
};

#endif