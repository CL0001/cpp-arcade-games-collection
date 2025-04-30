#include "game.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "raylib.h"

Game::Game()
{
	InitWindow(1024, 768, "Breakout");
	SetTargetFPS(60);

	paddle_.Init();
	ball_.Init();
	level_.Init();

	play_again_button_.Init(GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 100, "Retry");
	exit_button_.Init(GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 100, "Exit");

	std::ifstream input("game_stats.txt");
	input >> best_score_;
	input.close();
}

Game::~Game()
{
	CloseWindow();
}

void Game::Run()
{
	while (!WindowShouldClose() && !exit_)
	{
		Draw();
		Update();
	}

	Exit();
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(Color{ 40, 40, 43 });

	paddle_.Draw();
	ball_.Draw();
	level_.Draw();

	DrawStats();

	if (is_game_over_)
	{
		play_again_button_.Draw();
		exit_button_.Draw();
	}

	EndDrawing();
}

void Game::DrawStats()
{
	std::ostringstream ss;

	ss << "Lives: " << std::setw(3) << std::setfill('0') << lives_;
	std::string lives_text = ss.str();
	ss.str("");

	ss << "Score: " << std::setw(3) << std::setfill('0') << current_score_;
	std::string current_score_text = ss.str();
	ss.str("");
	
	ss << "Best: " << std::setw(3) << std::setfill('0') << best_score_;
	std::string best_score_text = ss.str();

	int lives_horizontal_position = 50;
	int current_score_horizontal_position = (GetScreenWidth() / 2) - (MeasureText(current_score_text.c_str(), 50) / 2);
	int best_score_horizontal_position = (GetScreenWidth() / 6 * 5) - (MeasureText(best_score_text.c_str(), 50) / 2);

	DrawText(lives_text.c_str(), lives_horizontal_position, 16, 50, WHITE);
	DrawText(current_score_text.c_str(), current_score_horizontal_position, 16, 50, WHITE);
	DrawText(best_score_text.c_str(), best_score_horizontal_position, 16, 50, WHITE);
}

void Game::Update()
{
	CheckGameOver();

	if (!is_game_over_)
	{
		paddle_.CheckCollision(ball_);

		if (level_.CheckCollision(ball_))
		{
			current_score_++;

			if (current_score_ > best_score_)
				best_score_ = current_score_;
		}

		paddle_.Move();
		ball_.Move();
	}
	else
	{
		if (play_again_button_.IsPressed())
			Restart();

		if (exit_button_.IsPressed())
			Exit();
	}
}

void Game::CheckGameOver()
{
	if (ball_.GetPosition().y + ball_.GetRadius() >= GetScreenHeight())
	{
		if (lives_ == 0)
		{
			is_game_over_ = true;
			return;
		}

		lives_--;
		ball_.Reset();
	}

	if (current_score_ == 96)
		is_game_over_ = true;
}

void Game::Restart()
{
	current_score_ = 0;
	lives_ = 3;
	is_game_over_ = false;

	paddle_.Reset();
	ball_.Reset();
	level_.Reset();
}

void Game::Exit()
{
	std::ofstream output("game_stats.txt");
	output << best_score_;
	output.close();

	exit_ = true;
}