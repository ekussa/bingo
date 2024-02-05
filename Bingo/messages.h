#pragma once

#include "types.h"

struct message
{
	type_t type;
	number_t number;

	message() :
		type(type_t::none),
		number(0)
	{
	}

	message(const type_t type) :
		type(type),
		number(0)
	{
	}

	message(const type_t type, const number_t number) :
		type(type),
		number(number)
	{
	}
};
