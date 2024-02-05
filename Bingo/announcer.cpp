#include "announcer.h"
#include <numeric>
#include <random>

announcer::announcer(announcer_shuffler& announcer_shuffler) :
	sequence_(announcer_shuffler.shuffle()),
	next_(sequence_.cbegin())
{
}

void announcer::listen(const message& message)
{
	switch (message.type)
	{
	case type_t::none:
		break;
	case type_t::bingo:
		break;
	default:
		break;
	}
}

const message announcer::announce()
{
	if (next_ >= sequence_.cend()) {
		return message(type_t::game_over_no_winner);
	}
	return message(
		type_t::number,
		*next_++);
}
