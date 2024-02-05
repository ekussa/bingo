
#include <iostream>

#include "sequential_table_dealer.h"
#include "game_builder.h"
#include "sequential_announcer_shuffler.h"


int main()
{
    constexpr auto start_number(10);
    constexpr auto player_quantity(3);
    
    sequential_table_dealer sequential_table_dealer(start_number);
    sequential_announcer_shuffler sequential_announcer_shuffler(start_number);
    
    game_builder game_builder(
        player_quantity,
        sequential_table_dealer,
        sequential_announcer_shuffler);

    while (game_builder.round() != true);

    for (auto& score : game_builder.get_score()) {
        for (auto& s : std::get<1>(score)) {
            std::cout << "Types: " << static_cast<unsigned int>(s) << "\n";
        }
        std::cout << "Total: " << std::get<2>(score) << "\n";
    }
}
