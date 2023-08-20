// Clock.h
#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include <stdexcept>

class Clock {
public:
    // Constructor to initialize the clock to 00:00:00
    Clock();

    // Function to set the time in 12-hour format
    // Parameters:
    //   - hours: The hour value (0-12)
    //   - minutes: The minute value (0-59)
    //   - seconds: The second value (0-59)
    //   - isAM: Boolean flag indicating AM (true) or PM (false)
    // Throws:
    //   - std::invalid_argument if the input values are invalid
    void set12HourTime(int hours, int minutes, int seconds, bool isAM);

    // Function to set the time in 24-hour format
    // Parameters:
    //   - hours: The hour value (0-23)
    //   - minutes: The minute value (0-59)
    //   - seconds: The second value (0-59)
    // Throws:
    //   - std::invalid_argument if the input values are invalid
    void set24HourTime(int hours, int minutes, int seconds);

    // Function to add one second to the clock's time
    void addSecond();

    // Function to add one minute to the clock's time
    void addMinute();

    // Function to add one hour to the clock's time
    void addHour();

    // Function to get the clock's time in 12-hour format as a string
    std::string get12HourTime() const;

    // Function to get the clock's time in 24-hour format as a string
    std::string get24HourTime() const;

private:
    // Helper function to check if the given time values are valid
    bool isValidTime(int hours, int minutes, int seconds);

    // Private data members to store the clock's hours, minutes, and seconds
    int hours_;
    int minutes_;
    int seconds_;
};

#endif // CLOCK_H

