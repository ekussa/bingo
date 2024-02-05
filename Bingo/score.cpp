#include "score.h"

points score::points_full_table = 100;
points score::points_orthogonal_complete = 10;
points score::points_diagonal_complete = 8;
points score::points_orthogonal_show_me_the_money = 4;
points score::points_diagonal_show_me_the_money = 3;

std::vector<std::pair<score_type, points>> score::table_ = {
	{score_type::full_table,	score::points_full_table},
	{score_type::horizontal_complete,	score::points_orthogonal_complete},
	{score_type::horizontal_show_me_the_money,	score::points_orthogonal_show_me_the_money},
	{score_type::vertical_complete,	score::points_orthogonal_complete},
	{score_type::vertical_show_me_the_money,	score::points_orthogonal_show_me_the_money},
	{score_type::top_left_diagonal_complete,	score::points_diagonal_complete},
	{score_type::top_left_diagonal_show_me_the_money,	score::points_diagonal_show_me_the_money},
	{score_type::top_right_diagonal_complete,	score::points_diagonal_complete},
	{score_type::top_right_diagonal_show_me_the_money,	score::points_diagonal_show_me_the_money},
};

points score::calculate(const std::vector<score_type>& scores)
{
	points total{};
	for (auto score : scores) {
		for (auto& table_item : table_) {
			if (table_item.first == score) {
				total += table_item.second;
				break;
			}
		}
	}
	return total;
}
