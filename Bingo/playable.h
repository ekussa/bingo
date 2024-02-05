#pragma once

#include "messages.h"

class playable
{
public:
	virtual void listen(const message& message) = 0;
	virtual const message announce() = 0;
};
