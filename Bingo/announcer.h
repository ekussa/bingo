#pragma once

#include "defs.h"
#include "playable.h"
#include "announcer_shuffler.h"

#include <array>

class announcer : public playable
{
	std::array<number_t, max_numbers> sequence_;
	std::array<number_t, max_numbers>::const_iterator next_;

public:
	announcer(announcer_shuffler& announcer_shuffler);

	// Inherited via playable
	void listen(const message& message) override;
	const message announce() override;
};
