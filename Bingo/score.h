#pragma once
#include <vector>

#include "score_type.h"

using points = int;

class score
{
	static points points_full_table;
	static points points_orthogonal_complete;
	static points points_diagonal_complete;
	static points points_orthogonal_show_me_the_money;
	static points points_diagonal_show_me_the_money;

	static std::vector<std::pair<score_type, points>> table_;

	std::vector<points> results_;

public:
	static points calculate(const std::vector<score_type>& scores);
};
