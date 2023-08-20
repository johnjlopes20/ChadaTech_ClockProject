// Menu.h
#ifndef MENU_H
#define MENU_H

#include "Clock.h"
#include <iostream>

class Menu {
public:
    // Constructor to initialize the menu with a default clock
    Menu();

    // Function to display the menu options
    void displayMenu();

    // Function to process user input and execute the chosen operation
    void processInput();

private:
    // Function to display both 12-hour and 24-hour time formats
    void displayBothFormats(Clock& clock);

    // Private data member to store the clock object
    Clock clock_;
};

#endif // MENU_H

