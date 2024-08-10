#include "simple.hpp"

Type get_type(std::string value) {
    std::regex dateTimeRegex("^\\d{2}/\\d{2}/\\d{4} \\d{2}:\\d{2}:\\d{2}$");
    std::regex timeRegex("^\\d{2}:\\d{2}:\\d{2}$");
    std::regex dateRegex("^\\d{2}/\\d{2}/\\d{4}$");
    std::regex yearMonthRegex("^\\d{4}-\\d{2}$");
    std::regex yearRegex("^\\d{4}$");
    std::regex monthDayRegex("^\\d{2}/\\d{2}$");
    std::regex dayRegex("^\\d{2}$");
    std::regex monthRegex("^\\d{2}$");
    std::regex numberRegex("^\\d+$");

    if (std::regex_match(value, dateTimeRegex)) {
        return dateTime;
    } else if (std::regex_match(value, timeRegex)) {
        return time;
    } else if (std::regex_match(value, dateRegex)) {
        return date;
    } else if (std::regex_match(value, yearMonthRegex)) {
        return yearMonth;
    } else if (std::regex_match(value, yearRegex)) {
        return year;
    } else if (std::regex_match(value, monthDayRegex)) {
        return monthDay;
    } else if (std::regex_match(value, dayRegex)) {
        return day;
    } else if (std::regex_match(value, monthRegex)) {
        return month;
    } else if (std::regex_match(value, numberRegex)) {
        return duration;
    } else {
        return string;
    }
}
