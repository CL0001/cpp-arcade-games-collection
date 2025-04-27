#pragma once

#include "raylib.h"

struct Brick
{
	Brick() = default;

	Brick(Rectangle texture_coords, Rectangle game_coords) :
		texture_coords(texture_coords), game_coords(game_coords)
	{
	}

	Rectangle texture_coords;
	Rectangle game_coords;
};