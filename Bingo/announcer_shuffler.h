#pragma once
#include <array>
#include "types.h"
#include "defs.h"

class announcer_shuffler
{
public:
	virtual std::array<number_t, max_numbers> shuffle() = 0;
};
