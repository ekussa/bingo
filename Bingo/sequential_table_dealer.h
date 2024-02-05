#pragma once
#include "table_dealeable.h"

class sequential_table_dealer : public table_dealable
{
	table table_;

public:
	sequential_table_dealer(number_t start_number);

	table shuffle() override;
};
