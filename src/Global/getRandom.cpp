#include "getRandom.h"
#include <random>
#include <functional>
#include <chrono>

namespace Global
{
    unsigned int getRandom ()
    {
        unsigned int min = 0;
        unsigned int max = std::numeric_limits<unsigned int>::max();

        return getRandom(min, max);
    }

    unsigned int getRandom (unsigned int min, unsigned int max)
    {
        unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<unsigned int> distribution(min, max);
        auto dice = std::bind(distribution, generator);

        return dice() + dice() + dice();
    }
}