#pragma once
#include <array>
#include <bitset>
#include <vector>
#include <algorithm>
#include <iterator>

#include "defs.h"
#include "messages.h"
#include "score_type.h"

struct table
{
    std::vector<score_type>
        scores;

	std::array<number_t, max_slots_per_table>
		numbers;

	std::bitset<max_slots_per_table>
		checked;

    table() {
        checked[max_slots_per_table/2] = true;
    }

    bool win() {
        scores = has_full_win();
        if (!scores.empty()) {
            return !scores.empty();
        }

        auto tmp = has_column_win();
        std::copy(tmp.begin(), tmp.end(), std::back_inserter(scores));

        tmp = has_row_win();
        std::copy(tmp.begin(), tmp.end(), std::back_inserter(scores));

        return !scores.empty();
    }

    bool has_quorum() {
        const auto count(checked.count());
        return
            count >= column_size ||
            count >= row_size;
    }

    void check_if_present(number_t number) {
        auto item(
            std::find(
                numbers.cbegin(),
                numbers.cend(),
                number));
        if (item != numbers.cend())
            checked[item - numbers.cbegin()] = true;

    }

private:
    
    std::vector<score_type> has_full_win()
    {
        if (checked.count() == max_numbers_per_table) {
            return { score_type::full_table };
        }
        return {};
    }

    std::vector<score_type> has_row_win()
	{
        std::vector<score_type> ret;
        for (int column = 0; column < column_size; column++) {
            unsigned char hits{};
            const auto offset(column * row_size);
            for (int row = offset; row < offset + row_size; row++) {
                if (checked[row] == true) {
                    hits++;
                }
            }
            if (hits == row_size) {
                ret.emplace_back(score_type::vertical_complete);
            } else if (hits == row_size - 1) {
                ret.emplace_back(score_type::vertical_show_me_the_money);
            }
        }
        return ret;
    }

    std::vector<score_type> has_column_win()
    {
        std::vector<score_type> ret;
        for (int row = 0; row < row_size; row++) {
            unsigned char hits{};
            const auto offset(row * row_size);
            for (int column = offset; column < offset + column_size; column++) {
                if (checked[column] == true) {
                    hits++;
                }
            }
            if (hits == column_size) {
                ret.emplace_back(score_type::horizontal_complete);
            }
            else if (hits == column_size - 1) {
                ret.emplace_back(score_type::horizontal_show_me_the_money);
            }
        }
        return ret;
    }
};
