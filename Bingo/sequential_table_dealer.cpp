#include "sequential_table_dealer.h"
#include <numeric>

sequential_table_dealer::sequential_table_dealer(number_t start_number)
{
    std::iota(
        table_.numbers.begin(),
        table_.numbers.end(),
        start_number);
    table_.numbers[max_slots_per_table / 2] = 0;
}

table sequential_table_dealer::shuffle()
{
    return table_;
}
