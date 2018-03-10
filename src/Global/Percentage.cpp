#include "Percentage.h"

namespace Global
{

    float Percentage::calculate (float whole, float percentage)
    {
        return percentage / 100 * whole;
    }
}