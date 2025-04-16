#pragma once

#include "ball.h"
#include "player.h"
#include "enemy.h"

class Game
{
public:
	Game();
	~Game() = default;

	void Run();

	void Draw();

	void Update();

private:
	bool is_game_running_;

	Ball ball_;
	Player player_;
	Enemy enemy_;

	int player_score_;
	int enemy_score_;
};