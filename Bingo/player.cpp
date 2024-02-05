#include "player.h"
#include <random>
#include <numeric>

void player::listen(const message& message)
{
    table_.check_if_present(message.number);
}

const message player::announce()
{
    if (table_.has_quorum() && table_.win()) {
        return message(type_t::bingo);
    }

    return message(type_t::none);
}

void player::take_table(table table)
{
    table_ = table;
}

const std::vector<score_type>& player::get_score() const
{
    return table_.scores;
}
