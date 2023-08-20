// Clock.cpp
#include "Clock.h"

Clock::Clock() : hours_(0), minutes_(0), seconds_(0) {}

bool Clock::isValidTime(int hours, int minutes, int seconds) {
    return (hours >= 0 && hours <= 23) &&
           (minutes >= 0 && minutes <= 59) &&
           (seconds >= 0 && seconds <= 59);
}

void Clock::set12HourTime(int hours, int minutes, int seconds, bool isAM) {
    if (!isValidTime(hours, minutes, seconds)) {
        throw std::invalid_argument("Invalid time values. Hours, minutes, or seconds are out of range.");
    }

    // Convert the hours to 12-hour format and adjust if necessary
    if (hours > 12) {
        hours -= 12;
    }

    // Set the clock's time
    hours_ = isAM ? hours : hours + 12;
    minutes_ = minutes;
    seconds_ = seconds;
}

void Clock::set24HourTime(int hours, int minutes, int seconds) {
    if (!isValidTime(hours, minutes, seconds)) {
        throw std::invalid_argument("Invalid time values. Hours, minutes, or seconds are out of range.");
    }

    // Set the clock's time
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
}

void Clock::addSecond() {
    // Increment seconds by one
    seconds_++;

    // Adjust minutes and hours if necessary
    if (seconds_ >= 60) {
        seconds_ = 0;
        addMinute();
    }
}

void Clock::addMinute() {
    // Increment minutes by one
    minutes_++;

    // Adjust hours if necessary
    if (minutes_ >= 60) {
        minutes_ = 0;
        addHour();
    }
}

void Clock::addHour() {
    // Increment hours by one
    hours_++;

    // Reset hours to 0 if it reaches 24
    if (hours_ >= 24) {
        hours_ = 0;
    }
}

std::string Clock::get12HourTime() const {
    // Determine the meridian (AM or PM)
    std::string meridian = (hours_ >= 12) ? "PM" : "AM";

    // Convert hours to 12-hour format and adjust if necessary
    int displayHours = (hours_ % 12 == 0) ? 12 : hours_ % 12;

    // Create and return the formatted 12-hour time string
    return std::to_string(displayHours) + ":" +
           (minutes_ < 10 ? "0" : "") + std::to_string(minutes_) + ":" +
           (seconds_ < 10 ? "0" : "") + std::to_string(seconds_) + " " + meridian;
}

std::string Clock::get24HourTime() const {
    // Create and return the formatted 24-hour time string
    return (hours_ < 10 ? "0" : "") + std::to_string(hours_) + ":" +
           (minutes_ < 10 ? "0" : "") + std::to_string(minutes_) + ":" +
           (seconds_ < 10 ? "0" : "") + std::to_string(seconds_);
}

