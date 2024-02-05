#pragma once

#include "playable.h"
#include "table_taker.h"
#include "table.h"
#include "score.h"

class player : public playable, public table_taker
{
	table table_;

public:
	void listen(const message& message) override;
	const message announce() override;

	void take_table(table table) override;

	const std::vector<score_type>& get_score() const;
};
