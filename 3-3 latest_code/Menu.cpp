// Menu.cpp
#include "Menu.h"
#include <limits>

Menu::Menu() {}

void Menu::displayMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Set 12-hour time" << std::endl;
    std::cout << "2. Set 24-hour time" << std::endl;
    std::cout << "3. Add a second" << std::endl;
    std::cout << "4. Add a minute" << std::endl;
    std::cout << "5. Add an hour" << std::endl;
    std::cout << "6. Display both formats" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void Menu::processInput() {
    int choice;
    bool exit = false;

    do {
        displayMenu();

        // Handle invalid input (e.g., non-integer or out-of-range values)
        while (!(std::cin >> choice) || choice < 0 || choice > 6) {
            std::cout << "Invalid input. Please enter a valid choice (0-6): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {
                int hours, minutes, seconds;
                bool isAM;
                std::cout << "Enter hours (0-12): ";
                std::cin >> hours;
                std::cout << "Enter minutes (0-59): ";
                std::cin >> minutes;
                std::cout << "Enter seconds (0-59): ";
                std::cin >> seconds;
                std::cout << "Is it AM? (1 for AM, 0 for PM): ";
                std::cin >> isAM;

                try {
                    clock_.set12HourTime(hours, minutes, seconds, isAM);
                } catch (const std::invalid_argument& e) {
                    std::cout << "Invalid time format. " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                int hours, minutes, seconds;
                std::cout << "Enter hours (0-23): ";
                std::cin >> hours;
                std::cout << "Enter minutes (0-59): ";
                std::cin >> minutes;
                std::cout << "Enter seconds (0-59): ";
                std::cin >> seconds;

                try {
                    clock_.set24HourTime(hours, minutes, seconds);
                } catch (const std::invalid_argument& e) {
                    std::cout << "Invalid time format. " << e.what() << std::endl;
                }
                break;
            }
            case 3:
                clock_.addSecond();
                break;
            case 4:
                clock_.addMinute();
                break;
            case 5:
                clock_.addHour();
                break;
            case 6:
                displayBothFormats(clock_);
                break;
            case 0:
                exit = true;
                break;
        }

        // Clear any remaining characters in the input stream
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (!exit);
}

void Menu::displayBothFormats(Clock& clock) {
    std::cout << "12-hour format: " << clock.get12HourTime() << std::endl;
    std::cout << "24-hour format: " << clock.get24HourTime() << std::endl;
}

