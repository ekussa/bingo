#include "game_builder.h"
#include <random>

game_builder::game_builder(
    unsigned char players_quantity,
    table_dealable& dealer,
    announcer_shuffler& announcer_shuffler) :
    players_(build_players(players_quantity)),
    announcer_(announcer_shuffler),
    dealer(dealer)
{
    deal_tables_to_all_players();
}

void game_builder::deal_tables_to_all_players()
{
    for (auto& player : players_) {
        player.take_table(dealer.shuffle());
    }
}

void game_builder::deal_tables_to_player(std::vector<player>::iterator player)
{
    player->take_table(dealer.shuffle());
}

std::vector<std::tuple<player*, std::vector<score_type>, points>> game_builder::get_score()
{
    std::vector<std::tuple<player*, std::vector<score_type>, points>> ret;
    for (auto& player : players_) {
        auto score(player.get_score());
        ret.emplace_back(
            &player,
            score,
            score::calculate(score));
    }
    return ret;
}

bool game_builder::is_over(const type_t type) {
    return
        type == type_t::bingo ||
        type == type_t::game_over_no_winner;
}

bool game_builder::round()
{
    auto announcer_msg = announcer_.announce();

    auto game_over(false);
    for (auto& player : players_) {
        player.listen(announcer_msg);
        auto player_msg = player.announce();
        if(is_over(player_msg.type)) {
            game_over = true;
        }
    }

    return game_over;
}

std::vector<player>& game_builder::get_players()
{
    return players_;
}

announcer& game_builder::get_announcer()
{
    return announcer_;
}

std::vector<player> game_builder::build_players(unsigned char quantity)
{
    std::vector<player> ret;
    for (unsigned char i=0; i<quantity; i++) {
        ret.emplace_back();
    }
    return ret;
}
