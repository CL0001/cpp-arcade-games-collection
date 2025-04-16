#include "game.h"

#include <string>

#include "raylib.h"

Game::Game()
{
	InitWindow(1200, 720, "Pong");
	SetTargetFPS(60);

	is_game_running_ = true;

	player_score_ = 0;
	enemy_score_ = 0;

	ball_.Init();
	player_.Init();
	enemy_.Init();
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		if (player_score_ == 3)
		{
			DrawText("You Win!", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 75, 100, GREEN);
			is_game_running_ = false;
		}
			
		if (enemy_score_ == 3)
		{
			DrawText("You Lose!", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 75, 100, RED);
			is_game_running_ = false;
		}

		if (is_game_running_)
		{
			Draw();

			Update();
		}

		EndDrawing();
	}
}

void Game::Draw()
{
	DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);

	DrawText(std::to_string(player_score_).c_str(), GetScreenWidth() / 4, 10, 50, WHITE);
	DrawText(std::to_string(enemy_score_).c_str(), GetScreenWidth() / 4 * 3, 10, 50, WHITE);

	ball_.Draw();
	player_.Draw();
	enemy_.Draw();
}

void Game::Update()
{
	ball_.Update(player_.GetPaddle(), enemy_.GetPaddle(), player_score_, enemy_score_);
	player_.Update();
	enemy_.Update(ball_.GetPosition());
}