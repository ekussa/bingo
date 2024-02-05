#pragma once
#include "table_dealeable.h"
#include <random>

class table_dealer : public table_dealable
{
public:
	table shuffle() override;
};
