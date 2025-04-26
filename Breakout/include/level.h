#pragma once

#include <array>

#include "raylib.h"

#include "brick.h"

class Level
{
public:
	void Init();

	void Draw();

	void Update();

private:
	Texture2D tileset_;
	std::array<Brick, 96> brick_layout_;
};