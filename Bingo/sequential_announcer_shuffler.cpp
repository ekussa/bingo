#include "sequential_announcer_shuffler.h"
#include <numeric>
#include <random>

sequential_announcer_shuffler::sequential_announcer_shuffler(number_t start_number)
{
	std::iota(sequence_.begin(), sequence_.end(), start_number);
	std::shuffle(sequence_.begin(), sequence_.end(), std::mt19937{ std::random_device{}() });
}

std::array<number_t, max_numbers> sequential_announcer_shuffler::shuffle()
{
	return sequence_;
}
