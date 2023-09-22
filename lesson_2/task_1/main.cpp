#include <iostream>
#include <string>

enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

std::string month_to_string(Month month) {
    switch (month) {
        case Month::January:
            return "January";
        case Month::February:
            return "February";
        case Month::March:
            return "March";
        case Month::April:
            return "April";
        case Month::May:
            return "May";
        case Month::June:
            return "June";
        case Month::July:
            return "July";
        case Month::August:
            return "August";
        case Month::September:
            return "September";
        case Month::October:
            return "October";
        case Month::November:
            return "November";
        case Month::December:
            return "December";
    }
    return "";
}

int main() {
    int number{};

    std::cout << "Enter 0 to exit or\nenter month number: ";
    std::cin >> number;

    while (number != 0) {
        Month month = static_cast<Month>(number);

        //std::cout << static_cast<int>(month) << '\n';

        std::cout << month_to_string(month) << '\n';

        std::cout << "Enter month number: ";
        std::cin >> number;
    }

    std::cout << "Good day, sir!\n";

    return EXIT_SUCCESS;
}
