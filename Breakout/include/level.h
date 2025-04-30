#pragma once

#include <vector>

#include "raylib.h"

#include "ball.h"
#include "brick.h"

class Level
{
public:
	void Init();

	void Draw();

	bool CheckCollision(Ball& ball);

	void Build();

	void Reset();

private:
	Texture2D tileset_{};
	std::vector<Brick> brick_layout_{96};
};