#include "table_dealer.h"

#include "defs.h"

table table_dealer::shuffle()
{
    table ret;
    std::random_device random_device;
    std::mt19937 mt19937_(random_device());
    std::uniform_int_distribution<> dist(0, max_numbers);
    for (int i = 0; i < max_slots_per_table; ++i) {
        ret.numbers[i] = dist(mt19937_);
    }
    ret.numbers[max_slots_per_table / 2] = 0;
    return ret;
}
