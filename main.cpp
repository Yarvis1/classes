#include "games.h"
#include "music.h"
#include "movies.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//prototypes
void addMedia(vector<Media*>& database);
void searchMedia(const vector<Media*>& database);
void deleteMedia(vector<Media*>& database);

int main() {
    vector<Media*> database; // vector to push back
    bool running = true;

    while (running) {
        // commands for user
        cout << "\nMedia Database\n";
        cout << "Enter 'add' to Add Media, 'search' to Search Media, 'delete' to Delete Media, or 'exit' to Exit: ";
        char command[10];
        cin >> command;
        cin.ignore(); 

        if (strcmp(command, "add") == 0) {
            addMedia(database); 
        } else if (strcmp(command, "search") == 0) {
            searchMedia(database); 
        } else if (strcmp(command, "delete") == 0) {
            deleteMedia(database); 
        } else if (strcmp(command, "exit") == 0) {
            running = false; // Exit the program
        } else {
            cout << "Invalid command. Try again.\n";
        }
    }

    // Clean up allocated memory
    for (Media* media : database) {
        delete media;
    }

    return 0;
}

void addMedia(vector<Media*>& database) {
    cout << "\nAdd Media\n";
    cout << "1. Game\n2. Music\n3. Movie\nChoose type: ";
    int type;
    if (!(cin >> type)) { // check input type
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter a number.\n";
        return;
    }
    cin.ignore();

    char title[100];
    int year;

    // Input common fields for all media types
    cout << "Enter title: ";
    cin.getline(title, 100);
    cout << "Enter year: ";
    if (!(cin >> year)) { // check input
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter a valid year.\n";
        return;
    }
    cin.ignore();

    if (type == 1) { // Add a game
        char publisher[100];
        float rating;

        cout << "Enter publisher: ";
        cin.getline(publisher, 100);
        cout << "Enter rating: ";
        if (!(cin >> rating)) { // check for rating
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid rating.\n";
            return;
        }
        cin.ignore();

        database.push_back(new Games(title, year, publisher, rating));
    } else if (type == 2) { // Add music
        char artist[100];
        float duration;
        char publisher[100];

        cout << "Enter artist: ";
        cin.getline(artist, 100);
        cout << "Enter duration (minutes): ";
        if (!(cin >> duration)) { // check for duration
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid duration.\n";
            return;
        }
        cin.ignore();
        cout << "Enter publisher: ";
        cin.getline(publisher, 100);

        database.push_back(new Music(title, year, artist, duration, publisher));
    } else if (type == 3) { // Add
        char director[100];
        float duration;
        float rating;

        cout << "Enter director: ";
        cin.getline(director, 100);
        cout << "Enter duration (minutes): ";
        if (!(cin >> duration)) { // check duration
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid duration.\n";
            return;
        }
        cin.ignore();
        cout << "Enter rating: ";
        if (!(cin >> rating)) { // check rating
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid rating.\n";
            return;
        }
        cin.ignore();

        database.push_back(new Movies(title, year, director, duration, rating));
    } else {
        cout << "Invalid type.\n";
    }
}

void searchMedia(const vector<Media*>& database) {
    cout << "\nSearch Media\n";
    cout << "1. By Title\n2. By Year\nChoose option: ";
    int option;
    if (!(cin >> option)) { // check option
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter a number.\n";
        return;
    }
    cin.ignore();

    if (option == 1) { // Search title
        char title[100];
        cout << "Enter title: ";
        cin.getline(title, 100);

        for (const Media* media : database) {
            if (strcmp(media->getTitle(), title) == 0) { // Compare titles
                media->display();
            }
        }
    } else if (option == 2) { // Search year
        int year;
        cout << "Enter year: ";
        if (!(cin >> year)) { // check year
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid year.\n";
            return;
        }

        for (const Media* media : database) {
            if (media->getYear() == year) { // Compare years
                media->display();
            }
        }
    } else {
        cout << "Invalid option.\n";
    }
}

void deleteMedia(vector<Media*>& database) {
    cout << "\nDelete Media\n";
    cout << "1. By Title\n2. By Year\nChoose option: ";
    int option;
    if (!(cin >> option)) { // check option
       cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter a number.\n";
        return;
    }
    cin.ignore();

    if (option == 1) { // Delete title
        char title[100];
        cout << "Enter title: ";
        cin.getline(title, 100);

        // Remove matching media from the database
        auto it = remove_if(database.begin(), database.end(), [title](Media* media) {
            if (strcmp(media->getTitle(), title) == 0) { // Compare titles
                delete media;
                return true;
            }
            return false;
        });
        database.erase(it, database.end());
    } else if (option == 2) { // Delete by year
        int year;
        cout << "Enter year: ";
        if (!(cin >> year)) { //check year
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid year.\n";
            return;
        }

        // Remove matching media from the database
        auto it = remove_if(database.begin(), database.end(), [year](Media* media) {
            if (media->getYear() == year) { // Compare years
                delete media;
                return true;
            }
            return false;
        });
        database.erase(it, database.end());
    } else {
        cout << "Invalid option.\n";
    }
}
