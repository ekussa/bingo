#pragma once

constexpr unsigned char max_numbers = 99;
constexpr unsigned char row_size = 5;
constexpr unsigned char column_size = 5;
constexpr unsigned char max_slots_per_table = row_size * column_size;
constexpr unsigned char max_numbers_per_table = max_slots_per_table - 1;
