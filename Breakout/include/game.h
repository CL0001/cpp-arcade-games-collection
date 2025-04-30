#pragma once

#include "paddle.h"
#include "ball.h"
#include "level.h"
#include "button.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	void Draw();
	void DrawStats();

	void Update();

	void CheckGameOver();
	void Restart();
	void Exit();

private:
	Paddle paddle_;
	Ball ball_;
	Level level_;

	Button play_again_button_;
	Button exit_button_;

	int lives_ = 3;
	int current_score_ = 0;
	int best_score_ = 0;

	bool is_game_over_ = false;
};