#include "game.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "raylib.h"

#include "button.h"
#include "config.h"

Game::Game()
{
	InitWindow(720, 800, "Snake");
	SetTargetFPS(60);

	map_border_ = { 30, 80, 660.0f, 660.0f };

	current_score_ = 0;
	UpdateCurrentScoreText();

	LoadBestScore();

	snake_.Init();
	apple_.Init();
	apple_.Spawn(snake_.GetBody());

	is_game_over_ = false;

	play_again_button_.Init("Play Again");
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BACKGROUND_COLOR);

		if (!is_game_over_)
			Update();

		Draw();

		EndDrawing();
	}
}

void Game::Draw()
{
	DrawRectangleLinesEx(map_border_, 10, ELEMENT_COLOR);

	DrawText(best_score_text_.c_str(), map_border_.x, 30, FONT_SIZE, ELEMENT_COLOR);
	DrawText(current_score_text_.c_str(), map_border_.x + map_border_.width - MeasureText("Score: 000", FONT_SIZE), 30, FONT_SIZE, ELEMENT_COLOR);

	snake_.Draw();
	apple_.Draw();

	if (is_game_over_)
	{
		if (current_score_ != 400)
		{
			const char* msg = "GAME OVER";
			int text_width = MeasureText(msg, 50);
			DrawText(msg, GetScreenWidth() / 2 - text_width / 2, GetScreenHeight() / 2 - 25, 50, RED);
		}
		else
		{
			const char* msg = "YOU WIN!";
			int text_width = MeasureText(msg, 50);
			DrawText(msg, GetScreenWidth() / 2 - text_width / 2, GetScreenHeight() / 2 - 25, 50, ELEMENT_COLOR);
		}

		std::ofstream game_statistics("game_statistics.txt");
		game_statistics << best_score_text_;

		play_again_button_.Draw();

		if (play_again_button_.CheckButtonClicked())
			Restart();
	}
}

void Game::Update()
{
	snake_.Update();

	if (CheckCollisionPointRec(snake_.GetHead(), apple_.GetHitbox()))
	{
		current_score_++;
		snake_.AddBodySegment();
		apple_.Spawn(snake_.GetBody());
	}

	UpdateCurrentScoreText();
	UpdateBestScoreText();

	CheckGameOver();
}

void Game::LoadBestScore()
{
	std::ifstream game_statistics("game_statistics.txt");

	if (game_statistics.is_open())
	{
		std::string line;
		std::getline(game_statistics, line);
		game_statistics.close();

		if (line.rfind("Best: ", 0) == 0)
		{
			std::istringstream iss(line.substr(6));
			int score;
			if (iss >> score)
				best_score_ = score;
			else
				best_score_ = 0;
		}
		else
		{
			best_score_ = 0;
		}
	}
	else
	{
		best_score_ = 0;
	}

	UpdateBestScoreText();
}

void Game::UpdateCurrentScoreText()
{
	std::ostringstream ss;
	ss << "Score: " << std::setw(3) << std::setfill('0') << current_score_;
	current_score_text_ = ss.str();
}

void Game::UpdateBestScoreText()
{
	if (current_score_ > best_score_)
		best_score_ = current_score_;

	std::ostringstream ss;
	ss << "Best: " << std::setw(3) << std::setfill('0') << best_score_;
	best_score_text_ = ss.str();
}

void Game::CheckGameOver()
{
	if (!CheckCollisionPointRec(snake_.GetHead(), map_border_))
		is_game_over_ = true;

	if (snake_.CheckCollisionHeadWithBody())
		is_game_over_ = true;

	if (current_score_ == 400)
		is_game_over_ = true;
}

void Game::Restart()
{
	snake_.Reset();
	current_score_ = 0;
	is_game_over_ = false;
}