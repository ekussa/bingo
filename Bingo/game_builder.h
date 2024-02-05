#pragma once

#include <vector>

#include "player.h"
#include "announcer.h"
#include "table_dealeable.h"
#include "score.h"

class game_builder
{
	static std::vector<player> build_players(unsigned char quantity);

	std::vector<player> players_;
	announcer announcer_;

	table_dealable& dealer;

public:
	game_builder(
		unsigned char players_quantity,
		table_dealable& dealer,
		announcer_shuffler& announcer_shuffler
	);

	static bool is_over(const type_t type);

	void deal_tables_to_all_players();
	void deal_tables_to_player(std::vector<player>::iterator player);
	std::vector<std::tuple<player*, std::vector<score_type>, points>> get_score();

	bool round();

	std::vector<player>& get_players();
	announcer& get_announcer();
};
