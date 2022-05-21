#include "Position.h"

#include <cassert>

Position::Position(int pos)
{
	if (pos >= 0 && pos <= 63)
		position = pos;
	else
		position = 0;
}
