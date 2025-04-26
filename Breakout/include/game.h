#pragma once

#include "paddle.h"
#include "ball.h"
#include "level.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	void Draw();

	void Update();

private:
	Paddle paddle_;
	Ball ball_;
	Level level_;
};