#pragma once

#include "announcer_shuffler.h"

class sequential_announcer_shuffler : public announcer_shuffler
{
	std::array<number_t, max_numbers> sequence_;

public:
	sequential_announcer_shuffler(number_t start_number);

	// Inherited via announcer_shuffler
	std::array<number_t, max_numbers> shuffle() override;
};
