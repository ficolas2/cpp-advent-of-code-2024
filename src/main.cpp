#include "day_01/day_01.h"
#include "day_02/day_02.h"
#include "day_03/day_03.h"
#include "day_04/day_04.h"

#include <cstdlib>
#include <iostream>

void (*const days[])(const char*) = { day_01, day_02, day_03, day_04 };

int main(int argc, char* argv[])
{
    int day;

    if (argc < 2) {
        std::cout << "No day provided" << std::endl;
        return 1;
    } else if (argc < 3) {
        std::cout << "No input file provided" << std::endl;
        return 1;
    }
    day = atoi(argv[1]);

    if (day < 1 || day > 25) {
        std::cout << "Invalid day. Day must be a number between 1 and 25"
                  << std::endl;
        return 1;
    }

    if (static_cast<int>(sizeof(days) / sizeof(*days)) >= day) {
        days[day - 1](argv[2]);
    } else {
        std::cout << "Day not implemented" << std::endl;
        return 1;
    }

    return 0;
}
